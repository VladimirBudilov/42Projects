#include "../includes/push_swap.h"

void swap_a(t_list **a)
{
	if (*a == NULL)
		return ;
    swap(a);
	ft_putstr_fd("sa ",1);
}

void rotate_a(t_list **a)
{
	if(*a == NULL)
		return ;
	rotate(a);
	ft_putstr_fd("ra ",1);
}

void push_a(t_list **a, t_list **b)
{
	if(*b == NULL)
		return ;
	push(b,a);
	ft_putstr_fd("pa", 1);
}

void	reverse_rotate_a(t_list **a)
{
	if(*a == NULL)
		return ;
	reverse_rotate(a);
	ft_putstr_fd("rra ",1);
}