/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:49:08 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/29 14:54:28 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	DON'T FORGET:
**	remove unused library headers like stdio.h
*/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef	struct	s_tab
{
	const char	*format;
	va_list		args;
	size_t		i;
	char		*flags;
	char		*conversion_types;
	void		*argument;
	int			left_justify;
	int			zero;
	int			width;
	int			precision;
	char		specifier;
	int			skip; //if prec = 0 && value of numerical argument = 0, skip printing; only free and re_initialze
	int			numerical; //is the argument numerical?
	int			negative; //is the number negative?
	int			ret;
}				t_tab;

int				ft_printf(const char *format, ...);
t_tab			*initialize(t_tab *tab);
t_tab			*re_initialize(t_tab *tab);
t_tab			*get_width(t_tab *tab);
t_tab			*get_precision(t_tab *tab);
int				parse(t_tab *tab);
t_tab			*parse_specifier(t_tab *tab);
t_tab			*parse_flags(t_tab *tab);
t_tab			*convert_char(t_tab *tab);
t_tab			*convert_hex(t_tab *tab);
t_tab			*convert_int(t_tab *tab);
t_tab			*convert_unsigned_int(t_tab *tab);
t_tab			*convert_ptr(t_tab *tab);
t_tab			*convert_string(t_tab *tab);
int				format(t_tab *tab);
t_tab			*format_padding(t_tab *tab);
t_tab			*format_width(t_tab *tab);
t_tab			*format_precision(t_tab *tab);
t_tab			*print_char(t_tab *tab);
int				print_argument(t_tab *tab);

#endif
