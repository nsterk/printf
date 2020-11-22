/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 19:24:23 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/22 15:41:50 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

int			main(void)
{
	int		i;
	char	*base_2;
	char	*base_10;
	char	*base_16;

	base_2 = "01";
	base_10 = "0123456789";
	base_16 = "0123456789abcdef";
	i = 25;
	printf("%s\n", ft_itoa_base(i, base_2));
	return (0);
}
