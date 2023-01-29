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

char	*ft_strrchr(const char *input_str, int c)
{
	int			str_len;
	const char	*str;
	const char	*rev_str;
	char		ch;

	ch = (char)c;
	str = input_str;
	str_len = ft_strlen(input_str);
	rev_str = (input_str + str_len);
	while (*rev_str != *str && ch != *rev_str)
		rev_str--;
	if (ch == *rev_str)
		return ((char *)rev_str);
	return (0);
}
