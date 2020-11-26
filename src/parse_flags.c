/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:12:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/26 23:37:46 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*parse_flags(t_tab *tab)
{
	tab->i++;
	while (ft_strchr(tab->flags, tab->format[tab->i]))
	{
		if (tab->format[tab->i] == '-')
		{
			tab->left_justify = 1;
			tab->i++;
		}
		if (tab->format[tab->i] == '0' && !tab->left_justify)
		{
			tab->zero = 1;
			tab->i++;
		}
		if (tab->format[tab->i] == '*' || (ft_isdigit(tab->format[tab->i])
			&& tab->format[tab->i] != '0'))
			get_width(tab);
		if (tab->format[tab->i] == '.')
			get_precision(tab);
	}
	if (tab->left_justify)
		tab->zero = 0;
	parse_specifier(tab);
	return (tab);
}
