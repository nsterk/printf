/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 21:24:38 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/16 18:36:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strdup(const char *src)
{
	char	*rstr;
	size_t	len;

	len = ft_strlen((char *)src);
	rstr = (char*)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	rstr = ft_strcpy(rstr, src);
	return (rstr);
}
