/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 19:05:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			parse_flags(t_tab *tab)
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
	return (tab->ret);
}

static void			find_len_modifier(t_tab *tab)
{
	if (*tab->format == 'h')
	{
		if (tab->format[1] == 'h')
		{
			tab->lenmod = 1;
			tab->format++;
		}
		else
			tab->lenmod = 2;
		tab->format++;
	}
	else if (*tab->format == 'l')
	{
		if (tab->format[1] == 'l')
		{
			tab->lenmod = 3;
			tab->format++;
		}
		else
			tab->lenmod = 4;
		tab->format++;
	}
}

static t_convert	convert_argument(char specifier)
{
	static const t_convert convert[255] = {
		['i'] = &convert_int,
		['d'] = &convert_int,
		['u'] = &convert_unsigned_int,
		['c'] = &convert_char,
		['%'] = &convert_char,
		['s'] = &convert_string,
		['p'] = &convert_ptr,
		['x'] = &convert_lowhex,
		['X'] = &convert_uphex,
	};

	return (convert[(unsigned int)specifier]);
}

int					conversion_type(t_tab *tab)
{
	t_convert	convert;

	find_len_modifier(tab);
	if (ft_strchr("%cspdiuxX", *tab->format))
	{
		if (tab->left_justify || tab->precision_bool)
			tab->zero = 0;
		if (tab->plus)
			tab->space = 0;
		convert = convert_argument(*tab->format);
		if (convert(tab) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

int					parse(t_tab *tab)
{
	int		c_check;

	if (*tab->format == '%')
		return (print_char(tab));
	while (*tab->format)
	{
		c_check = conversion_type(tab);
		if (c_check < 0)
			return (-1);
		else if (c_check > 0)
			return (format(tab));
		if (parse_flags(tab) < 0)
			return (-1);
		tab->format++;
	}
	return (tab->ret);
}
