/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:03:04 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/28 14:58:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_itoalen(long long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(long long n)
{
	int		len;
	char	*rstr;

	len = ft_itoalen(n);
	rstr = (char *)ft_calloc(len + 1, sizeof(*rstr));
	if (!rstr)
		return (NULL);
	if (n == 0)
		rstr[0] = '0';
	if (n < 0)
	{
		n = -n;
		rstr[0] = '-';
	}
	while (n && len >= 1)
	{
		rstr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (rstr);
}
