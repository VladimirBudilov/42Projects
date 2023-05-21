
#include "../includes/push_swap.h"

void	swap_b(t_list **b)
{
	if(*b == NULL)
		return;
	swap(b);
	ft_putstr_fd("sb\n",1);
}

void	rotate_b(t_list **b)
{
	if(*b == NULL)
		return;
	rotate(b);
	ft_putstr_fd("rb\n",1);
}

void	push_b(t_list **b, t_list **a)
{
	if(*a == NULL)
		return ;
	push(a,b);
	ft_putstr_fd("pb\n", 1);
}

void	reverse_rotate_b(t_list **b)
{
	if(*b == NULL)
		return;
	reverse_rotate(b);
	ft_putstr_fd("rrb\n",1);
}