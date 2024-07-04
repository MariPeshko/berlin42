# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 13:18:17 by mpeshko           #+#    #+#              #
#    Updated: 2024/06/27 19:36:07 by mpeshko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
NAME_B		= pipex_bonus

SRCS		=	source/pipex.c \
				source/call_cmd.c \
				source/errors.c \
				source/check_acces.c \
				source/check_run_or_not.c \
				source/wrapers.c \
				source/open_files.c
OBJDIR		=	obj
OBJS		=	$(SRCS:source/%.c=$(OBJDIR)/%.o)
MAIN		=	srcs/pipex.c

SRCS_B		=	source/pipex_bonus.c \
				source/call_cmd.c \
				source/errors.c \
				source/check_acces.c \
				source/check_run_or_not.c \
				source/wrapers.c \
				source/open_files.c \
				source/utils_bonus.c
OBJDIR_B	=	obj_b
OBJS_B		=	$(SRCS_B:source/%.c=$(OBJDIR_B)/%.o)
MAIN_B		=	srcs/pipex_bonus.c

HDRS	= 	incl/pipex.h

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ${NAME}
	@echo "\nNAME: OBJS - SUCCESS!\n"

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header file (incl/project.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
$(OBJDIR)/%.o: source/%.c $(HDRS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR_B)/%.o: source/%.c $(HDRS)
	@mkdir -p $(OBJDIR_B)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus:		${NAME_B}

${NAME_B}:	${OBJS_B}
	$(CC) $(CFLAGS) ${OBJS_B} $(LIBFT) -o ${NAME_B}

clean:
	@rm -rf $(OBJS)
	rm -rf ${OBJS_B}
	rm -rf obj/
	rm -rf obj_b/
	rm -rf $(LIBFT_DIR)/*.o

fclean:	clean
	rm -f $(LIBFT)
	@rm -f $(NAME)
	rm -f $(NAME_B)

re:	fclean all

re_bonus:	fclean bonus

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them
# as files.
.PHONY: all clean fclean re re_bonus bonus
