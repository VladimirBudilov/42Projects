/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stak_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:13:44 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/20 14:13:47 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **source_stack, t_list **dest_stack)
{
	ft_lstadd_front(dest_stack, *source_stack);
	*source_stack = (*source_stack)->next;
}

void	reverse(t_list **stack)
{
	t_list	*prev_last;
	t_list	*current;

	prev_last = NULL;
	current = *stack;
	while (current->next != NULL)
	{
		prev_last = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	prev_last->next = NULL;
}

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*remaining;

	if (ft_lstsize(*stack) <= 1)
		return ;
	first = *stack;
	second = first->next;
	second->next = first;
	remaining = second->next;
	first->next = remaining;
	*stack = second;
}

void	rotate(t_list **stack)
{
	t_list	*prev_last;
	t_list	*current;

	prev_last = NULL;
	current = *stack;
	while (current->next != NULL)
	{
		prev_last = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	prev_last->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*temp_node;

	last_node = ft_lstlast(*stack);
	ft_lstadd_front(stack, last_node);
	temp_node = (*stack)->next;
	while (temp_node != NULL)
	{
		if (temp_node->next == last_node)
			temp_node->next = NULL;
		temp_node = temp_node->next;
	}
}
