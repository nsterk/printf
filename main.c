/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 15:05:20 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 10:57:29 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <limits.h>

int		main(void)
{
	char *str;
	int i;

	str = "xxx";
	i = -123;
	//ft_printf("[%p]\n", str);
	ft_printf("[%-.20i]\n", i);
	//ft_printf("[%05i]\n[%05i]", i, -i);
	// ft_printf("[%015i]\n[%15i]\n[%i]\n[%015i]\n[%015i]\n", i, i, i, INT_MIN, INT_MAX);
	//printf("[%010s]\n[%10s]\n", str, str);
	return (0);
}
