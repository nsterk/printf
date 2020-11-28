/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned_itoa_base.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:03:04 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 21:13:19 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_unsigned_itoa_baselen(unsigned int num, int divider)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num /= divider;
	}
	return (len);
}

char			*ft_unsigned_itoa_base(unsigned int num, char *base)
{
	char	*str;
	int		divider;
	int		len;

	divider = ft_strlen(base);
	len = ft_unsigned_itoa_baselen(num, divider);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len - 1] = base[num % divider];
		num /= divider;
		len--;
	}
	return (str);
}
