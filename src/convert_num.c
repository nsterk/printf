/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:04:53 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 13:06:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*convert_int(t_tab *tab)
{
	int		i;
	char	*str;

	if (tab->format[tab->i] == 'd')
		tab->specifier = 'd';
	if (tab->format[tab->i] == 'i')
		tab->specifier = 'i';
	i = va_arg(tab->args, int);
	if (i < 0)
		tab->negative = 1;
	str = ft_itoa(i);
	if (!str)
		return (NULL);
	tab->argument = ft_strdup(str);
	if (!tab->argument)
		return (NULL);
	free(str);
	tab->numerical = 1;
	return (tab);
}

t_tab	*convert_unsigned_int(t_tab *tab)
{
	unsigned int ui;

	ui = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa_base(ui, "0123456789");
	if (!tab->argument)
		return (NULL);
	tab->numerical = 1;
	tab->specifier = 'u';
	return (tab);
}

t_tab		*convert_hex(t_tab *tab)
{
	unsigned int	ui;
	//printf("w to the idth %i\n", tab->width);
	ui = va_arg(tab->args, unsigned int);
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
	tab->numerical = 1;
	return (tab);
}

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