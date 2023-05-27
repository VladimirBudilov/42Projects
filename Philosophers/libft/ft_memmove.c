/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:09:14 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:09:27 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t max_len)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	i = 0;
	dst = (unsigned char *) s1;
	src = (unsigned char *) s2;
	if (s1 < s2)
	{
		while (i++ < max_len)
			*dst++ = *src++;
	}
	else
	{
		while (max_len > 0)
		{
			dst[max_len - 1] = src[max_len - 1];
			max_len--;
		}
	}
	return (s1);
}
