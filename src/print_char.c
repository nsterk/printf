/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 14:49:56 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 16:58:50 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

t_tab	*print_char(t_tab *tab)
{
	ft_putchar_fd(*tab->format, 1);
	tab->ret++;
	tab->format++;
	return (tab);
}
