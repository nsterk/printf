/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:26:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/19 10:21:30 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

t_tab	*convert_char(t_tab *tab)
{
	int c;

	c = va_arg(tab->args, int);
	tab->argument = malloc(sizeof(char) * 2);
	tab->argument[0] = c;
	tab->argument[1] = '\n';
	return (tab);
}
