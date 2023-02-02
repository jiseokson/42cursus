CC = cc
CFLAGS = -Wall -Wextra -Werror

MAND_SRCS = \
ft_atoi.c       ft_itoa.c       ft_memmove.c    ft_split.c      ft_strjoin.c    ft_strmapi.c    ft_strtrim.c \
ft_bzero.c      ft_memchr.c     ft_memset.c     ft_strchr.c     ft_strlcat.c    ft_strncmp.c    ft_substr.c \
ft_calloc.c     ft_memcmp.c     ft_put_fd.c     ft_strdup.c     ft_strlcpy.c    ft_strnstr.c    ft_tochr.c \
ft_ctype.c      ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strlen.c     ft_strrchr.c
BONUS_SRCS = \
ft_lstadd_back_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c	ft_lstmap_bonus.c	ft_lstsize_bonus.c \
ft_lstadd_front_bonus.c	ft_lstdelone_bonus.c	ft_lstlast_bonus.c	ft_lstnew_bonus.c

MAND_OBJS = $(MAND_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = libft.a

ifdef BONUS
	ALL_OBJS = $(MAND_OBJS) $(BONUS_OBJS)
else
	ALL_OBJS = $(MAND_OBJS)
endif

$(NAME): $(ALL_OBJS)
	@ar cr $(NAME) $^

bonus:
	@make BONUS=1 $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@rm -rf $(MAND_OBJS) $(BONUS_OBJS)

fclean:
	@make clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all, clean, fclean, re, bonus
