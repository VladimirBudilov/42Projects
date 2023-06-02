/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:36:13 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 18:36:15 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_all(t_philosophers_data *p_data, t_check *check)
{
	pthread_create(&check->is_dead_thread, NULL, check_dead, (void *) p_data);
	if (p_data->number_of_times_each_philosopher_must_eat != -1)
		pthread_create(&check->check_eat_thread, NULL,
			check_number_of_meals, (void *) p_data);
}

void	*check_number_of_meals(void *arg)
{
	t_philosophers_data	*p_data;
	int					i;
	int					j;

	i = 0;
	j = 0;
	p_data = (t_philosophers_data *) arg;
	while (1)
	{
		if (is_stop_all(&(p_data->philosophers[0])))
			break ;
		if (i == p_data->number_of_philosophers)
			i = 0;
		meal_counter(p_data, i, &j);
		stop_all(p_data, j);
		i++;
	}
	return (NULL);
}

void	meal_counter(t_philosophers_data *p_data, int i, int *j)
{
	pthread_mutex_lock(&(p_data->philosophers[i].increment_mutex));
	if (p_data->philosophers[i].number_of_times_eaten
		== p_data->number_of_times_each_philosopher_must_eat
		&& !p_data->philosophers[i].finished_eating)
	{
		pthread_mutex_unlock(&(p_data->philosophers[i].increment_mutex));
		p_data->philosophers[i].finished_eating = 1;
		*j += 1;
	}
	pthread_mutex_unlock(&(p_data->philosophers[i].increment_mutex));
}

void	stop_all(t_philosophers_data *p_data, int j)
{
	if (j == p_data->number_of_philosophers)
	{
		pthread_mutex_lock(&(p_data->stop_all_mutex));
		p_data->philosophers->p_data->stop_all = 1;
		pthread_mutex_unlock(&(p_data->stop_all_mutex));
	}
}
