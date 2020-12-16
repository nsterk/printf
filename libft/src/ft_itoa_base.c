/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:24:23 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/16 14:26:24 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	itoa_base_len(long num, int divider)
{
	size_t len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num)
	{
		len++;
		num /= divider;
	}
	return (len);
}

char			*ft_itoa_base(long num, char *base)
{
	char	*str;
	size_t	divider;
	size_t	len;

	divider = ft_strlen(base);
	len = itoa_base_len(num, divider);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (num)
	{
		str[len - 1] = base[num % divider];
		num /= divider;
		len--;
	}
	return (str);
}
