/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_tools(part3).c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:54:46 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:54:48 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_validate_atoi(const char *str)
{
	int				index;
	long long int	sign;
	long long int	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - '0');
		index++;
		if (check_overflow(res, sign))
			return (0);
	}
	return (1);
}

int	check_overflow(long long int res, long long int sign)
{
	if (res * sign > INT_MAX)
		return (1);
	if (res * sign < INT_MIN)
		return (1);
	return (0);
}
