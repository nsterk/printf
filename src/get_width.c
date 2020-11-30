/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_width.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:27:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 17:14:20 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*get_width(t_tab *tab)
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
		return (tab);
	}
	if (ft_isdigit(tab->format[i]))
	{
		while (ft_isdigit(tab->format[i]))
			i++;
		width_string = ft_substr(tab->format, 0, i);
		tab->width = ft_atoi(width_string);
		free(width_string);
		tab->format += i;
	}
	return (tab);
}

/*
t_tab	*get_width(t_tab *tab)
{
	size_t	end;
	char	*width_string;

	if (tab->format[tab->i] == '*')
	{
		tab->width = va_arg(tab->args, size_t);
		if (tab->width < 0)
		{
			tab->minus = 1;
			tab->width *= -1;
		}
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]))
	{
		end = tab->i;
		while (ft_isdigit(tab->format[end]))
			end++;
		width_string = ft_substr(tab->format, tab->i, end - tab->i);
		tab->width = ft_atoi(width_string);
		free(width_string);
		tab->i = end;
	}
	return (tab);
}
*/