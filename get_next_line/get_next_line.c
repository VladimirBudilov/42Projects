/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:12:22 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/29 21:12:30 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char		*line;
    static char	*remainder;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    remainder = ft_read_to_remainder(fd, remainder);
    if (!remainder)
        return (NULL);
    line = ft_get_line(remainder);
    remainder = ft_new_remainder(remainder);
    return (line);
}

#include "stdio.h"
int	main(void) {
    char *line;
    int i;
    int fd1;
    fd1 = open("text.txt", O_RDONLY);
    i = 1;
    while (i < 7) {
        line = get_next_line(fd1);
        printf("line [%02d]: %s", i, line);
        free(line);
        i++;
    }
    close(fd1);
    return (0);
}