

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
	if (!*string)
		return (0);
	if (*string == '-' && *(string + 1) == '\0')
		return (0);
	if (*string == '-')
		string++;
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
	if(is_validate_atoi(string))
		return (1);
	else
		return (0);
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

int	is_validate_atoi(const char *str)
{
	int			index;
	long long int	sign;
	long long int	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		   || str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - '0');
		index++;
		if(res * sign > INT_MAX)
			return (0);
		if(res * sign < INT_MIN)
			return (0);
	}
	return (1);
}

int count_space(char *string)
{
	int	count;
	int check;

	count = 0;
	check = 1;
	while (*string)
	{
		if (check && *string == ' ')
		{
			check = 0;
			count++;
		}
		if (!check && ft_isprint(*string))
		{
			check = 1;
		}
		string++;
	}
	return (count);
}

int	has_space(char *string)
{
	if (ft_strchr(string, ' '))
		return (1);
	else
		return (0);
}