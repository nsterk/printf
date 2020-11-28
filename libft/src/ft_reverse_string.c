/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:32:12 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:38:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_string(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	if (*str == '-')
	{
		start = str + 1;
		end = start + (ft_strlen(str) - 2);
	}
	else
	{
		start = str;
		end = start + (ft_strlen(str) - 1);
	}
	while (end > start)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);
}
