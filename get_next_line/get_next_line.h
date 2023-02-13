/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:12:49 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/29 21:12:53 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_remainder(int fd, char *remainder);
char	*ft_strchr(char *string, int chr);
char	*ft_strjoin(char *string, char *buff);
size_t	ft_strlen(char *string);
char	*ft_get_line(char *remainder);
char	*ft_new_remainder(char *remainder);

#endif
