/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_initialize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:01:01 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:16:09 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	re_initialize(t_tab *tab)
{
	tab->left_justify = 0;
	tab->zero = 0;
	tab->precision = -1;
	tab->precision_bool = 0;
	tab->width = 0;
	tab->numerical = 0;
	tab->negative = 0;
}
