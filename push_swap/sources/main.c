#include <stdbool.h>
#include "../includes/push_swap.h"



int main(int argc, char *argv[])
{
	int index;
	int temp_number;
	t_list *a;
	t_list *b;
    t_list *cursor;
    int sqrt_len;

	a = NULL;
    b= NULL;
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
        t_list *temp_cursor;
        temp_cursor = a;

        while (temp_cursor != NULL)
        {
            printf("index: %d , content %d\n", temp_cursor->index, temp_cursor->content);
            temp_cursor = temp_cursor->next;
        }

        if(!list_is_sorted(&a))
        {
            if (ft_lstsize(a) == 2)
                sort_2_nodes(&a);
            else if (ft_lstsize(a) == 3)
                sort_3_nodes(&a);
            else if (ft_lstsize(a) == 4)
                sort_4_nodes(&a, &b);
            else if (ft_lstsize(a) == 5)
                sort_5_nodes(&a, &b);
            else
            {
                sqrt_len = ft_sqrt(ft_lstsize(a));
                butterfly_sorting(&a, &b, sqrt_len);

            }
        }
        temp_cursor = a;
        while (temp_cursor!= NULL)
        {
            printf("index: %d , content %d\n", temp_cursor->index, temp_cursor->content);
            temp_cursor = temp_cursor->next;
        }
	}
	return (0);
}





