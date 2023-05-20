#include "../includes/push_swap.h"

int	list_is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	add_index(t_list **stack)
{
	t_list	*current;
	t_list	*sub_list;

	current = *stack;
	while (current != NULL)
	{
		current->index = 0;
		current = current->next;
	}
	current = *stack;
	while (current != NULL)
	{
		sub_list = *stack;
		while (sub_list != NULL)
		{
			if (current->content > sub_list->content)
				current->index += 1;
			sub_list = sub_list->next;
		}
		current = current->next;
	}
}