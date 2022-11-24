CC = cc
CFLAGS = -Wall -Wextra -Werror

MAND_SRCS = \
./mand/conversion.c\
./mand/ft_memcpy.c\
./mand/ft_print_c.c\
./mand/ft_print_d.c\
./mand/ft_print_form.c\
./mand/ft_print_i.c\
./mand/ft_print_p.c\
./mand/ft_print_percentage.c\
./mand/ft_print_s.c\
./mand/ft_print_u.c\
./mand/ft_print_x.c\
./mand/ft_print_x_upper.c\
./mand/ft_printf.c\
./mand/ft_strdup.c\
./mand/ft_strtol.c\
./mand/utils.c

BONUS_SRCS = \
./bonus/conversion_bonus.c\
./bonus/ft_memcpy_bonus.c\
./bonus/ft_print_c_bonus.c\
./bonus/ft_print_d_bonus.c\
./bonus/ft_print_form_bonus.c\
./bonus/ft_print_i_bonus.c\
./bonus/ft_print_p_bonus.c\
./bonus/ft_print_percentage_bonus.c\
./bonus/ft_print_s_bonus.c\
./bonus/ft_print_u_bonus.c\
./bonus/ft_print_x_bonus.c\
./bonus/ft_print_x_upper_bonus.c\
./bonus/ft_printf_bonus.c\
./bonus/ft_strdup_bonus.c\
./bonus/ft_strtol_bonus.c\
./bonus/utils_bonus.c

NAME = libftprintf.a

ifdef BONUS
	OBJS = $(BONUS_SRCS:.c=.o)
else
	OBJS = $(MAND_SRCS:.c=.o)
endif

$(NAME): $(OBJS)
	ar cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

all: $(NAME)

bonus:
	make BONUS=1 all

clean:
	rm -rf $(MAND_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re, bonus