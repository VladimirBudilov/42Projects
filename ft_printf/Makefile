SRCS = 	ft_printf.c format_c_and_s.c format_i_and_d.c format_p.c format_u.c format_x_and_X.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall

NAME =  libftprintf.a

all: $(NAME)

CC = cc

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all