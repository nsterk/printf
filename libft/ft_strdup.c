/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 21:24:38 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/30 13:29:32 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;

	len = ft_strlen((char *)src);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
