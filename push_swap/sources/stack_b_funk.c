/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_funk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:37:03 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:37:09 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_list **b)
{
	if (*b == NULL)
		return ;
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	rotate_b(t_list **b)
{
	if (*b == NULL || ft_lstsize(*b) == 1)
		return ;
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	push_b(t_list **b, t_list **a)
{
	if (*a == NULL)
		return ;
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	reverse_rotate_b(t_list **b)
{
	if (*b == NULL)
		return ;
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}
