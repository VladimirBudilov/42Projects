/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_inner_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:56:20 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 18:56:22 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philosopher_is_eating(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("%lld Philosopher %d is eating\n",
		current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	pthread_mutex_lock(&(philosopher->increment_mutex));
	philosopher->number_of_times_eaten++;
	pthread_mutex_unlock(&(philosopher->increment_mutex));
	pthread_mutex_lock(&(philosopher->last_time_eaten_mutex));
	philosopher->last_time_eaten
		= current_time(philosopher->p_data->start_time);
	pthread_mutex_unlock(&(philosopher->last_time_eaten_mutex));
	ft_usleep(philosopher->time_to_eat);
}

int	can_start_to_eat(t_philosopher *philosopher)
{
	if (is_stop_all(philosopher))
		return (0);
	pthread_mutex_lock(philosopher->right_fork.pthread_mutex);
	if (is_stop_all(philosopher))
	{
		pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
		return (0);
	}
	if (only_one_philosopher(philosopher))
		return (0);
	pthread_mutex_lock(philosopher->left_fork.pthread_mutex);
	if (is_stop_all(philosopher))
	{
		pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
		pthread_mutex_unlock(philosopher->left_fork.pthread_mutex);
		return (0);
	}
	return (1);
}

int	only_one_philosopher(t_philosopher *philosopher)
{
	if (philosopher->p_data->number_of_philosophers == 1)
	{
		ft_usleep(philosopher->p_data->time_to_die);
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		printf("%lld Philosopher %d died\n",
			current_time(philosopher->p_data->start_time), philosopher->id);
		pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
		philosopher->p_data->stop_all = 1;
		pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
		return (1);
	}
	return (0);
}

int	is_stop_all(t_philosopher *philosopher)
{
	pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
	if (philosopher->p_data->stop_all)
	{
		pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
	return (0);
}
