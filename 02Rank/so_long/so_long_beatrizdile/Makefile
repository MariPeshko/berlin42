# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by bedos-sa          #+#    #+#              #
#    Updated: 2024/06/04 13:48:27 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
XFLAGS =  -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT = ./libft
RM = rm -f
FILES = srcs/main.c \
		srcs/minilibx.c \
		srcs/handles.c \
		srcs/validation.c \
		srcs/error_characters.c \
		srcs/error_map_name.c \
		srcs/error_rectangular.c \
		srcs/error_map_path.c \
		srcs/keypress.c
OBJS = $(FILES:.c=.o)

all: $(NAME)
	@echo "SUCCESS!"

%.o: %.c include/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)

bonus: all

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus