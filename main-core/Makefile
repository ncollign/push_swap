# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 11:44:42 by ncollign          #+#    #+#              #
#    Updated: 2024/07/09 11:44:45 by ncollign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft 
LIBFT = ../libft/libft.a
SRCS = 	push_swap.c \
        utils/utils_exit.c \
        utils/utils_nodes.c \
        utils/utils_exit.c \
        utils/utils_sorting1.c \
        utils/utils_sorting2.c \
        sort_functions/push.c \
        sort_functions/reverse_rotate.c \
        sort_functions/rotate.c \
        sort_functions/swap.c \
        sort_functions/tiny_sort.c \
        sort_functions/big_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
