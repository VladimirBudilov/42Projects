/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:21:38 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 15:21:42 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_threads(t_philosophers_data *p_data)
{
	int			id;

	id = 1;
	while (id <= p_data->number_of_philosophers)
	{
		pthread_create(&(p_data->philosophers[id - 1].thread),
			NULL, &routine, &p_data->philosophers[id - 1]);
		id++;
	}
}

void	*routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *) arg;
	pthread_mutex_lock(&(philosopher->last_time_eaten_mutex));
	philosopher->last_time_eaten
		= current_time(philosopher->p_data->start_time);
	pthread_mutex_unlock(&(philosopher->last_time_eaten_mutex));
	if (philosopher->id % 2 == 0)
		usleep(2500);
	while (1)
	{
		pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
		if (philosopher->p_data->stop_all)
		{
			pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
			break ;
		}
		pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
		eat(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	join_threads(t_philosophers_data *p_data, t_check *check)
{
	int	i;

	i = 0;
	while (i < p_data->number_of_philosophers)
	{
		pthread_join(p_data->philosophers[i].thread, NULL);
		i++;
	}
	pthread_join(check->is_dead_thread, NULL);
	if (p_data->number_of_times_each_philosopher_must_eat != -1)
		pthread_join(check->check_eat_thread, NULL);
}
