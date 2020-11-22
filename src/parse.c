/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 11:44:42 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

int		parse(t_tab *tab)
{
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
		{
			parse_flags(tab);
		}
		else
		{
			write(1, &tab->format[tab->i], 1);
			tab->ret++;
			tab->i++;
		}
	}
	return (tab->ret);
}
