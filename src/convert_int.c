/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:04:53 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/28 16:53:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long			get_signed_int(t_tab *tab)
{
	long long n;

	if (!tab->lenmod)
		n = (long long)va_arg(tab->args, int);
	else if (tab->lenmod == 1)
		n = (char)va_arg(tab->args, int);
	else if (tab->lenmod == 2)
		n = (short)va_arg(tab->args, int);
	else if (tab->lenmod == 3)
		n = va_arg(tab->args, long long);
	else
		n = (long long)va_arg(tab->args, int);
	return (n);
}

static unsigned long long	get_unsigned_int(t_tab *tab)
{
	unsigned long long n;

	if (!tab->lenmod)
		n = (unsigned long long)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 1)
		n = (unsigned char)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 2)
		n = (unsigned short)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 3)
		n = va_arg(tab->args, unsigned long long);
	else
		n = (unsigned long long)va_arg(tab->args, unsigned int);
	return (n);
}

int					convert_int(t_tab *tab)
{
	long long	n;
	char		*temp;

	n = get_signed_int(tab);
	if (*tab->format == 'd')
		tab->specifier = 'd';
	if (*tab->format == 'i')
		tab->specifier = 'i';
	tab->format++;
	temp = ft_itoa_base(n, "0123456789");
	if (!temp)
		return (-1);
	if (tab->plus && *temp != '-')
		tab->argument = ft_strjoin("+", temp);
	else if (tab->space && *temp != '-')
		tab->argument = ft_strjoin(" ", temp);
	else
		tab->argument = ft_strdup(temp);
	free(temp);
	if (!tab->argument)
		return (-1);
	if (*tab->argument == '-' || *tab->argument == ' ')
		tab->plus = 1;
	return (1);
}

int					convert_unsigned_int(t_tab *tab)
{
	unsigned long long n;

	n = get_unsigned_int(tab);
	tab->specifier = 'u';
	tab->format++;
	tab->argument = ft_unsigned_itoa_base(n, "0123456789");
	if (!tab->argument)
		return (-1);
	return (1);
}
