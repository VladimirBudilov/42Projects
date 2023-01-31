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

#ifndef INC_42GITS_GET_NEXT_LINE_H
#define INC_42GITS_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
#include "stdlib.h"
# include "unistd.h"
# include <sys/fcntl.h>

char    *get_next_line(int fd);
static  int	count_words(const char *str, char separator);
static  char	*word_dup(const char *str, int start, int finish);
char	**ft_split(char const *s1, char separator);
int     ft_strlen(char *str);

#endif //INC_42GITS_GET_NEXT_LINE_H
