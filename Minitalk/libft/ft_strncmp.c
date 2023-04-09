/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:47:47 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:47:49 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t max_size)
{
	size_t	index;

	if (max_size == 0)
		return (0);
	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0')
	{
		if (index < (max_size - 1))
			index++;
		else
			return (0);
	}
	return ((unsigned char)(s1[index]) - (unsigned char)(s2[index]));
}
