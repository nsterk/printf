/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 12:47:45 by nsterk        ########   odam.nl         */
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
	int		ret;
	// int		ret2;
	str = "im the dog who gets beat";
	i = 1;
	i = -20;
	ret = ft_printf("[%.5i]\n", i);
	ret = ft_printf("[%10.5s]\n", str);
	printf("[%10.5s]\n", str);
	return (0);
}