# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 05:23:59 by gcadiou           #+#    #+#              #
#    Updated: 2017/01/15 02:28:13 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strcat.c     \
	  ft_strcpy.c     \
	  ft_strdup.c     \
	  ft_strlen.c     \
	  ft_strncat.c    \
	  ft_strncpy.c    \
	  ft_bzero.c      \
	  ft_memmove.c    \
	  ft_memcpy.c     \
	  ft_memccpy.c    \
	  ft_strsub.c     \
	  ft_putchar.c    \
	  ft_putstr.c     \
	  ft_putendl.c    \
	  ft_putnbr.c     \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c  \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c  \
	  ft_puterror.c         \
	  ft_strlentil.c        \
	  ft_realloc.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar -rc $(NAME) $(SRC:.c=.o)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
