/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_specifier.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:03:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 17:46:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*parse_specifier(t_tab *tab)
{
	if (!ft_strchr(tab->conversion_types, *tab->format))
		return (NULL);
	if (*tab->format == 'i' || *tab->format == 'd')
		convert_int(tab);
	if (*tab->format == 'u')
		convert_unsigned_int(tab);
	if (*tab->format == 'c')
		convert_char(tab);
	if (*tab->format == 's')
		convert_string(tab);
	if (*tab->format == 'p')
		convert_ptr(tab);
	if (*tab->format == 'x' || *tab->format == 'X')
		convert_hex(tab);
	tab->format++;
	format(tab);
	return (tab);
}
