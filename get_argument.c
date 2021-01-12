/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_argument.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 14:34:28 by nsterk        #+#    #+#                 */
/*   Updated: 2021/01/12 14:39:38 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	get_unsigned(t_tab *tab)
{
	unsigned long long n;

	if (!tab->lenmod)
		n = (unsigned long long)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 1)
		n = (unsigned char)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 2)
		n = (unsigned short)va_arg(tab->args, unsigned int);
	else if (tab->lenmod == 3)
		n = (unsigned long long)va_arg(tab->args, unsigned long);
	else
		n = va_arg(tab->args, unsigned long long);
	return (n);
}

long long			get_signed(t_tab *tab)
{
	long long n;

	if (!tab->lenmod)
		n = (long long)va_arg(tab->args, int);
	else if (tab->lenmod == 1)
		n = (char)va_arg(tab->args, int);
	else if (tab->lenmod == 2)
		n = (short)va_arg(tab->args, int);
	else if (tab->lenmod == 3)
		n = (long long)va_arg(tab->args, long);
	else
		n = va_arg(tab->args, long long);
	return (n);
}
