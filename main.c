/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 12:47:09 by nsterk        #+#    #+#                 */
/*   Updated: 2021/01/11 18:05:12 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int ret1;
	int ret2;

	// ret1 = ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	// ret2 = printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	// if (ret1 != ret2)
	// 	printf("mine: %i	real: %i\n", ret1, ret2);

	int a = 15;
	//int b = 25;

	ret1 = ft_printf("%-*p%-*x%-*p%-*x%-*p%-*x%-*p%-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	ret2 = printf("%-*p%-*x%-*p%-*x%-*p%-*x%-*p%-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	if (ret1 != ret2)
		printf("mine: %i	real: %i\n", ret1, ret2);
	ft_printf("\n%-*p%-*x%-*p%-*x\n", a, (void *)20959160, a, 1, a, NULL, a, 0);
	return (0);
}
