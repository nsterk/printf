/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_argument.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:29:42 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 16:42:56 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

int		print_argument(t_tab *tab)
{
	ft_putstr_fd(tab->padded_argument, 1);
	tab->ret = tab->ret + (int)ft_strlen(tab->padded_argument);
	free(tab->padded_argument);
	re_initialize(tab);
	if (tab->numerical)
		free(tab->argument);
	return (tab->ret);
}
