/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainreal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:45:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 11:07:29 by nsterk        ########   odam.nl         */
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
	//printf("[%030.*i]\n", 2, -i);
	printf("[%-.*s]\n", 2, str);
	//printf("[%-.*i]\n", 10, -i);
	//printf("[%*10i]\n", 25, i);
	return (0);
}
