
#include "../includes/push_swap.h"

void add_to_list_from_str_with_space(t_list **head, char *string)
{
	t_list *current;
	char **temp_array;
	int temp_number;
	int index;
	int length;

	index = 0;
	temp_number = 0;
	current = NULL;

	length = ft_count_words(string, ' ');
	temp_array = ft_split(string, ' ');
	while (index <= length)
	{
		if (current == NULL)
			current = *head;
		temp_number = ft_atoi(temp_array[index]);
		current = ft_lstnew(temp_number);
		ft_lstadd_back(head,current);
		current = current->next;
		index++;
	}
	free(temp_array);
}