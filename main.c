/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 19:59:02 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int		main(void)
{
	char	*str;
	int		i;
	int		ret;
	int		ret2;

	str = "im the dog who gets beat";
	i = 0;

	// ret = ft_printf("[%.*i]\n", -50, i);
	// ret2 = printf("[%.*i]\n", -50, i);  
	
	i = 0;
	ret = ft_printf("mine:	[%010x] [%0*x]\n", i, -10, i);
	ret2 = printf("real:	[%010x] [%0*x]\n", i, -10, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	// ret = ft_printf("%s\n", str);
	// ret2 = printf("%s\n", str);
	// if (ret != ret2)
	// 	printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	return (0);
}