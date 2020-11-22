/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:04:51 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/21 12:24:29 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

// static size_t	ft_strnlen(const char *s, size_t maxlen)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < maxlen)
// 	{
// 		if (s[i] == '\0')
// 			return (i);
// 		i++;
// 	}
// 	return (maxlen);
// }

t_tab	*convert_string(t_tab *tab)
{
	tab->argument = va_arg(tab->args, char *);
	return (tab);
}
