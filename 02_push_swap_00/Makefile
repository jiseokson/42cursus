# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jison <jison@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:37:05 by jison             #+#    #+#              #
#    Updated: 2023/01/17 16:16:54 by jison            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAND_SRCS = \
	cmd.c \
	cmd_push.c \
	cmd_reverse_rotate.c \
	cmd_rotate.c \
	cmd_swap.c \
	cycle.c \
	cycle_op.c \
	ft_atol.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_print.c \
	ft_split.c \
	ft_strlen.c \
	ft_substr.c \
	get_cycle.c \
	handle_error.c \
	push_swap.c \
	quick_sort.c \
	sort.c \
	sort_mini.c \
	sort_mini2.c \
	sort_utils.c \
	utils.c \
	sort_mini_por.c
MAND_OBJS = $(MAND_SRCS:.c=.o)

BONUS_SRCS = \
	checker_bonus.c \
	cmd.c \
	cmd_push.c \
	cmd_reverse_rotate.c \
	cmd_rotate.c \
	cmd_swap.c \
	cycle.c \
	cycle_op.c \
	ft_atol.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_print.c \
	ft_split.c \
	ft_strlen.c \
	ft_substr.c \
	get_cycle.c \
	get_next_line.c \
	handle_error.c \
	utils.c \
	sort_utils.c \
	quick_sort.c \
	ft_gnl_substr.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS = checker

NAME = push_swap

all: $(NAME)

$(NAME): $(MAND_OBJS)
	$(CC) $(CFLAGS) -o $@ $(MAND_OBJS)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(MAND_OBJS)
	rm -rf $(BONUS_OBJS)

fclean:
	make clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re:
	make fclean
	make all

.PHONY: clean, fclean, all
