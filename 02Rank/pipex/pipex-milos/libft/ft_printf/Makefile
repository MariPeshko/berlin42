CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= libftprintf.a
HEADER	= ft_printf.h
SRC 	= ft_printf.c \
	  ft_printf_utils.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
