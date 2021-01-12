/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:04:53 by nsterk        #+#    #+#                 */
/*   Updated: 2021/01/12 14:35:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// static unsigned long long	get_unsigned(t_tab *tab)
// {
// 	unsigned long long n;

// 	if (!tab->lenmod)
// 		n = (unsigned long long)va_arg(tab->args, unsigned int);
// 	else if (tab->lenmod == 1)
// 		n = (unsigned char)va_arg(tab->args, unsigned int);
// 	else if (tab->lenmod == 2)
// 		n = (unsigned short)va_arg(tab->args, unsigned int);
// 	else if (tab->lenmod == 3)
// 		n = (unsigned long long)va_arg(tab->args, unsigned long);
// 	else
// 		n = va_arg(tab->args, unsigned long long);
// 	return (n);
// }

int							convert_lowhex(t_tab *tab)
{
	char			*temp;

	tab->specifier = 'x';
	tab->format++;
	temp = ft_unsigned_itoa_base(get_unsigned(tab),
	"0123456789abcdef");
	if (!temp)
		return (-1);
	if (tab->hash && ft_strcmp("0", temp))
		tab->argument = ft_strjoin("0x", temp);
	else
	{
		tab->argument = ft_strdup(temp);
		tab->hash = 0;
	}
	free(temp);
	if (!tab->argument)
		return (-1);
	return (1);
}

int							convert_uphex(t_tab *tab)
{
	char			*temp;

	tab->specifier = 'X';
	tab->format++;
	temp = ft_unsigned_itoa_base(get_unsigned(tab),
	"0123456789ABCDEF");
	if (!temp)
		return (-1);
	if (tab->hash && ft_strcmp("0", temp))
		tab->argument = ft_strjoin("0X", temp);
	else
	{
		tab->argument = ft_strdup(temp);
		tab->hash = 0;
	}
	free(temp);
	if (!tab->argument)
		return (-1);
	return (1);
}

int							convert_ptr(t_tab *tab)
{
	char		*str;

	tab->specifier = 'p';
	tab->format++;
	str = ft_unsigned_itoa_base(va_arg(tab->args, unsigned long long),
	"0123456789abcdef");
	if (!str)
		return (-1);
	if (tab->precision_bool && !tab->precision && !ft_strcmp("0", str))
		tab->argument = ft_strdup("0x");
	else
		tab->argument = ft_strjoin("0x", str);
	free(str);
	if (!tab->argument)
		return (-1);
	return (1);
}