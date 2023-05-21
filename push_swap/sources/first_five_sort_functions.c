
#include "../includes/push_swap.h"

void	sort_2_nodes(t_list **stack)
{
    int first;
    int second;

    first = (*stack)->content;
    second = (*stack)->next->content;
    if (first > second) {
        swap_a(stack);
    }
}

void	sort_3_nodes(t_list **stack)
{
    int first;
    int second;
    int third;

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

void    sort_4_nodes(t_list **a, t_list **b)
{
    push_smallest_node_to_stack_b_4(a, b);
    sort_3_nodes(a);
    push_a(a, b);
}

void    sort_5_nodes(t_list **a, t_list **b)
{
    push_smallest_node_to_stack_b_5(a, b);
    sort_4_nodes(a, b);
    push_a(a, b);
}

void push_smallest_node_to_stack_b_4(t_list **a, t_list **b)
{
    t_list *smallest_node;
    t_list *current;

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

void push_smallest_node_to_stack_b_5(t_list **a, t_list **b)
{
    t_list *smallest_node;
    t_list *current;

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

t_list *find_smallest_node(t_list **stack)
{
    t_list *smallest_node;
    t_list *current;

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
