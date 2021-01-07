/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 12:47:09 by nsterk        #+#    #+#                 */
/*   Updated: 2021/01/07 18:07:28 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int ret1;
	int ret2;
	int		a = 4;
	int		b = 3;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	//int		f = 42;
	//int		g = 25;
	//int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	//char	*n = "abcdefghijklmnop";
	//char	*o = "-a";
	//char	*p = "-12";
	//char	*q = "0";
	//char	*r = "%%";
	//char	*s = "-2147483648";
	//char	*t = "0x12345678";
	//char	*u = "-0";

	ret1 = ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	ret2 = printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	if (ret1 != ret2)
		printf("mine: %i	real: %i\n", ret1, ret2);
	return (0);
}
