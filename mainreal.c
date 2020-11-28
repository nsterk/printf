/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainreal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:45:58 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 13:12:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*str;
	char	*str2;
	int		i;
	int		ret;

	str = "test to the test test";
	str2 = "en nu?";
	i = 10;
	//printf("\e[0;35mnumerical precision is 0\e[0m\n");
	ret = printf("value 0: %u\nvalue -0: %u\n", 0, -0);
	//printf("\e[0;35mstring precision is 0\e[0m\n");
	//printf("string \"abc\"	output: [%.0s]\n", "abc");
	// printf("\nret: %i\n", ret);
	return (0);
}
