NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
SRCS = push_swap.c sort.c utils.c sort_functions/push.c sort_functions/reverse_rotate.c sort_functions/rotate.c sort_functions/swap.c
LIBFT = ../libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C ../libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re