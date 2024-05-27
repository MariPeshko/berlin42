# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by bedos-sa          #+#    #+#              #
#    Updated: 2023/07/24 20:24:12 by bedos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
XFLAGS =  -lmlx -lXext -lX11
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