/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:04:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 16:58:11 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert_string(t_tab *tab)
{
	char	*temp;

	temp = va_arg(tab->args, char *);
	if (!temp)
		tab->argument = ft_strdup("(null)");
	else
		tab->argument = ft_strdup(temp);
	if (!tab->argument)
		return (NULL);
	tab->specifier = 's';
	return (tab);
}
