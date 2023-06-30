/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:08 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 14:43:09 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_fork	*create_forks(t_philosophers_data *p_data)
{
	int		i;
	t_fork	*fork_array;

	i = 1;
	fork_array = malloc(sizeof(t_fork) * p_data->number_of_forks);
	if (!fork_array)
		ft_error();
	while (i <= p_data->number_of_forks)
	{
		fork_array[i - 1] = create_fork(i);
		i++;
	}
	return (fork_array);
}

t_fork	create_fork(int id)
{
	t_fork	fork;

	fork.id = id;
	fork.pthread_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork.pthread_mutex, NULL);
	return (fork);
}
