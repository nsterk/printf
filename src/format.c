/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/26 23:13:34 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format(t_tab *tab)
{
	if (tab->precision)
		format_precision(tab);
	if ((int)ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	printf("tab->argument end of format: [%s]\n", tab->argument);
	//print_argument(tab);
	//printf("tab->padded_argument: [%s]\n", tab->padded_argument);
	return (tab);
}
