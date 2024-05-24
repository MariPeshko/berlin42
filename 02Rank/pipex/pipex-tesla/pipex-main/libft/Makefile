# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 20:01:54 by astavrop          #+#    #+#              #
#    Updated: 2023/11/27 16:58:59 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
NAME =			libft.a

SRC_FILES =		ft_memset.c ft_memcpy.c ft_memmove.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS =			$(SRC_FILES:.c=.o)

BONUS_FILES =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
BONUS_OBJS =	$(BONUS_FILES:.c=.o)

all: $(NAME)

.DEFAULT_GOAL := all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $?

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
