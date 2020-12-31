/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 19:34:01 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/28 17:38:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Removed checks from original ft_substr relating to size len compared 
**	to size of s, since I know that when used for printf this won't be an issue.
**	And I'm afraid otherwise there might be a risk for overflow rendering the
**	comparison invalid, in case of really long tab->format string.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (!s)
		return (NULL);
	sub = (char*)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
