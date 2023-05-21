#include "../includes/push_swap.h"

void    butterfly_sorting(t_list **stack_a, t_list **stack_b, int sqrt_len)
{

        int	len;
        int	n;

        len = ft_lstsize(*stack_a);
        n = 0;
        while (n < len)
        {
            if ((*stack_a)->index <= n)
            {
                push_b(stack_b, stack_a);
                rotate_b(stack_b);
                n++;
            }
            else if ((*stack_a)->index <= n + sqrt_len)
            {
                push_b(stack_b, stack_a);
                n++;
            }
            else
                rotate_a(stack_a);

        }
}

void	ft_function_i_wrote(t_list **stack_a, t_list **stack_b)
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

int ft_find_max(t_list *stack)
{
    int		max;
    t_list 	*tmp;

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