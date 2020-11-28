/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned_itoa.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:03:04 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:38:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_unsigned_itoalen(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*rstr;

	len = ft_unsigned_itoalen(n);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	if (n == 0)
		rstr[0] = '0';
	rstr[len] = '\0';
	while (n != 0 && len >= 0)
	{
		rstr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (rstr);
}
