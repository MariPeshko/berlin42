# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:32:51 by mpeshko           #+#    #+#              #
#    Updated: 2024/06/06 17:58:22 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

SRC	 = 		src/so_long.c \
			src/map_check.c \
			src/minilibx.c \
			src/img_tools.c \
			src/print_error.c \
			src/validate_path.c \
			src/utils.c \
			src/map.c \
			src/ft_init_values.c \
			src/hook.c
OBJ =		$(SRC:src/%.c=obj/%.o)
HDRS = 		src/so_long.h

LIBFT = 	libft/
LIB = 		libft/libft.a
GNL := 		get_next_line/*c
PRINTF = 	ft_printf/libftprintf.a

MLX_LIB = 	mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC =		cc
CFLAGS = 	-Wall -Wextra -Werror

all: $(NAME)
	@echo "SUCCESS!"

$(NAME): $(OBJ)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	@make -C $(LIBFT)
	@make -C ft_printf/
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) $(GNL) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

obj/%.o: src/%.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@printf "] "
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBFT)/*.o
	rm -rf ft_printf/sources/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	rm -f ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re