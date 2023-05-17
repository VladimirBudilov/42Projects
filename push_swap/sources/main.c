#include <stdbool.h>
#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	int index;
	int temp_number;
	t_list *a;
	t_list *b;
    t_list *cursor;

    b = NULL;
    cursor = NULL;
    index = 1;
	if (argc == 1)
		return (1);
	if (argc >= 2)
	{
        while (index < argc)
        {
            if (!is_valid(argv[index]))
                return (1);
            temp_number = atoi(argv[index]);
            if(index == 1)
			{
				a = ft_lstnew(temp_number);
				index++;
				continue;
			}
			cursor = ft_lstnew(temp_number);
			ft_lstadd_back(&a, cursor);
            cursor = ft_lstlast(a);

            index++;
        }
        if (has_repeat(&a))
		{
			return (1);
		}
		while (a != NULL)
		{
			printf("%d\n", a->content);
			a = a->next;
		}
	}
	return 0;
}


