NAME = server
NAME1 = client
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME) $(NAME1) 

$(NAME): server.o 
	$(CC) -o $@ $< -Llibft -lft

$(NAME1): client.o 
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
