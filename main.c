/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:20:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 14:49:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	ft_printf("%#05x", 43);
	return (0);
}
