/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 15:05:20 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 16:59:21 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <limits.h>

int		main(void)
{
	char *str;
	int i;
	int ret;

	str = "abcdefg";
	i = -12;
	//ft_printf("[%p]\n", str);
	//ft_printf("[%10.*s]\n", 3, str);
	//ret = ft_printf("hoiii \n[%-*.3s]\n", 10, str);
	str = NULL;
	ret = ft_printf("hoiii \n[%-.3s]\n", str);
	// printf("ret: %i\n", ret);
	// ret = printf("hoiii \n[%-.3s]\n", str);
	// printf("ret: %i\n", ret);
	// ret = ft_printf("[%-*.3i]\n", 15, i);
	// printf("ret: %i\n", ret);
	//ft_printf("[%10.3i]\n", str);
	//ft_printf("[%05i]\n[%05i]", i, -i);
	// ft_printf("[%015i]\n[%15i]\n[%i]\n[%015i]\n[%015i]\n", i, i, i, INT_MIN, INT_MAX);
	//printf("[%010s]\n[%10s]\n", str, str);
	return (0);
}
