/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainreal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:45:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/21 20:40:41 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*str;
	char	*str2;
	char	i;

	str = "testie test";
	str2 = "en nu?";
	i = 25;
	printf("[%-10i]\n[%-*i]\n", i, 10, i);
	return (0);
}
