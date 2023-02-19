/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:33:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 15:33:23 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_uns_nbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_put_uns_nbr(nbr / 10);
	ft_print_char((char)(nbr % 10 + 48));
}

int	nbr_uns_len(unsigned int nbr)
{
	int	str_len;

	str_len = 0;
	if (nbr == 0 || !nbr)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		str_len++;
	}
	return (str_len);
}

int	ft_print_uns_nbr(unsigned int input_nbr)
{
	int	str_len;

	str_len = 0;
	ft_put_uns_nbr(input_nbr);
	str_len = nbr_uns_len(input_nbr);
	return (str_len);
}
