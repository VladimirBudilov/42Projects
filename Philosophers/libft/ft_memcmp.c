/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:01:49 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:03:04 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t max_len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			index;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	index = 0;
	while (index < max_len)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}
