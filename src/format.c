/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 13:09:08 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format(t_tab *tab)
{
	if (tab->precision)
		format_precision(tab);
	if (tab->width && ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	//else <-hier nog iets mee doen
	//	tab->padded_argument = ft_strdup(tab->argument);
	print_argument(tab);
	return (tab);
}
