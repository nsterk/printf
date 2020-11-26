/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:58:14 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/26 23:12:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab			*format_precision(t_tab *tab)
{
	int		padding_length;
	char	*padding_string;

	if (tab->specifier == 's')
	{
		tab->argument[tab->precision] = '\0';
		return (tab);
	}
	padding_length = tab->precision - (int)ft_strlen(tab->argument);
	if (tab->negative)
		padding_length++;
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length);
	padding_string[padding_length] = '\0';
	if (tab->negative)
	{
		padding_string[0] = '-';
		tab->argument = ft_strjoin(padding_string, tab->argument + 1);
	}
	else
		tab->argument = ft_strjoin(padding_string, tab->argument);
	tab->negative = 0;
	free(padding_string);
	return (tab);
}
