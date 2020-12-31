/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 12:47:09 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/30 17:27:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	char *p;

	p = NULL;
	// ft_printf("|%#.3x|\n", 198);
	// printf("|%#.3x|\n", 198);
	// ft_printf("|%-5.p|\n", p);
	// printf("|%-5.p|\n", p);
	// ft_printf("|%+5.i|\n", 19);
	// printf("|%+5.i|\n", 19);
	ft_printf("|%+5.5i|\n", -19);
	printf("|%+5.5i|\n", -19);
	ft_printf("|%+10.5i|\n", 19);
	printf("|%+10.5i|\n", 19);
	return (0);
}
