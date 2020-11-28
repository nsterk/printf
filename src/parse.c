/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 13:55:51 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		parse(t_tab *tab)
{
	while (*tab->format != '\0')
	{
		if (*tab->format == '%')
		{
			tab->format++;
			if (*tab->format == '%')
			{
				print_char(tab);
				break ;
			}
			parse_flags(tab);
			parse_specifier(tab);
			format(tab);
		}
		else
			print_char(tab);
	}
	return (tab->ret);
}
