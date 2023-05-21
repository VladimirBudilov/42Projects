#include "../includes/push_swap.h"


int sqrt_len(t_list *stack)
{
    int	len;

    len = ft_lstsize(stack);
    return (ft_sqrt(len * 2));
}

int ft_sqrt(int nb)
{
    int i;

    i = 1;
    while (i * i < nb)
        i++;
    return (i);
}