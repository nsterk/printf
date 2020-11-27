/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 20:28:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 01:38:59 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*get_precision(t_tab *tab)
{
	size_t	i;
	char	*precision_string;

	if (*tab->format == '*')
	{
		tab->precision = va_arg(tab->args, int);
		tab->format++;
	}
	if (ft_isdigit(*tab->format) && *tab->format != '0')
	{
		i = 0;
		while (ft_isdigit(tab->format[i]))
			i++;
		precision_string = ft_substr(tab->format, 0, i);
		tab->precision = ft_atoi(precision_string);
		free(precision_string);
		tab->format += i;
	}
	if (tab->precision < 0)
		tab->precision = 0;
	return (tab);
}
