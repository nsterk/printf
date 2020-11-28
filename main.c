/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 15:05:20 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 15:09:46 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <limits.h>

int		main(void)
{
	char *str;
	int i;
	int ret;
	int ret2;

	str = "abcdefg";
	i = 636;

	ret = ft_printf("hoiii [%-.0i] %i [%10.0s] pointer: [%p] %x %10.0i\n", 0, 0 + 1, str, str, i, 0);
	ret2 = printf("hoiii [%-.0i] %i [%10.0s] pointer: [%p] %x %10.0i\n", 0, 0 + 1, str, str, i, 0);
	printf("my ret: %i\npf ret: %i\n", ret, ret2);
	ret = printf("[%-*.0i]\n", 10, 0);
	printf("ret: %i\n", ret);
	return (0);
}
