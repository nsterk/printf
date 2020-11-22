/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:46:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/16 21:51:20 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert(t_tab *tab)
{
	char			c;
	int				i;
	unsigned int	u;

	if (tab->specifier == 'c')
	{
		c = va_arg(tab->args, char);
		tab->argument = malloc(sizeof(char) * 2); //add protection
		tab->argument[0] = c;
		tab->argument[1] = '\n';
	}
	if (tab->specifier == 'i' || tab->specifier == 'd')
	{
		i = va_arg(tab->args, int);
		tab->argument = ft_itoa(i);
	}
	if (tab->specifier == 's')
		tab->argument = va_arg(lst->args, char *);
	if (tab->specifier == 'u')
	{
		u = va_arg(tab->args, unsigned int);
		tab->argument = ft_unsigned_itoa(u);
	}
	return (tab);
}
