/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i_and_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:14:06 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:08 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	nbr_len(int nbr)
{
	int	str_len;

	if (nbr >= 0)
		str_len = 0;
	else
		str_len = 1;
	if (nbr == 0 || !nbr)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		str_len++;
	}
	return (str_len);
}

void	ft_put_nbr(int input_nbr)
{
	unsigned int	nbr;
	unsigned int	temp_nbr;

	temp_nbr = (unsigned int) input_nbr;
	if (input_nbr < 0)
	{
		ft_print_char('-');
		nbr = temp_nbr * -1;
	}
	else
		nbr = temp_nbr;
	if (nbr >= 10)
		ft_put_nbr(nbr / 10);
	ft_print_char((char)(nbr % 10 + 48));
}

int	ft_print_nbr(int input_nbr)
{
	int	str_len;

	str_len = 0;
	ft_put_nbr(input_nbr);
	str_len = nbr_len(input_nbr);
	return (str_len);
}
