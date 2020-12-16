/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:32:00 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/16 15:33:45 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int			ret;
	t_tab		*tab;
	va_list		args;

	tab = malloc(sizeof(t_tab));
	if (!format || !tab)
		return (-1);
	tab->format = format;
	tab = initialize(tab);
	va_start(tab->args, format);
	ret = parse(tab);
	va_end(args);
	free(tab);
	return (ret);
}
