/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 21:08:10 by nsterk        ########   odam.nl         */
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
	i = 123;
	printf("\e[0;35mptr to str\e[0m\n");
	ret = ft_printf("[%p]\n", str);
	ret2 = printf("[%p]\n", str);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	printf("\e[0;35mptr to str, which has been set to NULL\e[0m\n");
	str = NULL;
	ret = ft_printf("[%p]\n", str);
	ret2 = printf("[%p]\n", str);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);

	/*
	
	printf("\e[0;35mptr to str + 1\e[0m\n");
	ret = ft_printf("[%p]\n", str + 1);
	ret2 = printf("[%p]\n", str + 1);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);

	
	*/
	
	return (0);
}