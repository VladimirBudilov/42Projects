/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_sorting_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:32:07 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:32:08 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (current->index > current->next->index)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

void	add_index(t_list **stack)
{
	t_list	*current;
	t_list	*sub_list;

	current = *stack;
	while (current != NULL)
	{
		current->index = 0;
		current = current->next;
	}
	current = *stack;
	while (current != NULL)
	{
		sub_list = *stack;
		while (sub_list != NULL)
		{
			if (current->content > sub_list->content)
				current->index += 1;
			sub_list = sub_list->next;
		}
		current = current->next;
	}
}
