/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:25:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 14:47:18 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

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
