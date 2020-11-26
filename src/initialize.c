/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:21:36 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/26 23:32:30 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*initialize(t_tab *tab)
{
	//tab->fcopy = (char *)tab->format;
	tab->i = 0;
	tab->flags = "-0.*";
	tab->conversion_types;
	tab->zero = 0;
	tab->minus = 0;
	tab->precision = 0;
	tab->width = 0;
	tab->numerical = 0;
	tab->negative = 0;
	//tab->specifier = "cspdiuxX%";
	tab->ret = 0;
	return (tab);
}
