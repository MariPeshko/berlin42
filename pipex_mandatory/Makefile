# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 13:18:17 by mpeshko           #+#    #+#              #
#    Updated: 2024/06/27 15:23:15 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

SRCS :=		source/pipex_mandatory.c \
			source/call_cmd.c \
			source/errors.c \
			source/check_acces.c \
			source/check_run_or_not.c \
			source/wrapers.c \
			source/open_files.c \
		
OBJS :=		$(SRCS:source/%.c=obj/%.o)

HDRS := 	incl/pipex.h

LIBFT_DIR =	source/libft
LIBFT =		source/libft/libft.a

CC =		cc
# the flag -Iincl is used to specify an additional directory where the compiler
# should look for header files
CFLAGS =	-Wall -Wextra -Werror -Iincl

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)

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
obj/%.o: source/%.c $(HDRS)
	@mkdir -p $(@D)
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
