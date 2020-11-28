/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned_int.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 10:51:11 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:46:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*convert_unsigned_int(t_tab *tab)
{
	long u;

	u = va_arg(tab->args, long);
	tab->argument = ft_itoa_base(u, "0123456789");
	if (!tab->argument)
		return (NULL);
	tab->numerical = 1;
	tab->specifier = 'u';
	return (tab);
}
