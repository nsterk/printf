/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:23:15 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 14:31:24 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
/*
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
} */

int			format(t_tab *tab)
{
	return (tab->ret);
	if (tab->precision >= 0)
	{
		if (!ft_strcmp(tab->argument, "0") && tab->precision == 0)
		{
			tab->skip = 1;
			return (print_argument(tab));
		}
		format_precision(tab);
	}
	if ((int)ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	print_argument(tab);
	return (tab->ret);
}
