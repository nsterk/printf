/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_initialize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:01:01 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 00:52:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*re_initialize(t_tab *tab)
{
	//tab->fcopy = (char *)tab->format;
	tab->left_justify = 0;
	tab->zero = 0;
	tab->precision = 0;
	tab->width = 0;
	tab->numerical = 0;
	tab->negative = 0;
	return (tab);
}
