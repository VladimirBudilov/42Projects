/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_functions.c                          :+:      :+:    :+:   */
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
	t_list	*temp;

	temp = *source_stack;
	*source_stack = (*source_stack)->next;
	temp->next = *dest_stack;
	*dest_stack = temp;
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

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*temp_node;

	last_node = *stack;
	temp_node = *stack;
	while (last_node->next != NULL)
	{
		temp_node = last_node;
		last_node = last_node->next;
	}
	temp_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}
