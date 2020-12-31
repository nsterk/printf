/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:21:36 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/30 13:04:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize(t_tab *tab)
{
	tab->arg_len = 0;
	tab->zero = 0;
	tab->left_justify = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->precision = -1;
	tab->precision_bool = 0;
	tab->width = 0;
	tab->lenmod = 0;
	tab->ret = 0;
}
