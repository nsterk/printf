/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:29:06 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 17:19:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

t_tab	*convert_ptr(t_tab *tab)
{
	char	*str;
	int		address;

	address = va_arg(tab->args, int);
	tab->numerical = 1;
	str = ft_itoa_base(address, "0123456789abcdef");
	tab->argument = ft_strjoin("0x10", str);
	tab->specifier = 'p';
	free(str);
	return (tab);
}
