/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 17:14:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:46:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab		*convert_hex(t_tab *tab)
{
	int		i;

	i = va_arg(tab->args, int);
	if (tab->format[tab->i] == 'x')
	{
		tab->specifier = 'x';
		tab->argument = ft_itoa_base(i, "0123456789abcdef");
	}
	if (tab->format[tab->i] == 'X')
	{
		tab->specifier = 'X';
		tab->argument = ft_itoa_base(i, "0123456789ABCDEF");
	}
	tab->numerical = 1;
	return (tab);
}
