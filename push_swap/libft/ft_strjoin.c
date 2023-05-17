/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:34:46 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:34:52 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		s1_index;
	int		s2_index;

	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (0);
	s1_index = 0;
	while (s1[s1_index] != '\0')
	{
		new_str[s1_index] = s1[s1_index];
		s1_index++;
	}
	s2_index = 0;
	while (s2[s2_index] != '\0')
		new_str[s1_index++] = s2[s2_index++];
	new_str[s1_index] = '\0';
	return (new_str);
}
