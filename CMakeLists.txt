cmake_minimum_required(VERSION 3.23.2)
project(42GITS)

set(CMAKE_CXX_STANDARD 14)

include_directories(#[[Libft]] get_next_line)

add_executable(42GITS
        get_next_line/get_next_line_utils.c get_next_line/get_next_line.h Libft/ft_lstnew.c Libft/ft_lstadd_front.c Libft/ft_lstsize.c Libft/ft_lstlast.c Libft/ft_lstadd_back.c Libft/ft_lstdelone.c Libft/ft_lstiter.c Libft/ft_lstmap.c Libft/ft_lstclear.c Libft/get_next_line.c
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c)
