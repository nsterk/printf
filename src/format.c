/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/27 13:06:09 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static t_tab	*format_string_precision(t_tab *tab)
{
	char	*temp;
	temp = ft_strdup(tab->argument);
	if (!temp)
		return (NULL);
	free(tab->argument);
	tab->argument = ft_calloc(tab->precision + 1, sizeof(*temp));
	if (!tab->argument)
		return (NULL);
	ft_strlcpy(tab->argument, temp, tab->precision + 1);
	free(temp);
	return (tab);
}

t_tab			*format(t_tab *tab)
{
	if (tab->precision && tab->specifier == 's' &&
		tab->precision < (int)ft_strlen(tab->argument))
		format_string_precision(tab);
	else if (tab->precision > (int)ft_strlen(tab->argument))
		format_precision(tab);
	if ((int)ft_strlen(tab->argument) < tab->width)
	{
		tab->is_padded = 1;
		format_padding(tab);
	}
	print_argument(tab);
	return (tab);
}
