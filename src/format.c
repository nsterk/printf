/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 14:53:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*make_precision_padding(t_tab *tab)
{
	int		len;
	char	*padding_string;

	len = tab->precision - (int)ft_strlen(tab->argument);
	if (tab->hash && ft_strcmp("0", tab->argument))
		len += 4;
	else if (tab->plus)
		len += 2;
	padding_string = ft_calloc(len + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', len);
	if (tab->plus)
		padding_string[0] = tab->argument[0];
	else if (tab->hash && ft_strcmp("0", tab->argument))
		padding_string[1] = tab->argument[1];
	return (padding_string);
}

static char		*make_width_padding(t_tab *tab)
{
	int		len;
	char	*padding_string;

	len = tab->width - (int)ft_strlen(tab->argument);
	if (tab->plus && tab->zero)
		len++;
	if (tab->hash && tab->zero)
		len += 2;
	padding_string = ft_calloc(len + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	if (tab->zero)
	{
		ft_memset(padding_string, '0', len);
		if (tab->plus)
			padding_string[0] = tab->argument[0];
		else if (tab->space)
			padding_string[0] = ' ';
		else if (tab->hash)
			padding_string[1] = tab->argument[1];
	}
	else
		ft_memset(padding_string, ' ', len);
	return (padding_string);
}

int				format_precision(t_tab *tab)
{
	char	*padding_string;
	char	*temp;

	if (tab->precision < (int)ft_strlen(tab->argument))
		return (tab->ret);
	padding_string = make_precision_padding(tab);
	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp || !padding_string)
		return (-1);
	if (tab->hash)
		tab->argument = ft_strjoin(padding_string, temp + 2);
	else if (tab->plus)
		tab->argument = ft_strjoin(padding_string, temp + 1);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	tab->plus = 0;
	free(padding_string);
	free(temp);
	if (!tab->argument)
		return (-1);
	return (tab->ret);
}

int				format_width(t_tab *tab)
{
	char	*temp;
	char	*padding_string;

	padding_string = make_width_padding(tab);
	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (-1);
	if (tab->left_justify)
		tab->argument = ft_strjoin(temp, padding_string);
	else
	{
		if (tab->plus && tab->zero)
			tab->argument = ft_strjoin(padding_string, temp + 1);
		else if (tab->hash && tab->zero)
			tab->argument = ft_strjoin(padding_string, temp + 2);
		else
			tab->argument = ft_strjoin(padding_string, temp);
	}
	free(padding_string);
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
			{
				free(tab->argument);
				tab->argument = ft_calloc(1, sizeof(*tab->argument));
			}
		}
		else if (tab->specifier != 's')
			if (format_precision(tab) < 0)
				return (-1);
	}
	if ((int)ft_strlen(tab->argument) < tab->width && tab->specifier != 'c')
		if (format_width(tab) < 0)
			return (-1);
	print_argument(tab);
	return (tab->ret);
}
