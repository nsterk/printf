/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:55:21 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 14:49:16 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

int		parse(t_tab *tab)
{
	while (*tab->format != '\0')
	{
		if (*tab->format == '%')
		{
			tab->format++;
			parse_flags(tab);
		}
		else
		{
			ft_putchar_fd(*tab->format, 1);
			tab->ret++;
			tab->format++;
		}
	}
	return (tab->ret);
}
