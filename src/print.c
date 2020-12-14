/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:13:36 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 13:13:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		print_argument(t_tab *tab)
{
	if (!tab->skip)
	{
		ft_putstr_fd(tab->argument, 1);
		tab->ret += (int)ft_strlen(tab->argument);
	}
	free(tab->argument);
	re_initialize(tab);
	return (tab->ret);
}

t_tab	*print_char(t_tab *tab)
{
	//write(1, &tab->format, 1);
	ft_putchar_fd(*tab->format, 1);
	tab->ret++;
	tab->format++;
	return (tab);
}
