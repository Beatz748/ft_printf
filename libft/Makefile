# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 20:37:26 by hwindom           #+#    #+#              #
#    Updated: 2020/05/30 05:42:54 by hwindom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_itoa.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_split.c


OSRCS = *.o


all: $(NAME)

$(NAME):
	gcc $(CFLAGS)  $(SRCS) \
		&& ar rc $(NAME) $(OSRCS) \
		&& ranlib $(NAME)

clean: 
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
