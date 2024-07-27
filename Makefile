# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS_DIR = main-core
SRCS = $(shell find $(SRCS_DIR) -name "*.c")
OBJS = $(SRCS:.c=.o)
INCLUDES = -I$(SRCS_DIR)
EXEC = push_swap

# Règles
all: $(LIBFT) $(EXEC)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c $(SRCS_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
