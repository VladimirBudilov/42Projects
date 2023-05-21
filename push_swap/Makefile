NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g

SRC_PATH = sources/
OBJ_PATH = objects/
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC		=  butterfly_sort.c\
           butterfly_sort_tools.c\
           first_five_sort_functions.c\
           generic_stack_sorting_functions.c\
           generic_stak_functions.c\
           main.c\
           stack_a_funk.c\
           stack_b_funk.c\
           stak_both_functions.c\
           validation_tools.c\
           work_with_lists.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/push_swap.h

all: $(OBJ_PATH) $(NAME) $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_PATH)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
