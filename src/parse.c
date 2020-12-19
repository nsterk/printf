/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:09:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_width(t_tab *tab)
{
	size_t	i;
	char	*width_string;

	i = 0;
	if (*tab->format == '*')
	{
		tab->format++;
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->left_justify = 1;
			tab->width *= -1;
		}
	}
	else if (ft_isdigit(tab->format[i]))
	{
		while (ft_isdigit(tab->format[i]))
			i++;
		width_string = ft_substr(tab->format, 0, i);
		if (!width_string)
			return (-1);
		tab->width = ft_atoi(width_string);
		free(width_string);
		tab->format += i;
	}
	return (tab->ret);
}

int		get_precision(t_tab *tab)
{
	size_t	i;
	char	*precision_string;

	if (*tab->format == '*')
	{
		tab->precision = va_arg(tab->args, int);
		tab->format++;
		if (tab->precision < 0)
			return (tab->ret);
	}
	else if (ft_isdigit(*tab->format))
	{
		i = 0;
		while (ft_isdigit(tab->format[i]))
			i++;
		precision_string = ft_substr(tab->format, 0, i);
		if (!precision_string)
			return (-1);
		tab->precision = ft_atoi(precision_string);
		free(precision_string);
		tab->format += i;
	}
	if (tab->precision < 0)
		tab->precision = 0;
	tab->precision_bool = 1;
	return (tab->ret);
}

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
		get_width(tab);
	if (*tab->format == '.')
	{
		tab->format++;
		get_precision(tab);
	}
	if (tab->left_justify || tab->precision_bool)
		tab->zero = 0;
	parse_specifier(tab);
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
		if (convert_int(tab) < 0)
			return (-1);
	if (*tab->format == 'u')
		if (convert_unsigned_int(tab) < 0)
			return (-1);
	if (*tab->format == 'c' || *tab->format == '%')
		convert_char(tab);
	if (*tab->format == 's')
		convert_string(tab);
	if (*tab->format == 'p')
		convert_ptr(tab);
	if (*tab->format == 'x' || *tab->format == 'X')
		convert_hex(tab);
	tab->format++;
	format(tab);
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
