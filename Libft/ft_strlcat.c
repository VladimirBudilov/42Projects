/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:39:31 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:39:37 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t max_size)
{
	size_t	src_index;
	size_t	dst_index;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	src_index = 0;
	dst_index = dst_len;
	if (dst_len >= max_size)
		return (max_size + ft_strlen(src));
	while (src[src_index] && (dst_len + src_index) < max_size - 1)
	{
		dest[dst_index] = src[src_index];
		dst_index++;
		src_index++;
	}
	dest[dst_index] = 0;
	return (dst_len + src_len);
}
