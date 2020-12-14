/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 20:21:31 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_tab	*format_string_precision(t_tab *tab)
{
	char	*temp;

	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	tab->argument = ft_calloc(tab->precision + 1, sizeof(*temp));
	if (!tab->argument)
		return (NULL);
	ft_strlcpy(tab->argument, temp, tab->precision + 1);
	free(temp);
	return (tab);
}

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

static t_tab	*format_num_precision(t_tab *tab)
{
	char	*padding_string;
	char	*temp;

	padding_string = make_padding(tab);
	if (!padding_string)
		return (NULL);
	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	if (tab->negative)
		tab->argument = ft_strjoin(padding_string, temp + 1);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	tab->negative = 0;
	free(padding_string);
	free(temp);
	return (tab);
}

t_tab			*format_precision(t_tab *tab)
{
	if (tab->specifier == 's')
	{
		if (tab->precision < (int)ft_strlen(tab->argument))
			return (format_string_precision(tab));
		else
			return (tab);
	}

	if (tab->precision >= (int)ft_strlen(tab->argument))
		format_num_precision(tab);
	return (tab);
}

t_tab	*format_padding(t_tab *tab)
{
	char	*temp;
	char	*padding_string;
	size_t	padding_length;

	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	padding_length = (size_t)tab->width - ft_strlen(temp);
	if (tab->negative && tab->zero)
		padding_length++;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
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
		if (tab->negative)
			tab->argument = ft_strjoin(padding_string, temp + 1);
		else
			tab->argument = ft_strjoin(padding_string, temp);
	}
	free(padding_string);
	return (tab);
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
		else
			format_precision(tab);
	}
	if ((int)ft_strlen(tab->argument) < tab->width && tab->specifier != 'c')
		format_padding(tab);
	print_argument(tab);
	return (tab->ret);
}
