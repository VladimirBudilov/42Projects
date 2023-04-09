/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:45:52 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:45:55 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*map_funk)(unsigned int, char))
{
	char			*str;
	unsigned int	index;

	index = 0;
	if (!string || !map_funk)
		return (0);
	str = ft_strdup(string);
	if (!str)
		return (0);
	while (str[index])
	{
		str[index] = map_funk(index, str[index]);
		index++;
	}
	return (str);
}
