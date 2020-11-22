/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:04:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 17:19:08 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert_string(t_tab *tab)
{
	tab->argument = va_arg(tab->args, char *);
	tab->specifier = 's';
	return (tab);
}
