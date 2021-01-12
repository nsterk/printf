# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 11:29:07 by nsterk        #+#    #+#                  #
#    Updated: 2021/01/12 14:46:35 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	libftprintf.h
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra

LIBFT_PATH	=	./libft/
LIBFT_SRC	= 	ft_atoi.c ft_bzero.c ft_calloc.c \
				ft_isspace.c ft_isdigit.c \
				ft_itoa_base.c ft_unsigned_itoa_base.c \
				ft_putchar_fd.c ft_putstr_fd.c \
				ft_memset.c \
				ft_strchr.c ft_strcmp.c \
				ft_strcpy.c ft_strlcpy.c \
				ft_strdup.c ft_strndup.c ft_strjoin.c \
				ft_strlen.c ft_substr.c
LIBFT_OBJ	=	$(LIBFT_SRC:%.c=%.o)
LIBFT_OP	=	$(LIBFT_OBJ:%=$(LIBFT_PATH)%)

PRINTF_SRC	=	initialize.c ft_printf.c \
				parse.c get_field_specs.c format.c \
				convert_alpha.c convert_int.c \
				convert_hex.c get_argument.c \
				re_initialize.c print.c
PRINTF_OBJ	=	$(PRINTF_SRC:%.c=%.o)

OBJ_FILES	=	$(PRINTF_OBJ) $(LIBFT_OP)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
		ar rs $(NAME) $(OBJ_FILES)

%.o: %.c	$(HEADER)
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		$(RM) $(OBJ_FILES)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus:		$(NAME)

.PHONY: all clean fclean re bonus
