/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/21 14:03:14 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	parse_flags(t_tab *tab)
{
	if (*tab->format == '-')
		tab->left_justify = 1;
	else if (*tab->format == '0')
		tab->zero = 1;
	else if (*tab->format == ' ')
		tab->space = 1;
	else if (*tab->format == '+')
		tab->plus = 1;
	else if (*tab->format == '#')
		tab->hash = 1;
	else if (*tab->format == '*' || (ft_isdigit(*tab->format)
		&& *tab->format != '0'))
		return (get_width(tab));
	else if (*tab->format == '.')
		return (get_precision(tab));
	//tab->format++;
	return (tab->ret);
}

static void	handle_flags(t_tab *tab)
{
	if (tab->left_justify || tab->precision_bool)
		tab->zero = 0;
	if (tab->plus)
		tab->space = 0;
}

int		conversion_type(t_tab *tab)
{
	if (ft_strchr(tab->conversion_types, *tab->format))
	{
		handle_flags(tab);
		if (*tab->format == 'i' || *tab->format == 'd')
			return (convert_int(tab));
		else if (*tab->format == 'u')
			return (convert_unsigned_int(tab));
		else if (*tab->format == 'c' || *tab->format == '%')
			return (convert_char(tab));
		else if (*tab->format == 's')
			return (convert_string(tab));
		else if (*tab->format == 'p')
			return (convert_ptr(tab));
		else if (*tab->format == 'x')
			return (convert_lowhex(tab));
		else if (*tab->format == 'X')
			return (convert_uphex(tab));
	}
	return (0);
}

int		parse(t_tab *tab)
{
	int		c_check;

	if (*tab->format == '%')
		return (print_char(tab));
	while (*tab->format)
	{
		c_check = conversion_type(tab);
		if (c_check)
		{
			if (c_check < 0)
				return (-1);
			else
				return (format(tab));
		}
		if ((c_check = parse_flags(tab)) < 0)
			return (-1);
		tab->format++;
	}
	return (tab->ret);
}
