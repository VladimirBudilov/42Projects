/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:38:20 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 21:48:20 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*arr;

	arr = (char *)malloc(size * number);
	if (!arr)
		return (0);
	ft_memset(arr, 0, (size * number));
	return (arr);
}
