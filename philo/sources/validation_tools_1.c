/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_tools_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:53:16 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 15:53:18 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/philosophers.h"

int	ft_isdigit(char i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

long long int	ft_atoi(char *string)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (string[i] == '-')
		sign = -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		res = res * 10 + string[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}
