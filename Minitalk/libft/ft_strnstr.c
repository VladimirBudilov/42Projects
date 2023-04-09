/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:48:49 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:48:51 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t max_size)
{
	size_t	str_index;
	size_t	tofind_index;

	str_index = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (str[str_index])
	{
		tofind_index = 0;
		while (str[str_index + tofind_index] == to_find[tofind_index]
			&& (str_index + tofind_index) < max_size)
		{
			if (str[str_index + tofind_index] == '\0'
				&& to_find[tofind_index] == '\0')
				return ((char *)&str[str_index]);
			tofind_index++;
		}
		if (to_find[tofind_index] == '\0')
			return ((char *)&str[str_index]);
		str_index++;
	}
	return (0);
}
