CC = cc
CFLAGS := -Wall -Wextra -Werror -g
NAME := libft.a
LIBFTPRINTFD := ./ft_printf
GNLD := ./get_next_line
HEADER = libft.h
SRC :=	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_iswhite.c \
	ft_isplusminus.c \
	ft_isintmacro.c \
	ft_isprime.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstintpos.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstbypass.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPRINTFD) all
	make -C $(GNLD) all
	find $(LIBFTPRINTFD) -name "*.o" -exec cp {} . \;
	find $(GNLD) -name "*.o" -exec cp {} . \;
	ar rcs $(NAME) *.o

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	make -C $(LIBFTPRINTFD) clean
	make -C $(GNLD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPRINTFD) fclean
	make -C $(GNLD) fclean

re: fclean all

.PHONY: all clean fclean re
