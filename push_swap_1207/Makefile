# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 18:52:11 by mpeshko           #+#    #+#              #
#    Updated: 2024/07/04 16:00:25 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

SRCS :=		source/push_swap/main.c  \
			source/push_swap/input_parsing.c \
			source/push_swap/input_atoi2.c \
			source/push_swap/input_dup_search.c \
			source/push_swap/sort_main.c \
			source/push_swap/sort_check_a.c \
			source/push_swap/sort_three.c \
			source/push_swap/algor_a_to_b.c \
			source/push_swap/algor_b_to_a.c \
			source/push_swap/utils_linked_lst.c \
			source/push_swap/utils_nbr_place.c \
			source/push_swap/operations00.c \
			source/push_swap/operations01.c \
			source/push_swap/operations02.c \
			source/push_swap/ft_error.c \
			source/push_swap/ft_free.c \

OBJS :=		$(SRCS:source/push_swap/%.c=obj/%.o)

HDRS := 	includes/push_swap.h

LIBFT_DIR =	source/libft
LIBFT =		source/libft/libft.a

CC =		cc
# the flag -Iincl is used to specify an additional directory where the compiler
# should look for header files
CFLAGS =	-Wall -Wextra -Werror -Iincl -g

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)
	@echo "SUCCESS!"

# Target $(NAME) depends on object files $(OBJS) and libft library.
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\nNAME: OBJS - SUCCESS!\n"

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header file (incl/project.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
obj/%.o: source/push_swap/%.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@printf "] "
	@$(CC) $(CFLAGS) -c -o $@ $<

# Target to remove all generated files.
clean:
	@rm -rf $(OBJS)
	rm -rf obj/
	rm -rf $(LIBFT_DIR)/*.o

# Target to remove all generated files and the program executable.
fclean:	clean
	rm -f $(LIBFT)
	@rm -f $(NAME)

# Target 're' depends on 'fclean' and 'all', rebuilding the project from scratch.
re:	fclean all

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them as files.
.PHONY: all clean fclean re