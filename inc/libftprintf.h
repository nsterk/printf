/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:49:08 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/19 13:15:51 by nsterk        ########   odam.nl         */
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
	char		*conversion_types;
	char		*argument;
	char		*padding;
	int			left_justify;
	int			zero;
	int			width;
	int			precision;
	int			precision_bool;
	char		specifier;
	int			numerical; //is the argument numerical?
	int			negative; //is the number negative?
	int			ret;
}				t_tab;

int				ft_printf(const char *format, ...);
void			initialize(t_tab *tab);
void			re_initialize(t_tab *tab);
int				get_width(t_tab *tab);
int				get_precision(t_tab *tab);
int				parse(t_tab *tab);
int				parse_specifier(t_tab *tab);
int				parse_flags(t_tab *tab);
void			parse_zero_minus(t_tab *tab);
int				convert_char(t_tab *tab);
int				convert_hex(t_tab *tab);
int				convert_int(t_tab *tab);
int				convert_unsigned_int(t_tab *tab);
int				convert_ptr(t_tab *tab);
int				convert_string(t_tab *tab);
int				format(t_tab *tab);
int				format_padding(t_tab *tab);
t_tab			*format_width(t_tab *tab);
int				format_precision(t_tab *tab);
int				print_char(t_tab *tab);
int				print_argument(t_tab *tab);
void			print_argument_char(t_tab *tab);

#endif
