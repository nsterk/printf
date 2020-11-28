/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainlietze.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:51:48 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:46:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

// int		main(void)
// {
// 	char *str;

// 	str = "abc";
// 	printf("checking with my printf:\n");
// 	ft_printf("%50s \n", str);
// 	//ft_printf("checking with real printf:\n");
// 	//printf("%u \n", UINT_MAX);
// 	return (0);
// 	}

int		main(void)
{
	printf(FIRST, printf(REAL) - 50);
	ft_printf(FIRST, ft_printf(MINE) - 50);
	return (0);
}
