/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_alpha.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 13:02:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/14 20:31:31 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*convert_string(t_tab *tab)
{
	char	*temp;
	
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
		return (NULL);
	return (tab);
}

t_tab	*convert_char(t_tab *tab)
{
	int c;

	c = va_arg(tab->args, int);
	tab->argument = ft_calloc(2, sizeof(unsigned char));
	if (!tab->argument)
		return (NULL);
	ft_memset(tab->argument, c, 1);
	tab->specifier = 'c';
	return (tab);
}
