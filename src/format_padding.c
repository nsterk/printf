/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_padding.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:37:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/23 11:28:58 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format_padding(t_tab *tab)
{
	char	*padding_string;
	size_t	padding_length;

	padding_length = tab->width - ft_strlen(tab->argument);
	if (tab->zero && !tab->minus && tab->negative)
	{
		padding_length++;
		tab->argument++;
	}
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	if (tab->zero && !tab->minus && tab->numerical)
	{
		ft_memset(padding_string, '0', padding_length);
		if (tab->negative)
			padding_string[0] = '-';
	}
	else
		ft_memset(padding_string, ' ', padding_length);
	padding_string[padding_length] = '\0';
	if (tab->minus)
		tab->padded_argument = ft_strjoin(tab->argument, padding_string);
	else
		tab->padded_argument = ft_strjoin(padding_string, tab->argument);
	free(padding_string);
	return (tab);
}
