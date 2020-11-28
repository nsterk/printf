/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:03:04 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 14:40:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static int		ft_itoalen(long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long	long_n;
	int		len;
	char	*rstr;

	long_n = (long)n;
	len = ft_itoalen(long_n);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	if (long_n == 0)
		rstr[0] = '0';
	rstr[len] = '\0';
	if (long_n < 0)
	{
		long_n = -long_n;
		rstr[0] = '-';
	}
	while (long_n && len >= 1)
	{
		rstr[len - 1] = long_n % 10 + '0';
		long_n /= 10;
		len--;
	}
	return (rstr);
}
