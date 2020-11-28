/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:29:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 21:13:31 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

t_tab	*convert_ptr(t_tab *tab)
{
	char			*str;
	unsigned int	address;

	address = va_arg(tab->args, unsigned int);
	str = ft_unsigned_itoa_base(address, "0123456789abcdef");
	if (!str)
		return (NULL);
	if (ft_strcmp("0", str))
		tab->argument = ft_strjoin("0x10", str);
	else
		tab->argument = ft_strjoin("0x", str);
	if (!tab->argument)
		return (NULL);
	tab->specifier = 'p';
	free(str);
	return (tab);
}
