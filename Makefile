# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 13:41:41 by fbenini-          #+#    #+#              #
#    Updated: 2025/10/23 16:56:47 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/

CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/main.c \
	   ./src/initializers.c \
	   ./src/swap_functions.c \
	   ./src/push_functions.c \
	   ./src/validate.c \
	   ./src/rotate_functions.c \
	   ./src/sort_small.c \
	   ./src/stack_finders.c \
	   ./src/turk_helpers.c \
	   ./src/turk_sort.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
