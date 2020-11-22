/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 20:08:43 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format(t_tab *tab)
{
	if (tab->width && ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	else
		tab->padded_argument = ft_strdup(tab->argument);
	print_argument(tab);
	/*
	**	and fill with ' ' or '0' depending on flags
	**	then strjoin argument+padding_str with order determined by tab->minus
 	*/
	return (tab);
}
