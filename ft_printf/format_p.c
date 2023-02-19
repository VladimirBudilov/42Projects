/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:41:58 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 16:42:02 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_len(unsigned long long ptr)
{
	int	str_len;

	str_len = 0;
	if (ptr == 0 || !ptr)
		return (1);
	while (ptr != 0)
	{
		ptr /= 16;
		str_len++;
	}
	return (str_len);
}

void	ft_put_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_pointer(ptr / 16);
		ptr %= 16;
	}
	if (ptr <= 9)
		ft_put_char(ptr + '0');
	else
		ft_put_char(ptr - 10 + 'a');
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	str_len;

	str_len = 0;
	str_len += write(1, "0x", 2);
	if (ptr == 0)
		str_len += write(1, "0", 1);
	else
	{
		ft_put_pointer(ptr);
		str_len += ft_pointer_len(ptr);
	}
	return (str_len);
}
