CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= pipex
SRCD	= ./source/
BONUSD	= ./bonus/
LIBFTD	= ./libft/
SRC 	= main.c \
	  piping.c \
	  utils.c \
	  liberators.c
BNAME	= pipex_bonus
BSRC 	= main_bonus.c \
	  piping_bonus.c \
	  childrenouter_bonus.c \
	  childrenmid_bonus.c \
	  utils_bonus.c \
	  liberators_bonus.c \
	  liberators_bonus2.c \
	  here_doc.c \
	  here_childrenouter_bonus.c

HEADER	= pipex.h
BHEADER	= pipex_bonus.h

all: libft $(NAME)

libft:
	make -sC $(LIBFTD) all

$(NAME): $(addprefix $(SRCD),$(SRC)) $(SRCD)$(HEADER)
	$(CC) $(CFLAGS) $(addprefix $(SRCD),$(SRC)) -I$(SRCD) -L$(LIBFTD) -lft -o $(NAME)

bonus: libft $(BNAME)

$(BNAME): $(addprefix $(BONUSD),$(BSRC)) $(BONUSD)$(BHEADER)
	$(CC) $(CFLAGS) $(addprefix $(BONUSD),$(BSRC)) -I$(BONUSD) -L$(LIBFTD) -lft -o $(BNAME)

clean:
	make -C $(LIBFTD) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(BNAME)
	make -C $(LIBFTD) fclean

re:	fclean all

.PHONY: all re clean fclean bonus libft
