# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 18:05:00 by mpeshko           #+#    #+#              #
#    Updated: 2024/06/09 17:10:24 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

SRCS :=		source/main.c \
			source/pipeline.c \
			source/call_cmd.c \
			source/utils.c
OBJS :=		$(SRCS:source/%.c=obj/%.o)

HDRS := 	incl/pipex.h

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
	@echo "\nNAME: OBJ - SUCCESS!\n"

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header file (incl/project.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
obj/%.o: source/%.c $(HDRS)
	@mkdir -p $(@D)
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@printf "] "
	@$(CC) $(CFLAGS) -c -o $@ $<

# Target to remove all generated files.
clean:
	@rm -rf $(OBJS)
	rm -rf $(LIBFT_DIR)/*.o

# Target to remove all generated files and the program executable.
fclean:	clean
	rm -f $(LIBFT)
	@rm -f $(NAME)

# Target 're' depends on 'fclean' and 'all', rebuilding the project from scratch.
re:	fclean all

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them as files.
.PHONY: all clean fclean re
