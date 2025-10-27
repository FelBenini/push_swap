# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 13:41:41 by fbenini-          #+#    #+#              #
#    Updated: 2025/10/27 12:20:28 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

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

CHECKER_SRCS = ./checker_src/main_bonus.c \
			   ./checker_src/validate_bonus.c \
			   ./checker_src/initializers_bonus.c \
			   ./checker_src/push_bonus.c \
			   ./checker_src/swap_bonus.c \
			   ./checker_src/rotate_bonus.c

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -L$(LIBFT_DIR) -lft -o $(CHECKER)

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

bonus: $(CHECKER)

.PHONY: all clean fclean re bonus
