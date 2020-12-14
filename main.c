/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 16:42:29 by nsterk        ########   odam.nl         */
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
	i = 1;

	// ret = ft_printf("[%.*i]\n", -50, i);
	// ret2 = printf("[%.*i]\n", -50, i);  
	
	i = 1;
	ret = ft_printf("mine:	[%010i] [%0*i]\n", i, -10, i);
	ret2 = printf("real:	[%010i] [%0*i]\n", i, -10, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect i = 1\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	i = 0;
	ret = ft_printf("mine:	[%.5i] [%.*i] [%.i]\n", i, -5, i, i);
	ret2 = printf("real:	[%.5i] [%.*i] [%.i]\n", i, -5, i, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect i = 0\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);

	ret = ft_printf("mine:	[%.5s] [%.*s] [%.s]\n", str, -5, str, str);
	ret2 = printf("real:	[%.5s] [%.*s] [%.s]\n", str, -5, str, str);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect str\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);

	// ret = ft_printf("%s\n", str);
	// ret2 = printf("%s\n", str);
	// if (ret != ret2)
	// 	printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	return (0);
}