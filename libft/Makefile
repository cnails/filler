# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnails <cnails@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:40:03 by cnails            #+#    #+#              #
#    Updated: 2020/06/28 10:49:58 by cnails           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

FILES = ft_atoi.c ft_putchar.c ft_strlen.c \
		ft_putnbr.c ft_putstr.c ft_strcpy.c \
		ft_strdup.c ft_memset.c ft_bzero.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c \
		ft_strlcat.c ft_strchr.c ft_memcmp.c \
		ft_memchr.c ft_memmove.c ft_memccpy.c \
		ft_memcpy.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strcmp.c ft_strncmp.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c ft_filereader.c ft_isprime.c \
		ft_lennwords.c ft_getnwords.c get_next_line.c \
		ft_dtoa.c ft_strset.c ft_for.c ft_itoa_base.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c $(INC)
	@gcc -c  $< -I .
	@echo -n "."

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo ""

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft.a
re: fclean all
