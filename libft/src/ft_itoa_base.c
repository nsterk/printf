/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:24:23 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 15:44:27 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

const size_t	itoa_base_len(long num, size_t divider)
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

char		*ft_itoa_base(int num, char *base)
{
	char	*str;
	size_t	divider;
	long	long_num;
	size_t	len;

	long_num = (long)num;
	divider = ft_strlen(base);
	len = itoa_base_len(long_num, divider);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (long_num)
	{
		str[len - 1] = base[long_num % divider];
		long_num /= divider;
		len--;
	}
	return (str);
}
