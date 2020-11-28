/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned_int.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 10:51:11 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 21:13:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*convert_unsigned_int(t_tab *tab)
{
	unsigned int ui;

	ui = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa_base(ui, "0123456789");
	if (!tab->argument)
		return (NULL);
	tab->numerical = 1;
	tab->specifier = 'u';
	return (tab);
}
