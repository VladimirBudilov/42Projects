/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_five_functions_tools.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:29:30 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:29:32 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_smallest_node(t_list **stack)
{
	t_list	*smallest_node;
	t_list	*current;

	smallest_node = *stack;
	current = *stack;
	while (current != NULL)
	{
		if (current->index < smallest_node->index)
			smallest_node = current;
		current = current->next;
	}
	return (smallest_node);
}

void	push_smallest_node_to_stack_b_5(t_list **a, t_list **b)
{
	t_list	*smallest_node;
	t_list	*current;

	smallest_node = find_smallest_node(a);
	current = *a;
	if (current->next == smallest_node)
		swap_a(a);
	else if (current->next->next == smallest_node)
	{
		rotate_a(a);
		rotate_a(a);
	}
	else if (current->next->next->next == smallest_node)
	{
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
	else if (current->next->next->next->next == smallest_node)
		reverse_rotate_a(a);
	push_b(b, a);
}

void	push_smallest_node_to_stack_b_4(t_list **a, t_list **b)
{
	t_list	*smallest_node;
	t_list	*current;

	smallest_node = find_smallest_node(a);
	current = *a;
	if (current->next == smallest_node)
		swap_a(a);
	else if (current->next->next == smallest_node)
	{
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
	else if (current->next->next->next == smallest_node)
		reverse_rotate_a(a);
	push_b(b, a);
}
