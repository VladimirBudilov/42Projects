
NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a

SRC = ft_fractol.c \
	julia.c \
	complex_math.c \
	hooks.c \
	mandelbrot.c \
	params.c \


all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./libft

	$(MAKE) --no-print-directory -C ./minilibx-linux

	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)


clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SRC:.c=.o)


fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)


re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT:
