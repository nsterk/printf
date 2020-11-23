/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainreal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:45:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 21:05:41 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*str;
	char	*str2;
	char	i;

	str = "test to the test test";
	str2 = "en nu?";
	i = 123;
	// printf("\e[4;3mwidth & precision specified:\e[0m\n");
	// printf("\e[0;35mpositive field width argument:\e[0m [%*.*i]\n", 10, 5, i);
	// printf("\e[0;36mnegative field width argument:\e[0m [%*.*i]\n", -10, 5, i);
	// printf("\e[4;3monly width specified:\e[0m\n");
	// printf("positive field width: [%*i]\n", 10, i);
	// printf("negative field width: [%*i]\n", -10, i);
	// printf("\e[4;3monly precision specified:\e[0m\n");
	// printf("positive precision: [%.*i]\n", 10, i);
	// printf("negative precision: [%.*i]\n", -10, i);
	// printf("\e[4;3mwidth & precision specified:\e[0m\n");
	// printf("\e[0;35mpositive precision argument:\e[0m [%*.*i]\n", 10, 5, i);
	// printf("\e[0;36mnegative precision argument:\e[0m [%*.*i]\n", 10, -5, i);

	// printf("\e[0;35mwidth & precision, same sign:\e[0m\n");
	// printf("positive width, positive precision: [%*.*i]\n", -10, -5, i);
	// printf("negative width, negative precision: [%*.*i]\n", -10, -5, i);
	// printf("\e[0;35mwidth & precision, different signs:\e[0m\n");
	// printf("positive width, negative precision: [%*.*i]\n", 10, -5, i);
	// printf("negative width, positive precision: [%*.*i]\n", -10, 5, i);

	printf("negative width: [%0*i]\n", -10, i);

	//printf("[%-.*s]\n", 2, str);
	//printf("[%-.*i]\n", 10, -i);
	//printf("[%*10i]\n", 25, i);
	return (0);
}
