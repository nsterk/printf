/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:24:23 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/30 19:04:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_base_len(long long n, int divider)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= divider;
	}
	return (len);
}

char			*ft_itoa_base(long long n, char *base)
{
	char	*str;
	size_t	divider;
	size_t	len;

	divider = ft_strlen(base);
	len = itoa_base_len(n, divider);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n)
	{
		str[len - 1] = base[n % divider];
		n /= divider;
		len--;
	}
	return (str);
}
