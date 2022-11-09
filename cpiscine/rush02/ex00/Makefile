CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = ./includes
SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = rush-02

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCS) -o $(<:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
