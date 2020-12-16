/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:04:53 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/16 17:30:47 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert_int(t_tab *tab)
{
	int		i;

	if (*tab->format == 'd')
		tab->specifier = 'd';
	if (*tab->format == 'i')
		tab->specifier = 'i';
	i = va_arg(tab->args, int);
	if (i < 0)
		tab->negative = 1;
	tab->argument = ft_itoa(i);
	if (!tab->argument)
		return (-1);
	tab->numerical = 1;
	return (tab->ret);
}

int		convert_unsigned_int(t_tab *tab)
{
	unsigned int ui;

	ui = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa_base(ui, "0123456789");
	if (!tab->argument)
		return (-1);
	tab->numerical = 1;
	tab->specifier = 'u';
	return (tab->ret);
}

int	convert_hex(t_tab *tab)
{
	unsigned long ui;

	ui = va_arg(tab->args, unsigned long);
	if (*tab->format == 'x')
	{
		tab->specifier = 'x';
		tab->argument = ft_unsigned_itoa_base(ui, "0123456789abcdef");
	}
	if (*tab->format == 'X')
	{
		tab->specifier = 'X';
		tab->argument = ft_unsigned_itoa_base(ui, "0123456789ABCDEF");
	}
	if (!tab->argument)
		return (-1);
	tab->numerical = 1;
	return (tab->ret);
}

int	convert_ptr(t_tab *tab)
{
	char				*str;
	unsigned long long	address;

	tab->specifier = 'p';
	address = va_arg(tab->args, unsigned long long);
	str = ft_unsigned_itoa_base(address, "0123456789abcdef");
	if (!str)
		return (-1);
	tab->argument = ft_strjoin("0x", str);
	free(str);
	if (!tab->argument)
		return (-1);
	return (tab->ret);
}
