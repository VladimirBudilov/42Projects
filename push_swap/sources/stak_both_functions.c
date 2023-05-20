/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stak_both_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:23:23 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/20 14:23:25 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss", 1);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr", 1);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr", 1);
}
