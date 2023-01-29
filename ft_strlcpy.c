/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:40:34 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:40:37 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *str1, const char *str2, size_t max_size)
{
	size_t			index;
	size_t			src_size;

	index = 0;
	src_size = ft_strlen(str2);
	if (!str1 || !str2)
		return (0);
	if (max_size == 0)
		return (src_size);
	while (str2[index] && index < max_size - 1)
	{
		str1[index] = str2[index];
		index++;
	}
	str1[index] = '\0';
	return (src_size);
}
