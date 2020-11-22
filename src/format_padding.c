/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_padding.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:37:07 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 12:41:15 by nsterk        ########   odam.nl         */
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
		if (tab->negative)
		{
			ft_memset(padding_string, '0', padding_length);
			padding_string[0] = '-';
		}
		else
			ft_memset(padding_string, '0', padding_length);
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
































/*
t_tab	*format_padding(t_tab *tab)
{
	size_t	padding_length;
	char	*padding_string;

	padding_length = tab->width - ft_strlen(tab->argument);
	if (tab->zero && !tab->minus && tab->negative)
	{
		padding_length++;
		tab->argument++;
	}
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	padding_string[padding_length] = '\0';
	if (tab->zero && tab->numerical && !tab->minus)//hier nog op terugkomen want mag alleen bij numerical input
	{
		if (tab->negative)
		{
			padding_string[0] = '-';
			ft_memset(padding_string + 1, '0', padding_length - 1);
		}
		else
			ft_memset(padding_string, '0', padding_length);
	}
	else
		ft_memset(padding_string, ' ', padding_length);
	if (tab->minus)
		tab->padded_argument = ft_strjoin(tab->argument, padding_string);
	else
		tab->padded_argument = ft_strjoin(padding_string, tab->argument);
	free(padding_string);
	return (tab);
}
*/
/* 
**	nu als tab->zero maar !tab->numerical doet ie alsof die 0 nooit is gevonden:
**	pad met spaties ipv nullen alsof er niets aan de hand is. echte printf geeft
**	denk ik error ofzo? dus dat nog bekijken later. Wat doen in dat geval?
**
**	ook in that vein: wat te doen als tab->zero && tab->minus?
**	want dat doet ie gewoon niet. in dat geval ook een error message?
*/