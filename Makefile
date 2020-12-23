# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 11:29:07 by nsterk        #+#    #+#                  #
#    Updated: 2020/12/21 13:36:12 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# dont forget to remove -g in CFLAGS 

NAME		=	libftprintf.a
HEADER		=	libftprintf.h
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra -g -Iinc

LIBFT_PATH	=	./libft/src/
LIBFT_SRC	= 	ft_atoi.c ft_bzero.c ft_calloc.c \
				ft_isspace.c ft_isdigit.c \
				ft_itoa.c ft_itoa_base.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c \
				ft_memcpy.c ft_memset.c \
				ft_strchr.c ft_strcmp.c ft_strncmp.c \
				ft_strcpy.c ft_strlcpy.c \
				ft_strdup.c ft_strndup.c ft_strjoin.c \
				ft_strlen.c ft_strnlen.c \
				ft_substr.c ft_tolower.c \
				ft_toupper.c ft_reverse_string.c \
				ft_unsigned_itoa_base.c
LIBFT_OBJ	=	$(LIBFT_SRC:%.c=%.o)

PRINTF_PATH	=	./src/
PRINTF_SRC	=	initialize.c ft_printf.c \
				parse.c get_field_specs.c format.c \
				convert_alpha.c convert_num.c \
				re_initialize.c print.c
PRINTF_OBJ	=	$(PRINTF_SRC:%.c=%.o)

PRINTF_OP	=	$(PRINTF_OBJ:%=$(PRINTF_PATH)%)
LIBFT_OP	=	$(LIBFT_OBJ:%=$(LIBFT_PATH)%)

OBJ_FILES	=	$(PRINTF_OP) $(LIBFT_OP)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
		ar rs $(NAME) $(OBJ_FILES)

%.o: %.c	$(HEADER)
		$(CC) -c $(CFLAGS) -o $@ $<

test: re
		$(CC) $(CFLAGS) main.c libftprintf.a -o printf
		./printf

clean:
		$(RM) $(OBJ_FILES)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus:
		$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus test bonustest
