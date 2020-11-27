/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 15:05:20 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 02:44:00 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <limits.h>

int		main(void)
{
	char *str;
	int i;

	str = "abcdefg";
	i = -12;
	//ft_printf("[%p]\n", str);
	//ft_printf("[%10.*s]\n", 3, str);
	ft_printf("[%-*.3s]\n", 10, str);
	//ft_printf("[%10.3i]\n", str);
	//ft_printf("[%05i]\n[%05i]", i, -i);
	// ft_printf("[%015i]\n[%15i]\n[%i]\n[%015i]\n[%015i]\n", i, i, i, INT_MIN, INT_MAX);
	//printf("[%010s]\n[%10s]\n", str, str);
	return (0);
}
