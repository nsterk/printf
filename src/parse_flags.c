/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:12:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 00:35:18 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*parse_flags(t_tab *tab)
{
	tab->format++;
	while (ft_strchr(tab->flags, *tab->format))
	{
		if (*tab->format == '-')
		{
			tab->left_justify = 1;
			tab->format++;
		}
		if (*tab->format == '0' && !tab->left_justify)
		{
			tab->zero = 1;
			tab->format++;
		}
		if (*tab->format == '*' || (ft_isdigit(*tab->format)
			&& *tab->format != '0'))
			get_width(tab);
		if (*tab->format == '.')
		{
			tab->format++;
			get_precision(tab);
		}
	}
	if (tab->left_justify || tab->precision)
		tab->zero = 0;
	parse_specifier(tab);
	return (tab);
}
