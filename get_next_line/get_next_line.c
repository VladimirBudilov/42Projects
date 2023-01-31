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

char *ft_read (int fd)
{
	static char b[BUFFER_SIZE];
	int  i;
	int buf_len;
	char *temp1;
	char *temp2;
	char checker;

	i = 0;
	b[BUFFER_SIZE - 1] = '\0';
	read(fd, b, BUFFER_SIZE);
	buf_len = ft_strlen(b);
	temp1 = (char *) malloc(buf_len+1)
	if(b[BUFFER_SIZE] != '\n')
		while (b[i] != '\n' || b[i] != '\0' || i < buf_len)
		{

			i++;
		}
}


int main ()
{
	int	fd;

	fd = open("./test1.txt", O_RDONLY);
	printf("%s", ft_read(fd));
	printf("%s", ft_read(fd));
	printf("%s", ft_read(fd));
	printf("%s", ft_read(fd));
	close(fd);
	return (1);
}
