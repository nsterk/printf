/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 18:13:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*make_precision_padding(t_tab *tab)
{
	int		len;
	char	*padding;

	len = tab->precision - (int)ft_strlen(tab->argument);
	if (tab->hash && ft_strcmp("0", tab->argument))
		len += 4;
	else if (tab->plus)
		len += 2;
	padding = ft_calloc(len + 1, sizeof(*padding));
	if (!padding)
		return (NULL);
	ft_memset(padding, '0', len);
	if (tab->plus)
		padding[0] = tab->argument[0];
	else if (tab->hash && ft_strcmp("0", tab->argument))
		padding[1] = tab->argument[1];
	return (padding);
}

static char		*make_width_padding(t_tab *tab)
{
	int		len;
	char	*padding;

	len = tab->width - (int)ft_strlen(tab->argument);
	if (tab->plus && tab->zero)
		len++;
	if (tab->hash && tab->zero)
		len += 2;
	padding = ft_calloc(len + 1, sizeof(*padding));
	if (!padding)
		return (NULL);
	if (tab->zero)
	{
		ft_memset(padding, '0', len);
		if (tab->plus)
			padding[0] = tab->argument[0];
		else if (tab->space)
			padding[0] = ' ';
		else if (tab->hash)
			padding[1] = tab->argument[1];
	}
	else
		ft_memset(padding, ' ', len);
	return (padding);
}

static int		format_precision(t_tab *tab)
{
	char	*padding;
	char	*temp;

	if (tab->precision < (int)ft_strlen(tab->argument))
		return (tab->ret);
	temp = ft_strdup(tab->argument);
	padding = make_precision_padding(tab);
	free(tab->argument);
	if (!temp || !temp)
		return (-1);
	if (tab->hash)
		tab->argument = ft_strjoin(padding, temp + 2);
	else if (tab->plus)
		tab->argument = ft_strjoin(padding, temp + 1);
	else
		tab->argument = ft_strjoin(padding, temp);
	tab->plus = 0;
	free(padding);
	free(temp);
	if (!tab->argument)
		return (-1);
	return (tab->ret);
}

static int		format_width(t_tab *tab)
{
	char	*temp;
	char	*padding;

	temp = ft_strdup(tab->argument);
	padding = make_width_padding(tab);
	free(tab->argument);
	if (!temp || !padding)
		return (-1);
	if (tab->left_justify)
		tab->argument = ft_strjoin(temp, padding);
	else
	{
		if (tab->plus && tab->zero)
			tab->argument = ft_strjoin(padding, temp + 1);
		else if (tab->hash && tab->zero)
			tab->argument = ft_strjoin(padding, temp + 2);
		else
			tab->argument = ft_strjoin(padding, temp);
	}
	free(padding);
	free(temp);
	if (!tab->argument)
		return (-1);
	return (tab->ret);
}

int				format(t_tab *tab)
{
	if (tab->precision_bool)
	{
		if (!tab->precision)
		{
			if (tab->plus && !ft_strcmp(tab->argument + 1, "0"))
				tab->argument[1] = '\0';
			else if (!ft_strcmp(tab->argument, "0"))
				tab->argument[0] = '\0';
		}
		else
		{
			if (format_precision(tab) < 0)
				return (-1);
		}
	}
	if ((int)ft_strlen(tab->argument) < tab->width && tab->specifier != 'c')
		if (format_width(tab) < 0)
			return (-1);
	print_argument(tab);
	return (tab->ret);
}
