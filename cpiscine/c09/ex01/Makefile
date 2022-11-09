CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./includes
SRC_DIR = ./srcs

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar cr $(TARGET) $(OBJS)

srcs/ft_putchar.o: srcs/ft_putchar.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC_DIR)

srcs/ft_swap.o: srcs/ft_swap.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC_DIR)

srcs/ft_putstr.o: srcs/ft_putstr.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC_DIR)

srcs/ft_strlen.o: srcs/ft_strlen.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC_DIR)

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC_DIR)

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
