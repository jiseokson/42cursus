CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c eval.c operators.c operator_id.c ft_atoi.c print.c
OBJS = $(SRCS:.c=.o)

TARGET = do-op

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
