/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 14:13:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_zero_minus(t_tab *tab)
{
	if (*tab->format == '-' || *tab->format == '0')
	{
		if (*tab->format == '-')
			tab->left_justify = 1;
		else
			tab->zero = 1;
		tab->format++;
	}
	if (*tab->format == '-')
	{
		tab->left_justify = 1;
		tab->format++;
	}
	if (*tab->format == '0')
	{
		tab->zero = 1;
		tab->format++;
	}
}

int		parse_flags(t_tab *tab)
{
	if (*tab->format == '%')
		return (print_char(tab));
	parse_zero_minus(tab);
	if (*tab->format == '*' || (ft_isdigit(*tab->format)
		&& *tab->format != '0'))
		if (get_width(tab) < 0)
			return (-1);
	if (*tab->format == '.')
	{
		tab->format++;
		if (get_precision(tab) < 0)
			return (-1);
	}
	if (tab->left_justify || tab->precision_bool)
		tab->zero = 0;
	if (parse_specifier(tab) < 0)
		return (-1);
	tab->format++;
	if (format(tab) < 0)
		return (-1);
	return (tab->ret);
}

int		parse_specifier(t_tab *tab)
{
	if (!ft_strchr(tab->conversion_types, *tab->format))
	{
		tab->format++;
		return (tab->ret);
	}
	if (*tab->format == 'i' || *tab->format == 'd')
		return (convert_int(tab));
	if (*tab->format == 'u')
		return (convert_unsigned_int(tab));
	if (*tab->format == 'c' || *tab->format == '%')
		return (convert_char(tab));
	if (*tab->format == 's')
		return (convert_string(tab));
	if (*tab->format == 'p')
		return (convert_ptr(tab));
	if (*tab->format == 'x' || *tab->format == 'X')
		return (convert_hex(tab));
	return (tab->ret);
}

int		parse(t_tab *tab)
{
	while (*tab->format)
	{
		if (*tab->format == '%')
		{
			tab->format++;
			if (parse_flags(tab) < 0)
				return (-1);
		}
		else
			tab->ret = print_char(tab);
	}
	return (tab->ret);
}
