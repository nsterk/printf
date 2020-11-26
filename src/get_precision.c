/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 20:28:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/26 17:20:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*get_precision(t_tab *tab)
{
	size_t	end;
	char	*precision_string;

	tab->i++;
	if (tab->format[tab->i] == '*')
	{
		tab->precision = va_arg(tab->args, int);
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]) && tab->format[tab->i] != '0')
	{
		end = tab->i;
		while (ft_isdigit(tab->format[end]))
			end++;
		precision_string = ft_substr(tab->format, tab->i, end - tab->i);
		tab->precision = ft_atoi(precision_string);
		free(precision_string);
		tab->i = end;
	}
	if (tab->precision > 0)
		tab->zero = 0;
	else
		tab->precision = 0;
	return (tab);
}
