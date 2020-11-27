/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_padding.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:37:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 17:03:58 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*format_padding(t_tab *tab)
{
	char	*temp;
	char	*padding_string;
	size_t	padding_length;

	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	padding_length = (size_t)tab->width - ft_strlen(temp);
	if (tab->negative && tab->zero)
		padding_length++;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	if (tab->zero)
	{
		ft_memset(padding_string, '0', padding_length);
		if (tab->negative)
			padding_string[0] = '-';
	}
	else
		ft_memset(padding_string, ' ', padding_length);
	if (tab->left_justify)
		tab->argument = ft_strjoin(temp, padding_string);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	free(padding_string);
	return (tab);
}



/*
t_tab	*format_padding(t_tab *tab)
{
	char	*padding_string;
	// char	*temp;
	size_t	padding_length;

	// temp = malloc(sizeof(*temp) * ft_strlen(tab->argument) + 1);
	// ft_memcpy(temp, tab->argument, ft_strlen(tab->argument) + 1);
	// free(tab->argument);
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
		tab->argument = ft_strjoin(temp, padding_string);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	free(padding_string);
	//free(temp);
	return (tab);
}
*/