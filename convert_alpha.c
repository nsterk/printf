/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_alpha.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:02:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/30 13:00:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		convert_string(t_tab *tab)
{
	char	*temp;

	tab->format++;
	tab->specifier = 's';
	temp = va_arg(tab->args, char *);
	if (!tab->precision_bool)
	{
		if (!temp)
			tab->argument = ft_strdup("(null)");
		else
			tab->argument = ft_strdup(temp);
	}
	else
	{
		if (!temp)
			tab->argument = ft_strndup("(null)", (size_t)tab->precision + 1);
		else
			tab->argument = ft_strndup(temp, (size_t)tab->precision + 1);
	}
	if (!tab->argument)
		return (-1);
	tab->arg_len = ft_strlen(tab->argument);
	tab->precision_bool = 0;
	return (1);
}

int		convert_char(t_tab *tab)
{
	int c;

	if (*tab->format == 'c')
	{
		c = va_arg(tab->args, int);
		tab->specifier = 'c';
	}
	else
		c = *tab->format;
	tab->format++;
	tab->argument = ft_calloc(2, sizeof(unsigned char));
	if (!tab->argument)
		return (-1);
	ft_memset(tab->argument, c, 1);
	tab->arg_len = 1;
	tab->precision_bool = 0;
	return (1);
}
