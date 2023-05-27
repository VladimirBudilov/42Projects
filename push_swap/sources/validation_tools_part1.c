/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:39:54 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:39:56 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid(char *string, t_list **stack)
{
	if (!ft_strisdigit(string))
	{
		ft_error(stack);
		return (0);
	}
	if (!is_valid_number(string))
	{
		ft_error(stack);
		return (0);
	}
	return (1);
}

int	ft_strisdigit(char *string)
{
	if (!*string)
		return (0);
	if (*string == '-' && *(string + 1) == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}

int	is_valid_number(char *string)
{
	if (is_validate_atoi(string))
		return (1);
	else
		return (0);
}

int	has_repeat(t_list **stack)
{
	t_list	*current_node;
	t_list	*compare_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		compare_node = current_node->next;
		while (compare_node != NULL)
		{
			if (compare_node->content == current_node->content)
			{
				ft_error(stack);
				return (1);
			}
			compare_node = compare_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}
