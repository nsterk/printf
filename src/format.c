/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:36:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*make_padding(t_tab *tab)
{
	int		padding_length;
	char	*padding_string;

	padding_length = tab->precision - (int)ft_strlen(tab->argument);
	if (tab->negative)
		padding_length += 2;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length);
	if (tab->negative)
		padding_string[0] = '-';
	return (padding_string);
}

int		format_precision(t_tab *tab)
{
	char	*padding_string;
	char	*temp;

	if (tab->precision < (int)ft_strlen(tab->argument))
		return (tab->ret);
	padding_string = make_padding(tab);
	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp || !padding_string)
		return (-1);
	if (tab->negative)
		tab->argument = ft_strjoin(padding_string, temp + 1);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	tab->negative = 0;
	free(padding_string);
	free(temp);
	return (tab->ret);
}

int		format_padding(t_tab *tab)
{
	char	*temp;
	char	*padding_string;
	size_t	padding_length;

	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (-1);
	padding_length = (size_t)tab->width - ft_strlen(temp);
	if (tab->negative && tab->zero)
		padding_length++;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
	{
		free(temp);
		return (-1);
	}
	if (tab->zero)
	{
		ft_memset(padding_string, '0', padding_length);
		if (tab->negative)
			padding_string[0] = '-';
	}
	else
		ft_memset(padding_string, ' ', padding_length);
	if (tab->left_justify)
		tab->argument = ft_strjoin(temp, padding_string);
	else
	{
		if (tab->negative && tab->zero)
			tab->argument = ft_strjoin(padding_string, temp + 1);
		else
			tab->argument = ft_strjoin(padding_string, temp);
	}
	free(padding_string);
	free(temp);
	return (tab->ret);
}

int			format(t_tab *tab)
{
	if (tab->precision_bool)
	{
		if (!ft_strcmp(tab->argument, "0") && !tab->precision)
		{
			free(tab->argument);
			tab->argument = ft_calloc(1, sizeof(*tab->argument));
		}
		else if (tab->specifier != 's')
			if (format_precision(tab) < 0)
				return (-1);
	}
	if ((int)ft_strlen(tab->argument) < tab->width && tab->specifier != 'c')
		if (format_padding(tab) < 0)
			return (-1);
	print_argument(tab);
	return (tab->ret);
}
