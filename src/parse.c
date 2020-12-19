/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:38:21 by nsterk        ########   odam.nl         */
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
