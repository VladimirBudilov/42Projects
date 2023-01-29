/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:41:01 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 21:21:11 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t max_len)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			index;

	dst = (unsigned char *)str1;
	src = (unsigned char *)str2;
	index = 0;
	while (index < max_len)
	{
		dst[index] = src[index];
		index++;
	}
	return (str1);
}
