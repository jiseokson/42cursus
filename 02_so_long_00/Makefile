# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jison <jison@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:22:46 by jison             #+#    #+#              #
#    Updated: 2023/01/27 16:11:13 by jison            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

SRC = \
	$(shell find $(SRC_DIR) -name "*.c") \
	$(shell find $(FT_PRINTF_DIR) -name "*.c") \
	$(shell find $(GET_NEXT_LINE_DIR) -name "*.c")
OBJ = $(SRC:.c=.o)

HEADER = \
	$(shell find $(SRC_DIR) -name "*.h") \
	$(shell find $(FT_PRINTF_DIR) -name "*.h") \
	$(shell find $(GET_NEXT_LINE_DIR) -name "*.h")

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) $(HEADER)
	@$(CC) \
		-L$(MLX_DIR) -lmlx \
		-L$(LIBFT_DIR) -lft \
		-framework OpenGl \
		-framework AppKit \
		$(OBJ) \
		-o $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) \
		$(CFLAGS) \
		-I$(MLX_DIR) \
		-I$(LIBFT_DIR) \
		-I$(FT_PRINTF_DIR) \
		-I$(GET_NEXT_LINE_DIR) \
		-c $< \
		-o $@

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	@make clean
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
