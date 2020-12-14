/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hugemain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 15:05:20 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 19:19:17 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int		main(void)
{
	char *str;
	int i;
	int ret;
	int ret2;

	str = "i'm the dog who gets beat";

	/* INTEGERS ONLY */
	/* NO FLAGS */
	printf("\e[0;33mno flags\e[0m\n");
	i = 99;
	ret = ft_printf("start nice and easy: %i\n", i);
	ret2 = printf("start nice and easy: %i\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// -i
	ret = ft_printf("%i\n", -i);
	ret2 = printf("%i\n", -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	i = 0;
	ret = ft_printf("%i\n", i);
	ret2 = printf("%i\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);	
	// i = max int
	ret = ft_printf("%i\n", INT_MAX);
	ret2 = printf("%i\n", INT_MAX);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = min int
	ret = ft_printf("%i\n", INT_MIN);
	ret2 = printf("%i\n", INT_MIN);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = max int + 1
	ret = ft_printf("%i\n", INT_MAX + 1);
	ret2 = printf("%i\n", INT_MAX + 1);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* ONLY 0 FLAG */
	printf("\e[0;33monly 0 flag\e[0m\n");
	// i = 99
	i = 99;
	ret = ft_printf("%0i\n", i);
	ret2 = printf("%0i\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// -i
	ret = ft_printf("%0i\n", -i);
	ret2 = printf("%0i\n", -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	i = 0;
	ret = ft_printf("%0i\n", i);
	ret2 = printf("%0i\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* ONLY - FLAG */
	printf("\e[0;33monly - flag\e[0m\n");
	// i = 99
	i = 99;
	ret = ft_printf("%-i\n", i);
	ret2 = printf("%-i\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = -i
	ret = ft_printf("%-i\n", -i);
	ret2 = printf("%-i\n", -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* ONLY WIDTH SPECIFIED */
	printf("\e[0;33monly width specified\e[0m\n");
	// i = 99
	// width = 10
	i = 99;
	printf("\e[0;35mwidth = 10\e[0m\n");
	ret = ft_printf("[%10i]\n", i);
	ret2 = printf("[%10i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = -10
	printf("\e[0;35mwidth = -10\e[0m\n");
	ret = ft_printf("[%*i]\n", -10, i);
	ret2 = printf("[%*i]\n", -10, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 3
	printf("\e[0;35mwidth = 3\e[0m\n");
	ret = ft_printf("[%3i]\n", i);
	ret2 = printf("[%3i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 2
	printf("\e[0;35mwidth = 2\e[0m\n");
	ret = ft_printf("[%2i]\n", i);
	ret2 = printf("[%2i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%*i]\n", 0, i);
	ret2 = printf("[%*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	// width = 0
	i = 0;
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%*i]\n", 0, i);
	ret2 = printf("[%*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* 0 ICM WIDTH */
	printf("\e[0;33m0 and width specified\e[0m\n");
	// i = 99
	// width = 5
	i = 99;
	ret = ft_printf("[%05i]\n", i);
	ret2 = printf("[%05i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 1
	i = 99;
	ret = ft_printf("[%01i]\n", i);
	ret2 = printf("[%01i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* 0 ICM *WIDTH */
	printf("\e[0;33m0 and *width\e[0m\n");
	// i = 99
	// width = 5
	i = 99;
	printf("\e[0;35mwidth = 5\e[0m\n");
	ret = ft_printf("[%0*i]\n", 5, i);
	ret2 = printf("[%0*i]\n", 5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = -5
	printf("\e[0;35mwidth = -5\e[0m\n");
	ret = ft_printf("[%0*i]\n", -5, i);
	ret2 = printf("[%0*i]\n", -5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%0*i]\n", 0, i);
	ret2 = printf("[%0*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	printf("\e[0;36mi = 0\e[0m\n");
	// width = 5
	printf("\e[0;35mwidth = 5\e[0m\n");
	i = 0;
	ret = ft_printf("[%0*i]\n", 5, i);
	ret2 = printf("[%0*i]\n", 5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%0*i]\n", 0, i);
	ret2 = printf("[%0*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	/* - ICM WIDTH */
	printf("\e[0;33m- and width specified\e[0m\n");
	// i = 99
	// width = 5
	i = 99;
	ret = ft_printf("[%-5i]\n", i);
	ret2 = printf("[%-5i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 1
	i = 99;
	ret = ft_printf("[%-1i]\n", i);
	ret2 = printf("[%-1i]\n", i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	/* - ICM *WIDTH */
	printf("\e[0;33m- and *width\e[0m\n");
	// i = 99
	// width = 5
	i = 99;
	printf("\e[0;35mwidth = 5\e[0m\n");
	ret = ft_printf("[%-*i]\n", 5, i);
	ret2 = printf("[%-*i]\n", 5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%-*i]\n", 0, i);
	ret2 = printf("[%-*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	printf("\e[0;36mi = 0\e[0m\n");
	// width = 5
	printf("\e[0;35mwidth = 5\e[0m\n");
	i = 0;
	ret = ft_printf("[%-*i]\n", 5, i);
	ret2 = printf("[%-*i]\n", 5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%-*i]\n", 0, i);
	ret2 = printf("[%-*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = -5
	printf("\e[0;35mwidth = -5\e[0m\n");
	ret = ft_printf("[%-*i]\n", -5, i);
	ret2 = printf("[%-*i]\n", -5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = -99
	i = -99;
	printf("\e[0;36mi = -99\e[0m\n");
	// width = 5
	printf("\e[0;35mwidth = 5\e[0m\n");
	ret = ft_printf("[%-*i]\n", 5, i);
	ret2 = printf("[%-*i]\n", 5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = 0
	printf("\e[0;35mwidth = 0\e[0m\n");
	ret = ft_printf("[%-*i]\n", 0, i);
	ret2 = printf("[%-*i]\n", 0, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// width = -5
	printf("\e[0;35mwidth = -5\e[0m\n");
	ret = ft_printf("[%-*i]\n", -5, i);
	ret2 = printf("[%-*i]\n", -5, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	
	/* ONLY HEX CONVERSION */
	// i = 8432
	printf("\e[0;33monly hex conversion\e[0m\n");
	printf("\e[0;36mi = 8432\e[0m\n");
	i = 8432;
	ret = ft_printf("[%x] [%X] [%x] [%X]\n", i, i, -i, -i);
	ret2 = printf("[%x] [%X] [%x] [%X]\n", i, i, -i, -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
		printf("\e[0;33monly hex conversion\e[0m\n");
	/* width specified */
	printf("\e[0;33micm width specified\e[0m\n");
	ret = ft_printf("[%10x] [%2X] [%*x] [%*X]\n", i, i, 10, -i, -10, -i);
	ret2 = printf("[%10x] [%2X] [%*x] [%*X]\n", i, i, 10, -i, -10, -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* - flag icm width*/
	printf("\e[0;33m-flag icm width\e[0m\n");
	ret = ft_printf("[%-10x] [%X] [%x] [%X]\n", i, i, -i, -i);
	ret2 = printf("[%-10x] [%X] [%x] [%X]\n", i, i, -i, -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* 0flag icm width */
	printf("\e[0;33m0flag icm width\e[0m\n");
	ret = ft_printf("mine:	[%010x] [%0*X] [%015x] [%010X]\n", i, -10, i, -i, -i);
	ret2 = printf("real:	[%010x] [%0*X] [%015x] [%010X]\n", i, -10, i, -i, -i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// i = 0
	i = 0;
	printf("\e[0;36mi = 0\e[0m\n");
	ret = ft_printf("mine:	[%010x] [%0*x]\n", i, -10, i);
	ret2 = printf("real:	[%010x] [%0*x]\n", i, -10, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	printf("\e[0;33mspecifying precision\e[0m\n");
	printf("\e[0;36mi = 8432\e[0m\n");
	// i = 8432
	i = 8432;
	ret = ft_printf("[%0.10i] [%0.*i]\n", i, -10, i);
	ret2 = printf("[%0.10i] [%0.*i]\n", i, -10, i);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);

	/* STRINGS ONLY */
	// NO FLAGS
	printf("\e[0;33no flags\e[0m\n");
	ret = ft_printf("[%s]\n", str);
	ret2 = printf("[%s]\n", str);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	//str & str + 5
	ret = ft_printf("[%s] [%s]\n", str, str + 5);
	ret2 = printf("[%s] [%s]\n", str, str + 5);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	// flaggiewaggies
	ret = ft_printf("mine:	[%.5s] [%.*s] [%.s]\n", str, -5, str, str);
	ret2 = printf("real:	[%.5s] [%.*s] [%.s]\n", str, -5, str, str);
	if (ret != ret2)
		printf("\e[0;31mreturn value incorrect\e[0m\nexpected: %i\nreceived: %i\n", ret2, ret);
	/* CHARS ONLY */
	
	return (0);
}
