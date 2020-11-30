/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 21:24:38 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 13:34:01 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *src, size_t n)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, n);
	return (str);
}
