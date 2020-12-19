/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:03:50 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	//char	*str;
	int		i;
	int		ret;
	// int		ret2;
	// str = "im the dog who gets beat";
	i = 1;
	i = 0;
	ret = ft_printf("[%.0d]\n", i);
	// ft_printf("mine:	[%10.5s]\n", str);
	// printf("real:	[%10.5s]\n", str);
	// ft_printf("mine:	[%10.5i]\n", i);
	// printf("real:	[%10.5i]\n", i);
	return (0);
}