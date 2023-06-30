NAME	= philo

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

SRC_PATH = sources/
OBJ_PATH = objects/

SRC		= check_tools_1.c\
          check_tools_2.c\
          forks.c\
          main.c\
          main_tools.c\
          philosophers.c\
          thread.c\
          thread_inner_1.c\
          thread_inner_2.c\
          time.c\
          validation_tools_1.c\
          validation_tools_2.c


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/philosophers.h

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
