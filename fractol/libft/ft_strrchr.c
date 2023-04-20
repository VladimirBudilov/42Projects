/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:51:10 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:51:13 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	str = (char *) s;
	i = ft_strlen(str);
	if (!str)
		return (0);
	while (str[j])
		j++;
	while (i >= 0)
	{
		if (str[j] == (char)c)
			return (str + j);
		i--;
		j--;
	}
	return (0);
}
