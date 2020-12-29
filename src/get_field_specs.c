/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_field_specs.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 14:12:59 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/28 14:36:00 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	width_from_format(t_tab *tab)
{
	size_t	i;
	char	*width_string;

	i = 0;
	while (ft_isdigit(tab->format[i]))
		i++;
	width_string = ft_substr(tab->format, 0, i);
	if (!width_string)
		return (-1);
	tab->width = ft_atoi(width_string);
	free(width_string);
	tab->format += (i - 1);
	return (tab->ret);
}

int			get_width(t_tab *tab)
{
	if (*tab->format == '*')
	{
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->left_justify = 1;
			tab->width *= -1;
		}
	}
	else if (ft_isdigit(*tab->format))
	{
		if (width_from_format(tab) < 0)
			return (-1);
	}
	return (tab->ret);
}

static int	precision_from_format(t_tab *tab)
{
	char	*precision_string;
	size_t	i;

	i = 0;
	tab->format++;
	while (ft_isdigit(tab->format[i]))
		i++;
	precision_string = ft_substr(tab->format, 0, i);
	if (!precision_string)
		return (-1);
	tab->precision = ft_atoi(precision_string);
	free(precision_string);
	tab->format += (i - 1);
	return (tab->ret);
}

int			get_precision(t_tab *tab)
{
	if (tab->format[1] == '*')
	{
		tab->precision = va_arg(tab->args, int);
		tab->format++;
		if (tab->precision < 0)
			return (tab->ret);
	}
	else if (ft_isdigit(tab->format[1]))
	{
		if (precision_from_format(tab) < 0)
			return (-1);
	}
	if (tab->precision < 0)
		tab->precision = 0;
	tab->precision_bool = 1;
	return (tab->ret);
}
