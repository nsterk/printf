/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned_int.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 10:51:11 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/21 18:06:12 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert_unsigned_int(t_tab *tab)
{
	unsigned int	u;

	u = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa(u);
	tab->numerical = 1;
	return (tab);
}
