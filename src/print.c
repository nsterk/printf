/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:13:36 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 18:18:01 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

static void		print_argument_char(t_tab *tab)
{
	int i;

	i = 1;
	if (tab->left_justify)
	{
		write(1, tab->argument, 1);
		while (i < tab->width)
		{
			write(1, &" ", 1);
			i++;
		}
	}
	else
	{
		while (i < tab->width)
		{
			write(1, &" ", 1);
			i++;
		}
		write(1, tab->argument, 1);
	}
	tab->ret += i;
}

int				print_argument(t_tab *tab)
{
	if (tab->specifier == 'c')
	{
		if (tab->width > 1)
			print_argument_char(tab);
		else
		{
			write(1, tab->argument, 1);
			tab->ret++;
		}
	}
	else
	{
		ft_putstr_fd(tab->argument, 1);
		tab->ret += (int)ft_strlen(tab->argument);
	}
	if (tab->argument)
		free(tab->argument);
	re_initialize(tab);
	return (tab->ret);
}

int				print_char(t_tab *tab)
{
	write(1, tab->format, 1);
	tab->ret++;
	tab->format++;
	return (tab->ret);
}
