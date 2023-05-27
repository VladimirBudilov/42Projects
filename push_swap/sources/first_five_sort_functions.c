/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_five_sort_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:28:33 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:28:35 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2_nodes(t_list **stack)
{
	int	first;
	int	second;

	first = (*stack)->content;
	second = (*stack)->next->content;
	if (first > second)
	{
		swap_a(stack);
	}
}

void	sort_3_nodes(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && third > first)
		swap_a(stack);
	else if (first > second && second > third && third < first)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first > second && second < third && third < first)
		rotate_a(stack);
	else if (first < second && second > third && third > first)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (first < second && second > third && third < first)
		reverse_rotate_a(stack);
}

void	sort_4_nodes(t_list **a, t_list **b)
{
	push_smallest_node_to_stack_b_4(a, b);
	sort_3_nodes(a);
	push_a(a, b);
}

void	sort_5_nodes(t_list **a, t_list **b)
{
	push_smallest_node_to_stack_b_5(a, b);
	sort_4_nodes(a, b);
	push_a(a, b);
}
