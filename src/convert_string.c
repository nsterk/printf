/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:04:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 16:16:21 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_tab	*convert_string(t_tab *tab)
{
	char	*temp;
	
	tab->specifier = 's'; 
	temp = va_arg(tab->args, char *);
	if (tab->precision < 0)
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
