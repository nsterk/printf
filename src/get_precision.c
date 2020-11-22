/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 20:28:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 20:39:05 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*get_precision(t_tab *tab)
{
	size_t	end;
	char	*precision_string;

	tab->i++;
	tab->specify_precision = 1;
	if (tab->format[tab->i] == '*')
	{
		tab->precision = va_arg(tab->args, size_t);
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]))
	{
		end = tab->i;
		while (ft_isdigit(tab->format[end]))
			end++;
		precision_string = ft_substr(tab->format, tab->i, end - tab->i);
		tab->precision = ft_atoi(precision_string);
		free(precision_string);
		tab->i = end;
	}
	return (tab);
}
