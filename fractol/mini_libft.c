/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:40:37 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/15 17:40:39 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	atof_core(char *str, t_res *res)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			res->result = res->result * 10.0 + (*str - '0');
			if (res->decimal)
				res->decimal_place /= 10.0;
		}
		else if (*str == '.')
			res->decimal = 1;
		else
			break ;
		str++;
	}
	res->result *= (res->sign);
	if (res->decimal)
		res->result *= res->decimal_place;
	return (res->result);
}

double	ft_atof(char *str)
{
	t_res	res;

	res.result = 0.0;
	res.sign = 1;
	res.decimal = 0;
	res.decimal_place = 1.0;
	res.result = atof_core (str, &res);
	return (res.result);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '.' || *str == '-')
		{
			str++;
			continue ;
		}
		return (0);
	}
	return (1);
}
