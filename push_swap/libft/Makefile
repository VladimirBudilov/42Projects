# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:51:55 by vbudilov          #+#    #+#              #
#    Updated: 2023/05/22 19:51:59 by vbudilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strrchr.c ft_strchr.c \
	   ft_calloc.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c \
		ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstclear.c   ft_lstadd_front.c


OBJ		= $(SRCS:.c=.o)
OBJ_PATH = objects/
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

CFLAGS = -Werror -Wextra -Wall

all: $(OBJ_PATH) $(NAME)

CC = cc

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
