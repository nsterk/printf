/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:32:00 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/20 16:40:33 by nsterk        ########   odam.nl         */
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
	initialize(tab);
	va_start(tab->args, format);
	while (*tab->format)
	{
		if (*tab->format == '%')
		{
			tab->format++;
			if (parse(tab) < 0)
				return (-1);
		}
		else
			tab->ret = print_char(tab);
	}
	ret = tab->ret;
	va_end(args);
	free(tab);
	return (ret);
}
