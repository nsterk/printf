/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_specifier.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:03:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 10:46:15 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

t_tab	*parse_specifier(t_tab *tab)
{
	if (tab->format[tab->i] == 'i')
	{
		tab->specifier = 'i';
		convert_int(tab);
	}
	if (tab->format[tab->i] == 'd')
	{
		tab->specifier = 'd';
		convert_int(tab);
	}
	if (tab->format[tab->i] == 'u')
	{
		tab->specifier = 'u';
		convert_unsigned_int(tab);
	}
	if (tab->format[tab->i] == 'c')
	{
		tab->specifier = 'c';
		convert_char(tab);
	}
	if (tab->format[tab->i] == 's')
	{
		tab->specifier = 's';
		convert_string(tab);
	}
	if (tab->format[tab->i] == 'p')
	{
		tab->specifier = 'p';
		convert_ptr(tab);
	}
	tab->i++;
	format(tab);
	//print_argument(tab);
	return (tab);
}
