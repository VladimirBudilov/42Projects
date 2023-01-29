/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:25:25 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:25:28 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *input_str, int fd)
{
	int	index;

	index = 0;
	if (!input_str)
		return ;
	if (fd < 0)
		return ;
	while (input_str[index])
	{
		ft_putchar_fd(input_str[index], fd);
		index++;
	}
}
