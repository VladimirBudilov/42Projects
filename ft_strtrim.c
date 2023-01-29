/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:52:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:52:23 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *trim_char)
{
	size_t	len;
	char	*dst;

	if (!str || !trim_char)
		return (NULL);
	while (*str && ft_strchr(trim_char, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(trim_char, str[len]))
		len--;
	dst = ft_substr(str, 0, len + 1);
	return (dst);
}
