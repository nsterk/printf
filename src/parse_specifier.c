/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_specifier.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:03:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 17:44:19 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

t_tab	*parse_specifier(t_tab *tab)
{
	if (tab->format[tab->i] == 'i' || tab->format[tab->i] == 'd')
		convert_int(tab);
	if (tab->format[tab->i] == 'u')
		convert_unsigned_int(tab);
	if (tab->format[tab->i] == 'c')
		convert_char(tab);
	if (tab->format[tab->i] == 's')
		convert_string(tab);
	if (tab->format[tab->i] == 'p')
		convert_ptr(tab);
	if (tab->format[tab->i] == 'x' || tab->format[tab->i] == 'X')
		convert_hex(tab);
	tab->i++;
	format(tab);
	//print_argument(tab);
	return (tab);
}
