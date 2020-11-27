/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:58:14 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 14:27:18 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format_precision(t_tab *tab)
{
	size_t	padding_length;
	char	*padding_string;
	char	*temp;

	temp = ft_strdup(tab->argument);
	if (!temp)
		return (NULL);
	free(tab->argument);
	padding_length = tab->precision - ft_strlen(temp);
	if (tab->negative)
		padding_length += 2;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length);
	padding_string[padding_length] = '\0';
	if (tab->negative)
	{
		padding_string[0] = '-';
		tab->argument = ft_strjoin(padding_string, temp + 1);
	}
	else
		tab->argument = ft_strjoin(padding_string, temp);
	tab->negative = 0;
	free(padding_string);
	free(temp);
	return (tab);
}
