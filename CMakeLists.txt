cmake_minimum_required(VERSION 3.23.2)
project(42GITS)

set(CMAKE_CXX_STANDARD 14)

include_directories(#[[Libft]] get_next_line)

add_executable(42GITS
        get_next_line/get_next_line_utils.c get_next_line/get_next_line.h Libft/ft_lstnew.c Libft/ft_lstadd_front.c Libft/ft_lstsize.c Libft/ft_lstlast.c Libft/ft_lstadd_back.c Libft/ft_lstdelone.c Libft/ft_lstiter.c Libft/ft_lstmap.c Libft/ft_lstclear.c
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_printf.h ft_printf/format_i_and_d.c ft_printf/format_c_and_s.c ft_printf/format_u.c ft_printf/format_x_and_X.c ft_printf/format_p.c)
