/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_precision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:58:14 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 13:09:10 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_tab	*format_string_precision(t_tab *tab)
{
	char	*temp;

	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	tab->argument = ft_calloc(tab->precision + 1, sizeof(*temp));
	if (!tab->argument)
		return (NULL);
	ft_strlcpy(tab->argument, temp, tab->precision + 1);
	free(temp);
	return (tab);
}

static char		*make_padding(t_tab *tab)
{
	size_t	padding_length;
	char	*padding_string;

	padding_length = tab->precision - ft_strlen(tab->argument);
	if (tab->negative)
		padding_length += 2;
	padding_string = ft_calloc(padding_length + 1, sizeof(*padding_string));
	if (!padding_string)
		return (NULL);
	ft_memset(padding_string, '0', padding_length - 1);
	if (tab->negative)
		padding_string[0] = '-';
	return (padding_string);
}

static t_tab	*format_num_precision(t_tab *tab)
{
	char	*padding_string;
	char	*temp;

	padding_string = make_padding(tab);
	if (!padding_string)
		return (NULL);
	temp = ft_strdup(tab->argument);
	free(tab->argument);
	if (!temp)
		return (NULL);
	if (tab->negative)
		tab->argument = ft_strjoin(padding_string, temp + 1);
	else
		tab->argument = ft_strjoin(padding_string, temp);
	tab->negative = 0;
	free(padding_string);
	free(temp);
	return (tab);
}

t_tab			*format_precision(t_tab *tab)
{
	if (tab->specifier == 's')
	{
		if (tab->precision < (int)ft_strlen(tab->argument))
			return (format_string_precision(tab));
		else
			return (tab);
	}
	else if (tab->precision >= (int)ft_strlen(tab->argument))
		format_num_precision(tab);
	return (tab);
}
