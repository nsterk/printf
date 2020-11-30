/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 17:54:26 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parse(t_tab *tab)
{
	while (*tab->format != '\0')
	{
		if (*tab->format == '%' && tab->format[1] != '%')
		{
			tab->format++;
			parse_flags(tab);
			//parse_specifier(tab);
			//format(tab);
		}
		else
			print_char(tab);
	}
	return (tab->ret);
}
