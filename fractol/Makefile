NAME = fractol

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = main.c events.c julia.c mandelbrot.c tools.c mini_libft.c

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
