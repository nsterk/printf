/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:32:00 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 17:12:05 by nsterk        ########   odam.nl         */
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
	tab->ret = parse(tab);
	va_end(args);
	ret = tab->ret;
	free(tab);
	return (ret);
}
