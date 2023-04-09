/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:18:55 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:19:06 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *res, int ch, size_t max_len)
{
	size_t			index;
	unsigned char	*str;

	str = (unsigned char *)res;
	index = 0;
	while (index < max_len)
	{
		str[index] = (unsigned char)ch;
		index++;
	}
	return (res);
}
