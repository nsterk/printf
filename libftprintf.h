/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 19:49:08 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/30 19:37:05 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

/*
** The t_tab struct stores all necessary information.
** The variables in this struct represent:
**
** format:			the string that was passed to ft_printf.
** args:			the arguments that were passed to ft_printf.
** ret:				total nr of characters printed (return value ft_printf).
** argument:		the current argument that is being processed.
**
** FLAGS
** left_justify:	minus flag.
** zero, space:		zero flag and space flag.
** plus, hash:		plus flag and hash flag.
**
** FIELD SPECS
** width:			stores value of width specified.
** precision:		stores value precision specified.
** precision_bool:	set to 1 if precision has been specified.
**
** CONVERSION SPECS
** lenmod:			stores length modifier specified.
** specifier:		conversion specifier.
*/

typedef	struct	s_tab
{
	const char	*format;
	va_list		args;
	int			ret;
	char		*argument;
	int			arg_len;
	int			left_justify;
	int			zero;
	int			space;
	int			plus;
	int			hash;
	int			width;
	int			precision;
	int			precision_bool;
	int			lenmod;
	char		specifier;
}				t_tab;

int				ft_printf(const char *format, ...);
void			initialize(t_tab *tab);
void			re_initialize(t_tab *tab);

/*
** Parsing functions.
*/

int				parse(t_tab *tab);
int				get_width(t_tab *tab);
int				get_precision(t_tab *tab);

/*
** Conversion functions and dispatch table to these functions.
*/

int				convert_char(t_tab *tab);
int				convert_lowhex(t_tab *tab);
int				convert_uphex(t_tab *tab);
int				convert_int(t_tab *tab);
int				convert_unsigned_int(t_tab *tab);
int				convert_ptr(t_tab *tab);
int				convert_string(t_tab *tab);
typedef int		(*t_convert)(t_tab *tab);

/*
** Formatting + printing functions.
*/

int				format(t_tab *tab);
int				print_char(t_tab *tab);
int				print_argument(t_tab *tab);

#endif
