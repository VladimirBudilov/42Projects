/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:06:43 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:06:47 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		index;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	index = 1;
	if (argc == 1)
		return (1);
	if (argc >= 2)
	{
		while (index < argc)
		{
			create_list(&a, argv[index]);
			index++;
		}
		if (has_repeat(&a))
			ft_error(&a);
		add_index(&a);
		if (!list_is_sorted(&a))
			do_sort(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}

void	do_sort(t_list **stack_a, t_list **stack_b)
{
	int	sqrt_len;

	if (ft_lstsize(*stack_a) == 2)
		sort_2_nodes(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_3_nodes(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_4_nodes(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5_nodes(stack_a, stack_b);
	else
	{
		sqrt_len = ft_sqrt(ft_lstsize(*stack_a));
		butterfly_sorting(stack_a, stack_b, sqrt_len);
		push_all_to_stack_a(stack_a, stack_b);
	}
}

void	create_list(t_list **stack, char *number)
{
	int		temp_number;
	t_list	*cursor;

	if (has_space(number))
	{
		if (!str_is_correct(number, stack))
			ft_error(stack);
		add_to_list_from_str_with_space(stack, number);
		return ;
	}
	if (!is_valid(number, stack))
		ft_error(stack);
	temp_number = atoi(number);
	if (stack == NULL)
	{
		*stack = ft_lstnew(temp_number);
	}
	cursor = ft_lstnew(temp_number);
	ft_lstadd_back(stack, cursor);
}
