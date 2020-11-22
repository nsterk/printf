/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:29:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/21 18:05:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

t_tab	*convert_ptr(t_tab *tab)
{
	char	*str;
	int		address;

	address = va_arg(tab->args, int);
	tab->numerical = 1;
	printf("[%i]\n", address);
	printf("?????");
	str = ft_itoa(address);
	return (tab);
}
