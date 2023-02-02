# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jison <jison@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:43:11 by jison             #+#    #+#              #
#    Updated: 2023/02/02 13:02:24 by jison            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

HEADER = \
	$(shell find $(SRC_DIR) -type f -name "*.h") \
	$(shell find $(FT_PRINTF_DIR) -type f -name "*.h") \
	$(shell find $(GET_NEXT_LINE_DIR) -type f -name "*.h")

SRC = \
	$(shell find $(SRC_DIR) -type f -name "*.c") \
	$(shell find $(FT_PRINTF_DIR) -type f -name "*.c") \
	$(shell find $(GET_NEXT_LINE_DIR) -type f -name "*.c")
OBJ = $(SRC:.c=.o)

$(NAME): $(LIBFT) $(HEADER) $(OBJ)
	@$(CC) \
		-L$(LIBFT_DIR) -lft\
		$(OBJ) \
		-o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

%.o: %.c
	@$(CC) \
		$(CFLAGS) \
		-I$(LIBFT_DIR) \
		-I$(FT_PRINTF_DIR) \
		-I$(GET_NEXT_LINE_DIR) \
		-c $< \
		-o $@

all: $(NAME)

bonus: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@make clean
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
