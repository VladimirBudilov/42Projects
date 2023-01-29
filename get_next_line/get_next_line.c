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
	static char b[10];
	static int  i;

	b[9] = '\0';
	rea     d(fd, b, 4);

	return (b);

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
