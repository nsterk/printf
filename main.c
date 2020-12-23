/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/23 15:53:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	char	*str;
	int		i;
	// int		ret1;
	// int		ret2;

	str = "im the dog who gets beat";
	i = 0;
	// ret1 = printf("[%0+5i][%0 5i] [%+5i]\n", i, i, -i);
	// ret2 = ft_printf("[%0+5i][%0 5i] [%+5i]\n", i, i, -i);
	// printf("\nprintf ret: %i	my ret: %i\n", ret1, ret2);
	// ft_printf("%.x %.X\n%.i %.d\n", -i, -i, i, i);
	// printf("%.x %.X\n%.i %.d\n", -i, -i, i, i);
	// str = "0";
	// printf("[%.s]\n", str);
	ft_printf("%3.s\n", str);
	return (0);
}
