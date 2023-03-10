/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:30:24 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:30:36 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	char	c;

	c = (char )ch;
	while (*str && c != *str)
		str++;
	if (c == *str)
		return ((char *)str);
	return (0);
}
