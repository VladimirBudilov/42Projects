/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_inner_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:33:20 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 19:33:22 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat(t_philosopher *philosopher)
{
	if (!can_start_to_eat(philosopher))
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	if (!is_stopped(philosopher))
		printf("%lld Philosopher %d has taken a fork\n",
			current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	if (is_stop_all(philosopher))
	{
		pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
		pthread_mutex_unlock(philosopher->left_fork.pthread_mutex);
		return ;
	}
	philosopher_is_eating(philosopher);
	pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
	pthread_mutex_unlock(philosopher->left_fork.pthread_mutex);
}

void	thinking(t_philosopher *philosopher)
{
	if (is_stop_all(philosopher))
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	if (!is_stopped(philosopher))
		printf("%lld Philosopher %d is thinking\n",
			current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
}

void	sleeping(t_philosopher *philosopher)
{
	if (is_stop_all(philosopher))
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	if (!is_stopped(philosopher))
		printf("%lld Philosopher %d is sleeping\n",
			current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	ft_usleep(philosopher->time_to_sleep);
}
