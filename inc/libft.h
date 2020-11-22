/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:00:39 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/19 10:26:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
char		*ft_itoa(int n);
void		*ft_memset(void *str, int c, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *s);
size_t		*ft_strnlen(const char *s, size_t maxlen);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_reverse_string(char *str);
int			*ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_unsigned_itoa(unsigned int n);

#endif
