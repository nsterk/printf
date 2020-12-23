/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainreal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:45:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/20 15:58:42 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	char	*str;
	char	*str2;
	int		i;
	//int		ret;

	str = "test to the test test";
	str2 = "en nu?";
	i = 200;
	//printf("\e[0;35mnumerical precision is 0\e[0m\n");
	//ret = ft_printf("[%.0d]", 0);
	printf("[%+5i] [%i]\n", i, -i);
	printf("[%.i] [%i]\n", i, -i);
	// ret = printf("[%c]", 0);
	// printf("\nret: %i\n", ret);
	//printf("\e[0;35mstring precision is 0\e[0m\n");
	//printf("string \"abc\"	output: [%.0s]\n", "abc");
	// printf("\nret: %i\n", ret);
	return (0);
}
