/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:58:14 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 11:26:10 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab			*format_precision(t_tab *tab)
{
	size_t	padding_length;
	char	*padding_string;

	if (tab->specifier == 's')
	{
		tab->argument[tab->precision] = '\0';
		return (tab);
	}
	padding_length = tab->precision - ft_strlen(tab->argument);
	if (tab->negative)
	{
		padding_length++;
		tab->argument++;
	}
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length);
	if (tab->negative)
		padding_string[0] = '-';
	return (tab);
}
