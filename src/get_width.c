/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_width.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:27:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 20:23:27 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*get_width(t_tab *tab)
{
	size_t	end;
	char	*width_string;

	if (tab->format[tab->i] == '*')
	{
		tab->width = va_arg(tab->args, size_t);
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
