CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRCS = srcs/main.c srcs/map.c srcs/bsq.c srcs/solve.c srcs/parse.c srcs/valid.c srcs/util.c srcs/io.c srcs/ft_print.c srcs/ft_string.c
OBJS = $(SRCS:.c=.o)

NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $< -I $(INC_DIR)

.PHONY: clean fclean re

clean:
	rm -f $(SRC_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
