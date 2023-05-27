/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:55:06 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/22 17:55:07 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_to_list_from_str_with_space(t_list **head, char *string)
{
	t_list	*current;
	char	**temp_array;
	int		temp_number;
	int		index;
	int		length;

	index = 0;
	temp_number = 0;
	current = NULL;
	length = ft_count_words(string, ' ');
	temp_array = ft_split(string, ' ');
	while (index < length)
	{
		temp_number = ft_atoi(temp_array[index]);
		if (is_empty(&current, head, temp_number))
		{
			index++;
			continue ;
		}
		current = ft_lstnew(temp_number);
		ft_lstadd_back(head, current);
		current = current->next;
		index++;
	}
	free_array(temp_array);
}

void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

int	is_empty(t_list **current, t_list **head, int number)
{
	if (current == NULL)
	{
		if (*head == NULL)
			*head = ft_lstnew(number);
		current = head;
		return (1);
	}
	return (0);
}
