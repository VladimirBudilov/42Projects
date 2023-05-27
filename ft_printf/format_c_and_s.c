/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_and_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:15:47 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 15:15:48 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_put_char(int ch)
{
	write(1, &ch, 1);
}

int	ft_print_char(int ch)
{
	ft_put_char(ch);
	return (1);
}

void	ft_put_str(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		ft_print_char(str[index]);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_put_str(str);
	return (ft_strlen(str));
}
