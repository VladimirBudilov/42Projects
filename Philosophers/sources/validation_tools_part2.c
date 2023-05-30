#include "../includes/philosophers.h"


int	has_space(char *string)
{
	if (ft_strchr(string, ' '))
		return (1);
	else
		return (0);
}

int	ft_count_words(const char *str, char separator)
{
	int	amount_of_words;
	int	trigger;

	amount_of_words = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != separator && trigger == 0)
		{
			trigger = 1;
			amount_of_words++;
		}
		else if (*str == separator)
			trigger = 0;
		str++;
	}
	return (amount_of_words);
}

int	str_is_correct(char *string, t_list **stack)
{
	char	**temp_array;
	int		index;
	int		count;

	index = 0;
	count = ft_count_words(string, ' ');
	if (count == 0)
	{
		ft_error(stack);
		return (0);
	}
	temp_array = ft_split(string, ' ');
	while (index < count)
	{
		if (!is_valid(temp_array[index], stack))
		{
			ft_error(stack);
			return (0);
		}
		index++;
	}
	return (1);
}

void	ft_error(t_list **stack_a)
{
	free_stack(stack_a);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*current_node;
	t_list	*next_node;

	if (!*stack)
		return ;
	current_node = *stack;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*stack = NULL;
}
