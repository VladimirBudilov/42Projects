/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:59:10 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:01:04 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t max_len)
{
	unsigned char	*string;
	size_t			index;

	string = (unsigned char *)str;
	index = 0;
	while (index++ < max_len)
	{
		if (*string == (unsigned char)c)
			return ((void *)string);
		string++;
	}
	return (0);
}
