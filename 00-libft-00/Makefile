CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find . -name ft_*.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a

$(NAME): $(OBJS)
	ar cr -o $@ $(OBJS)

%.o: %.c:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
