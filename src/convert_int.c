/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:25:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 16:33:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_tab	*convert_int(t_tab *tab)
{
	int		i;
	char	*str;

	i = va_arg(tab->args, int);
	if (i < 0)
		tab->negative = 1;
	tab->numerical = 1;
	str = ft_itoa_base(i, "0123456789");
	tab->argument = str;
	//free(str); //ok dit is nog iest dat later gefixt moet worden want als ik hier free heb ik geen memory leak MAAR dan is er een probleem als ik later tab->argument wil gaan formatten
	return (tab);
}

/*	TO DO FOR PRINT_INT	 */
/*	- all formatting: */
/*		- checking for flags and combinations of flags */
/*			? reset tab to default settings prior to doing anything else? 
		questions:
		a) what needs to  be reset, ie what are default settings
		b) do i want these default settings to vary across variable types. why or why not */