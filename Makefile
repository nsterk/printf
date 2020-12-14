# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 11:29:07 by nsterk        #+#    #+#                  #
#    Updated: 2020/12/14 13:14:11 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	libftprintf.h
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra -Iinc

LIBFT_PATH	=	./libft/src/
LIBFT_SRC	= 	ft_atoi.c ft_bzero.c ft_calloc.c \
				ft_isspace.c ft_isdigit.c \
				ft_itoa.c ft_itoa_base.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c \
				ft_memcpy.c ft_memset.c \
				ft_strchr.c ft_strcmp.c ft_strcpy.c \
				ft_strdup.c ft_strndup.c ft_strjoin.c \
				ft_strlcpy.c ft_strlen.c ft_strnlen.c \
				ft_substr.c ft_tolower.c \
				ft_toupper.c ft_reverse_string.c \
				ft_unsigned_itoa_base.c
LIBFT_OBJ	=	$(LIBFT_SRC:%.c=%.o)

PRINTF_PATH	=	./src/
PRINTF_SRC	=	initialize.c ft_printf.c \
				parse.c format.c \
				get_width.c get_precision.c \
				convert_alpha.c convert_num.c \
				re_initialize.c print.c 
PRINTF_OBJ	=	$(PRINTF_SRC:%.c=%.o)

PRINTF_OP	= $(PRINTF_OBJ:%=$(PRINTF_PATH)%)
LIBFT_OP	= $(LIBFT_OBJ:%=$(LIBFT_PATH)%)

O_FILES		= $(PRINTF_OP) $(LIBFT_OP)

all:		$(NAME)

$(NAME):	$(O_FILES)
		ar rs $(NAME) $(O_FILES)

%.o: %.c	$(HEADER)
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		$(RM) $(O_FILES)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
