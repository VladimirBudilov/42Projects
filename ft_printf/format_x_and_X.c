/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_and_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:34:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 15:34:23 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_len( unsigned int nbr)
{
	int	str_len;

	str_len = 0;
	if (nbr == 0 || !nbr)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		str_len++;
	}
	return (str_len);
}

void	ft_put_hex(unsigned int nbr, char format)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, format);
		nbr %= 16;
	}
	if (nbr <= 9)
		ft_put_char(nbr + '0');
	else
	{
		if (format == 'x')
			ft_put_char(nbr - 10 + 'a');
		else if (format == 'X')
			ft_put_char(nbr - 10 + 'A');
	}
}

int	ft_print_hex(unsigned int nbr, char format)
{
	int	str_len;

	str_len = 0;
	ft_put_hex(nbr, format);
	str_len = ft_hex_len(nbr);
	return (str_len);
}
