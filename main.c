/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/29 13:15:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int		main(void)
{
	char	*str;
	int		i;
	int		ret;
	//int		ret2;

	str = "im the dog who gets beat";
	i = 8432;

	ret = ft_printf("[%c]", 0);
	printf("\nret my printf: %i\n", ret);
	ret = printf("[%c]", 0);
	printf("\nret real printf: %i\n", ret);
	ret = printf("%c", 1);
	printf("\nret real printf alleen char: %i\n", ret);
	// ret = ft_printf("[%0.10i] [%0.*i]\n", i, -10, i);
	// ret2 = printf("[%0.10i] [%0.*i]\n", i, -10, i);
	// if (ret != ret2)
	// 	printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	return (0);
}