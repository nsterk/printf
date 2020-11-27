/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:04:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 11:57:01 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert_string(t_tab *tab)
{
	tab->argument = ft_strdup(va_arg(tab->args, char *));
	if (!tab->argument)
		return (NULL);
	tab->specifier = 's';
	return (tab);
}
