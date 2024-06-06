# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:32:51 by mpeshko           #+#    #+#              #
#    Updated: 2024/05/27 16:12:34 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

SRC	 = 		src/so_long.c \
			src/utils.c \
			src/img_tools.c \
			src/parser.c \
			src/validate_path.c \
			src/utils2.c
OBJ =		$(SRC:src/%.c=obj/%.o)
HDRS = 		src/so_long.h

LIBFT = 	libft/
LIB = 		libft/libft.a
GNL := 		get_next_line/*c
PRINTF = 	printf/libftprintf.a

MLX_LIB = 	mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC =		cc
CFLAGS = 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	@make -C $(LIBFT)
	@make -C printf/
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) $(GNL) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

obj/%.o: src/%.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@printf "] "
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBFT)/*.o
	rm -rf printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	rm -f printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re