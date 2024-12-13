NAME = libftprintf.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# source files and objects
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# phony targets
.PHONY: all clean fclean re
