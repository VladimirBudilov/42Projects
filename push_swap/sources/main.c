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
		add_index(&a);
		//rotate_a(&a);
		while (a != NULL)
		{
			printf("a->content = %d\n", a->content);
			printf("a->index = %d\n", a->index);
			a = a->next;
		}
	}
	return (0);
}





