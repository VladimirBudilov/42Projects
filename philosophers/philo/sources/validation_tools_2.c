/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_tools_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:53:30 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 15:53:31 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_not_validate_args(int argc, char **string)
{
	if (argc < 5 || argc > 6)
	{
		ft_error();
		return (1);
	}
	if (!is_valid(string[1]) || !is_valid(string[2])
		|| !is_valid(string[3]) || !is_valid(string[4]))
	{
		ft_error();
		return (1);
	}
	if (argc == 6 && !is_valid(string[5]))
	{
		ft_error();
		return (1);
	}
	if (argc == 6 && ft_atoi(string[5]) <= 0)
	{
		ft_error();
		return (1);
	}
	return (0);
}

int	is_valid(char *string)
{
	if (!ft_strisdigit(string))
		return (0);
	if (ft_atoi(string) <= 0)
		return (0);
	return (1);
}

int	ft_strisdigit(char *string)
{
	if (!*string)
		return (0);
	if (*string == '-' && *(string + 1) == '\0')
		return (0);
	if (*string == '-')
		return (0);
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}
