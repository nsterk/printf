/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_argument.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:29:42 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 14:43:51 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

int		print_argument(t_tab *tab)
{
	ft_putstr_fd(tab->argument, 1);
	tab->ret += (int)ft_strlen(tab->argument);
	free(tab->argument);
	re_initialize(tab);
	return (tab->ret);
}
