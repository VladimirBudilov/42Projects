/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:23:45 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:23:55 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int input_nbr, int fd)
{
	unsigned int	nbr;
	unsigned int	temp_nbr;

	temp_nbr = (unsigned int) input_nbr;
	if (input_nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = temp_nbr * -1;
	}
	else
		nbr = temp_nbr;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}
