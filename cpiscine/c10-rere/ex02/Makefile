CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find . -name "*.c") 
OBJS = $(SRCS:.c=.o)

TARGET = ft_tail

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
