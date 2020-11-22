/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:12:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/21 20:55:18 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*parse_flags(t_tab *tab)
{
	tab->i++;
	if (tab->format[tab->i] == '-')
	{
		tab->minus = 1;
		tab->i++;
	}
	if (tab->format[tab->i] == '0')
	{
		tab->zero = 1;
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]))
		get_width(tab);
	parse_specifier(tab);
	return (tab);
}
