/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:24:23 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:38:37 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	itoa_base_len(long num, int divider)
{
	int len;

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
	int		divider;
	int		len;

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
