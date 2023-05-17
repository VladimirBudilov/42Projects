/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:10:59 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/02 19:11:01 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;
	t_list	*j;

	i = *lst;
	while (i)
	{
		j = i->next;
		ft_lstdelone(i, (*del));
		i = j;
	}
	*lst = 0;
}
