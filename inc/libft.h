/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:00:39 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/29 19:09:31 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
int			ft_isspace(int c);
char		*ft_itoa_base(long long num, char *base);
void		*ft_memset(void *str, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(char *s1, char *s2);
void		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_unsigned_itoa_base(unsigned long long num, char *base);

#endif
