/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:04:53 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/21 14:29:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		convert_int(t_tab *tab)
{
	int		i;

	if (*tab->format == 'd')
		tab->specifier = 'd';
	if (*tab->format == 'i')
		tab->specifier = 'i';
	tab->format++;
	i = va_arg(tab->args, int);
	if (i < 0)
		tab->negative = 1;
	tab->argument = ft_itoa(i);
	if (!tab->argument)
		return (-1);
	return (1);
}

int		convert_unsigned_int(t_tab *tab)
{
	unsigned int ui;

	tab->specifier = 'u';
	tab->format++;
	ui = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa_base(ui, "0123456789");
	if (!tab->argument)
		return (-1);
	return (1);
}

int		convert_lowhex(t_tab *tab)
{
	unsigned long	ui;
	char			*temp;

	tab->specifier = 'x';
	tab->format++;
	ui = va_arg(tab->args, unsigned long);
	temp = ft_unsigned_itoa_base(ui, "0123456789abcdef");
	if (!temp)
		return (-1);
	if (tab->hash && ft_strchr("789abcdef", (int)*temp))
		tab->argument = ft_strjoin("0x", temp);
	else
		tab->argument = ft_strdup(temp);
	free(temp);
	if (!tab->argument)
		return (-1);
	return (1);
}

int		convert_uphex(t_tab *tab)
{
	unsigned long	ui;
	char			*temp;

	tab->specifier = 'X';
	tab->format++;
	ui = va_arg(tab->args, unsigned long);
	temp = ft_unsigned_itoa_base(ui, "0123456789ABCDEF");
	if (!temp)
		return (-1);
	if (tab->hash && ft_strchr("789ABCDEF", (int)*temp))
		tab->argument = ft_strjoin("0X", temp);
	else
		tab->argument = ft_strdup(temp);
	free(temp);
	if (!tab->argument)
		return (-1);
	return (1);
}

int		convert_ptr(t_tab *tab)
{
	char				*str;
	unsigned long long	address;

	tab->specifier = 'p';
	tab->format++;
	address = va_arg(tab->args, unsigned long long);
	str = ft_unsigned_itoa_base(address, "0123456789abcdef");
	if (!str)
		return (-1);
	tab->argument = ft_strjoin("0x", str);
	free(str);
	if (!tab->argument)
		return (-1);
	return (1);
}
