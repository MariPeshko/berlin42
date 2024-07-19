# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 13:18:17 by mpeshko           #+#    #+#              #
#    Updated: 2024/06/29 20:14:03 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	source/pipex.c \
				source/pipex_here_doc.c \
				source/call_cmd.c \
				source/errors.c \
				source/check_cmd_acces.c \
				source/wrapers.c \
				source/open_files.c \
				source/utils_bonus.c \
				source/get_next_line.c \
				source/get_next_line_utils.c
OBJDIR		=	obj
OBJS		=	$(SRCS:source/%.c=$(OBJDIR)/%.o)
MAIN		=	srcs/pipex.c

HDRS		= 	incl/pipex.h

LIBFT_DIR	=	source/libft
LIBFT		=	source/libft/libft.a

CC			=	cc
# the flag -Iincl is used to specify an additional directory where the compiler
# should look for header files
CFLAGS		=	-Wall -Wextra -Werror -Iincl -g

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS) and libft library.
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ${NAME}

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header file (incl/project.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
$(OBJDIR)/%.o: source/%.c $(HDRS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS)
	rm -rf obj/
	rm -rf $(LIBFT_DIR)/*.o

fclean:	clean
	rm -f $(LIBFT)
	@rm -f $(NAME)

re:	fclean all

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them
# as files.
.PHONY: all clean fclean re
