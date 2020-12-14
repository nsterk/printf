/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 19:28:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <unistd.h>

int		main(void)
{
	char	*str;
	int		i;
	int		ret;
	int		ret2;

	str = "im the dog who gets beat";
	i = 1;
	printf("\e[0;35mfield width = 5, left-justify & regular\e[0m\n");
	printf("\e[3;37mmet c == 'a'\e[0m\n");
	ret = ft_printf("mine:	[%-5c] [%5c]\n", 'a', 'a');
	ret2 = printf("real:	[%-5c] [%5c]\n", 'a', 'a');
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect i = 1\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	printf("\e[3;37mmet c == 0\e[0m\n");
	ret = ft_printf("mine:	[%-5c] [%5c]\n", 0, 0);
	ret2 = printf("real:	[%-5c] [%5c]\n", 0, 0);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect i = 1\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	return (0);
}