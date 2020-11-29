/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:26:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/29 14:55:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

t_tab	*convert_char(t_tab *tab)
{
	int c;

	c = va_arg(tab->args, int);
	if (c == 0 && tab->width < 2)
		tab->ret++;
	tab->argument = ft_calloc(2, sizeof(unsigned char));
	if (!tab->argument)
		return (NULL);
	ft_memset(tab->argument, c, 1);
	tab->specifier = 'c';
	return (tab);
}
