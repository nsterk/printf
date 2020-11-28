/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 15:12:14 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			format(t_tab *tab)
{
	if (tab->precision >= 0)
	{
		if (!ft_strcmp(tab->argument, "0") && tab->precision == 0)
		{
			free(tab->argument);
			tab->argument = ft_calloc(1, sizeof(*tab->argument));
		}
		else
			format_precision(tab);
	}
	if ((int)ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	print_argument(tab);
	return (tab->ret);
}
