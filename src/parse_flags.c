/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:12:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 21:18:43 by nsterk        ########   odam.nl         */
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
	if (tab->format[tab->i] == '0' && !tab->minus)
	{
		tab->zero = 1;
		tab->i++;
	}
	if ((tab->format[tab->i] == '*' || ft_isdigit(tab->format[tab->i]))
		&& tab->format[tab->i] != '0')
		get_width(tab);
	if (tab->format[tab->i] == '.')
		get_precision(tab);
	parse_specifier(tab);
	return (tab);
}
