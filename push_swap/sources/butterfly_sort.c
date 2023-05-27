/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:23:12 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:23:15 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	butterfly_sorting(t_list **stack_a, t_list **stack_b, int sqrt_len)
{
	int	len;
	int	cursor;

	len = ft_lstsize(*stack_a);
	cursor = 0;
	while (cursor < len)
	{
		if ((*stack_a)->index <= cursor)
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
			cursor++;
		}
		else if ((*stack_a)->index <= cursor + sqrt_len)
		{
			push_b(stack_b, stack_a);
			cursor++;
		}
		else
			rotate_a(stack_a);
	}
}

void	push_all_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	max;

	len = ft_lstsize(*stack_b);
	max = len - 1;
	while (len > 0)
	{
		while ((*stack_b)->index != max)
		{
			if (ft_find_max(*stack_b) == 1)
				rotate_b(stack_b);
			else
				reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
		max--;
		len--;
	}
}

int	ft_find_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	max = ft_lstsize(stack) - 1;
	tmp = stack;
	while (tmp->index != 0)
	{
		if (tmp->index == max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
