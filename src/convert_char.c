/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:26:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:46:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

t_tab	*convert_char(t_tab *tab)
{
	int c;

	c = va_arg(tab->args, int);
	if (c == 0)
		tab->ret++;
	tab->argument = ft_calloc(2, sizeof(char));
	if (!tab->argument)
		return (NULL);
	ft_memset(tab->argument, c, 1);
	tab->specifier = 'c';
	return (tab);
}
