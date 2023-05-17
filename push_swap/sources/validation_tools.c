

#include "../includes/push_swap.h"

int	is_valid(char *string)
{
	if (!ft_strisdigit(string))
	{
		ft_putstr_fd("you put not digit\n", 1);
		return (0);
	}
	if (!is_valid_number(string))
	{
		ft_putstr_fd("you put not walid number\n", 1);
		return (0);
	}
	return (1);
}

int	ft_strisdigit(char *string)
{
	if (*string == '-')
	{
		string++;
	}
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}

int is_valid_number(char *string)
{
	long long int number;

	number = ft_atoi(string);
	printf("number = %lld\n", number);

	if(number > INT_MAX)
		return (0);
	if(number < INT_MIN)
		return (0);
	return 1;
}

int has_repeat(t_list **stack)
{
	t_list *current_node;
	t_list *compare_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		compare_node = current_node->next;
		while (compare_node != NULL)
        {
            if(compare_node->content == current_node->content)
			{
				ft_putstr_fd("you have repeat in numbers", 1);
				return (1);
			}
			compare_node = compare_node->next;
		}
		current_node = current_node->next;
    }
	return (0);
}
