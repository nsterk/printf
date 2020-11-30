/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 17:14:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 19:54:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab		*convert_hex(t_tab *tab)
{
	unsigned int	ui;
	//printf("w to the idth %i\n", tab->width);
	ui = va_arg(tab->args, unsigned int);
	if (*tab->format == 'x')
	{
		tab->specifier = 'x';
		tab->argument = ft_unsigned_itoa_base(ui, "0123456789abcdef");
	}
	if (*tab->format == 'X')
	{
		tab->specifier = 'X';
		tab->argument = ft_unsigned_itoa_base(ui, "0123456789ABCDEF");
	}
	tab->numerical = 1;
	return (tab);
}
