/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   massiveprintf.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 21:31:17 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/19 15:38:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <libftprintf.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef	struct	s_tab
{
	const char	*format;
	va_list		args;
	size_t		i;
	char		*argument;
	int			minus;
	int			zero;
	int			width;
	char		specifier;
	char		*padded_argument;
	int			ret;
}				t_tab;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int		print_argument(t_tab *tab)
{
	ft_putstr_fd(tab->padded_argument, 1);
	tab->ret = (int)ft_strlen(tab->padded_argument);
	return (tab->ret);
}

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\v' || c == ' ');
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

int		ull_overflow(int negative, unsigned long long num, const char *str)
{
	if (negative == -1 && *str > 5)
		return (0);
	if (negative == 1 && *str > 5)
		return (-1);
	num = (num * 10) + (*str - '0');
	return (num);
}

int		ll_overflow(int negative, unsigned long long num, const char *str)
{
	if (negative == -1 && *str > 8)
		return (0);
	if (negative == 1 && *str > 7)
		return (-1);
	num = (num * 10) + (*str - '0');
	return (num * negative);
}

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	int					negative;

	num = 0;
	negative = 1;
	if (*str == '\0')
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num >= 92233720368547758)
			return (ll_overflow(negative, num, str));
		else if (num >= 1844674407370955161)
			return (ull_overflow(negative, num, str));
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * negative);
}

int		ft_itoalen(long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		len;
	char	*rstr;

	// if (base < 2 || base > 16)
	// 	return (0);
	long_n = n;
	len = ft_itoalen(long_n);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	if (long_n == 0)
		rstr[0] = '0';
	if (long_n < 0)
	{
		rstr[0] = '-';
		long_n *= -1;
	}
	rstr[len] = '\0';
	while (long_n != 0 && len >= 0)
	{
		rstr[len - 1] = (long_n % 10) + '0';
		long_n /= 10;
		len--;
	}
	return (rstr);
}

int		ft_unsigned_itoalen(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*rstr;

	len = ft_unsigned_itoalen(n);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	if (n == 0)
		rstr[0] = '0';
	rstr[len] = '\0';
	while (n != 0 && len >= 0)
	{
		rstr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (rstr);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

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

t_tab	*format_padding(t_tab *tab)
{
	int		padding_length;
	char	*padding_string;

	if (tab->width && (int)ft_strlen(tab->argument) < tab->width)
		padding_length = tab->width - (int)ft_strlen(tab->argument);
	padding_string = malloc(sizeof(*padding_string) * (padding_length + 1));
	if (!padding_string)
		return (NULL);
	if (tab->zero)
		ft_memset(padding_string, '0', padding_length); //hier nog op terugkomen want mag alleen bij numerical input
	else
		ft_memset(padding_string, ' ', padding_length);
	padding_string[padding_length + 1] = '\0';
	if (tab->minus)
		tab->padded_argument = ft_strjoin(tab->argument, padding_string);
	else
		tab->padded_argument = ft_strjoin(padding_string, tab->argument);
	//printf("padded_argument: [%s]\n", tab->padded_argument);
	/*
	**	and fill with ' ' or '0' depending on flags
	**	then strjoin argument+padding_str with order determined by tab->minus
 	*/
 	free(padding_string);
	return (tab);
}


t_tab	*format(t_tab *tab)
{
	if (tab->width && (int)ft_strlen(tab->argument) < tab->width)
		format_padding(tab);
	else
	tab->padded_argument = ft_strdup(tab->argument);
	print_argument(tab);
	/*
	**	and fill with ' ' or '0' depending on flags
	**	then strjoin argument+padding_str with order determined by tab->minus
 	*/
	return (tab);
}

t_tab	*convert_int(t_tab *tab)
{
	int		i;

	i = va_arg(tab->args, int);
	tab->argument = ft_itoa(i);
	return (tab);
}

t_tab	*convert_unsigned_int(t_tab *tab)
{
	unsigned int	u;

	u = va_arg(tab->args, unsigned int);
	tab->argument = ft_unsigned_itoa(u);
	//tab->ret += ft_strlen(str);
	return (tab);
}

t_tab	*convert_ptr(t_tab *tab)
{
	char	*str;
	int		address;

	address = va_arg(tab->args, int);
	str = ft_itoa(address);
	return (tab);
}

t_tab	*convert_char(t_tab *tab)
{
	int c;

	c = va_arg(tab->args, int);
	tab->argument = malloc(sizeof(char) * 2);
	tab->argument[0] = c;
	tab->argument[1] = '\n';
	return (tab);
}

t_tab	*convert_string(t_tab *tab)
{
	tab->argument = va_arg(tab->args, char *);
	return (tab);
}

t_tab	*initialize(t_tab *tab)
{
	//tab->fcopy = (char *)tab->format;
	tab->i = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->width = 0;
	//tab->specifier = "cspdiuxX%";
	tab->ret = 0;
	return (tab);
}

t_tab	*get_width(t_tab *tab)
{
	int		end;
	char	*width_string;

	end = tab->i;
	while (ft_isdigit(tab->format[end]))
		end++;
	width_string = ft_substr(tab->format, tab->i, end - tab->i);
	tab->width = ft_atoi(width_string);
	free(width_string);
	tab->i = end;
	return (tab);
}

t_tab	*parse_specifier(t_tab *tab)
{
	if (tab->format[tab->i] == 'i')
	{
		tab->specifier = 'i';
		convert_int(tab);
	}
	if (tab->format[tab->i] == 'd')
	{
		tab->specifier = 'd';
		convert_int(tab);
	}
	if (tab->format[tab->i] == 'u')
	{
		tab->specifier = 'u';
		convert_unsigned_int(tab);
	}
	if (tab->format[tab->i] == 'c')
	{
		tab->specifier = 'c';
		convert_char(tab);
	}
	if (tab->format[tab->i] == 's')
	{
		tab->specifier = 's';
		convert_string(tab);
	}
	if (tab->format[tab->i] == 'p')
	{
		tab->specifier = 'p';
		convert_ptr(tab);
	}
	tab->i++;
	format_padding(tab);
	//print_argument(tab);
	return (tab);
}

t_tab	*parse_flags(t_tab *tab)
{
	tab->i++;
	if (tab->format[tab->i] == '-')
	{
		tab->minus = 1;
		tab->i++;
	}
	if (tab->format[tab->i] == '0')
	{
		tab->zero = 1;
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]))
		get_width(tab);
	parse_specifier(tab);
	return (tab);
}

int		parse(t_tab *tab)
{
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
			parse_flags(tab);
		else
		{
			write(1, &tab->format[tab->i], 1);
			tab->ret++;
			//tab->i++;
		}
		tab->i++;
	}
	return (tab->ret);
}

int		ft_printf(const char *format, ...)
{
	int			ret;
	t_tab		*tab;
	va_list		args;
	tab = malloc(sizeof(t_tab));
	if (!format || !tab)
		return (-1);
	tab->format = format;
	tab = initialize(tab);
	va_start(tab->args, format);
	tab->ret = parse(tab);
	va_end(args);
	ret = tab->ret;
	free(tab);
	return (ret);
}

int		main(void)
{
	char *str;
	char *str2;

	str = "testie test";
	str2 = "en nu?";
	ft_printf("%25i\n", -9000);
	return (0);
}