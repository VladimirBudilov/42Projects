# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 18:56:15 by vbudilov          #+#    #+#              #
#    Updated: 2023/05/22 18:56:17 by vbudilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g

SRC_PATH = sources/
OBJ_PATH = objects/

SRC		= forks.c\
          main.c\
          main_tools.c\
          philosophers.c\
          tests.c\
          thread.c\
          thread_inner.c\
          time.c\
          validation_tools_part1.c


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/push_swap.h

all: $(OBJ_PATH) $(NAME) $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
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
