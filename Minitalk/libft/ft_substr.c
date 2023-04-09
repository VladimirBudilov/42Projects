/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:53:38 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:53:42 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start,
		size_t len_for_new_string)
{
	char		*new_str;
	size_t		i;
	size_t		index_new_str;

	if (!string)
		return (0);
	if (ft_strlen(string) < len_for_new_string)
		len_for_new_string = ft_strlen(string);
	new_str = (char *)malloc(len_for_new_string + 1);
	if (!new_str)
		return (0);
	i = start;
	index_new_str = 0;
	while (i < ft_strlen(string) && index_new_str < len_for_new_string)
		new_str[index_new_str++] = string[i++];
	new_str[index_new_str] = '\0';
	return (new_str);
}
