#include <stdbool.h>
#include "../includes/push_swap.h"



int main(int argc, char *argv[])
{
	int index;
	int temp_number;
	t_list *a;
    t_list *cursor;

	a = NULL;
    cursor = NULL;
    index = 1;
	if (argc == 1)
		return (1);
	if (argc >= 2)
	{
        while (index < argc)
        {
			if (has_space(argv[index]))
			{
				if(!str_is_correct(argv[index]))
					return (1);
				add_to_list_from_str_with_space(&a, argv[index]);
				index++;
				continue;

			}
			if (!is_valid(argv[index]))
                return (1);
            temp_number = atoi(argv[index]);
            if(a == NULL)
			{
				a = ft_lstnew(temp_number);
				index++;
				continue;
			}
			cursor = ft_lstnew(temp_number);
			ft_lstadd_back(&a, cursor);

            index++;
        }
        if (has_repeat(&a))
			return (1);
		while (a != NULL)
		{
			printf("a->content = %d\n", a->content);
			a = a->next;
		}
	}
	return 0;
}

int str_is_correct(char *string)
{

	char **temp_array;
	int index;
	int count;

	index = 0;
	count = 0;
	printf("count %d", count);

	count = ft_count_words(string, ' ');
	printf("count %d", count);

	temp_array = ft_split(string, ' ');
	if(count == 0)
	{
		ft_putstr_fd("Error: Invalid string with spaces", 1);
		return (0);
	}
	printf("count %d", count);
	while (index < count)
	{
		if (!is_valid(temp_array[index]))
		{
			ft_putstr_fd("Error: Invalid string with spaces", 1);
			free(temp_array);
			return (0);
		}
		index++;
	}
	free(temp_array);
	return (1);
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