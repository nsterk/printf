/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_numerical.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:37:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 16:12:15 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_tab	*format_precision(t_tab *tab)
{
	return (tab);
}

static t_tab	*pad_whitespace(t_tab *tab)
{
	char	*padding_string;
	size_t	padding_length;

	padding_length = tab->width - ft_strlen(tab->argument);
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, ' ', padding_length);
	if (tab->minus)
		tab->padded_argument = ft_strjoin(tab->argument, padding_string);
	else
		tab->padded_argument = ft_strjoin(padding_string, tab->argument);
	return (tab);
}

static t_tab	*pad_zero(t_tab *tab)
{
	char	*padding_string;
	size_t	padding_length;

	padding_length = tab->width - ft_strlen(tab->argument);
	if (tab->negative)
	{
		padding_length++;
		tab->argument++;
	}
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length);
	if (tab->negative)
		padding_string[0] = '-';
	padding_string[padding_length] = '\0';
	return (tab);
}

static t_tab	*format_width(t_tab *tab)
{
	char	*padding_string;
	size_t	padding_length;

	padding_length = tab->width - ft_strlen(tab->argument);
	if (tab->zero && !tab->minus && tab->negative)
	{
		padding_length++;
		tab->argument++;
	}
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	if (tab->zero && !tab->minus)
	{
		ft_memset(padding_string, '0', padding_length);
		if (tab->negative)
			padding_string[0] = '-';
	}
	else
		ft_memset(padding_string, ' ', padding_length);
	padding_string[padding_length] = '\0';
	if (tab->minus)
		tab->padded_argument = ft_strjoin(tab->argument, padding_string);
	else
		tab->padded_argument = ft_strjoin(padding_string, tab->argument);
	free(padding_string);
	return (tab);
}

t_tab	*format_numerical(t_tab *tab)
{
	if (tab->minus)
		tab->zero = 0;
	if (tab->precision)
		format_precision(tab);
	if (tab->width && ft_strlen(tab->argument) < tab->width)
		format_width(tab);
	
	// if (!tab->precision && !tab->width ||
	// 	!tab->precision && tab->width < ft_strlen(tab->argument))
	// 	tab->padded_argument = ft_strdup(tab->argument);
	return (tab);
}
