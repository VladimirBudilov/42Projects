/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:37:09 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 18:37:11 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*check_dead(void *arg)
{
	t_philosophers_data	*p_data;
	int					i;

	i = 0;
	p_data = (t_philosophers_data *) arg;
	while (1)
	{
		pthread_mutex_lock(&(p_data->stop_all_mutex));
		if (p_data->stop_all)
		{
			pthread_mutex_unlock(&(p_data->stop_all_mutex));
			break ;
		}
		pthread_mutex_unlock(&(p_data->stop_all_mutex));
		if (i == p_data->number_of_philosophers)
			i = 0;
		if ((is_dead(&p_data->philosophers[i])))
			break ;
		i++;
	}
	return (NULL);
}

int	is_stopped(t_philosopher *philosopher)
{
	int	rv;

	pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
	rv = philosopher->p_data->stop_all;
	pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
	return (rv);
}

int	is_dead(t_philosopher *philosopher)
{
	pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
	if (philosopher->p_data->stop_all)
	{
		pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
	pthread_mutex_lock(&(philosopher->last_time_eaten_mutex));
	if ((current_time(philosopher->p_data->start_time)
			- philosopher->last_time_eaten) > philosopher->time_until_die)
	{
		pthread_mutex_unlock(&(philosopher->last_time_eaten_mutex));
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		printf("%lld  philosopher %d died\n",
			current_time(philosopher->p_data->start_time), philosopher->id);
		pthread_mutex_unlock(philosopher->p_data->printf_mutex);
		pthread_mutex_lock(&(philosopher->p_data->stop_all_mutex));
		philosopher->p_data->stop_all = 1;
		pthread_mutex_unlock(&(philosopher->p_data->stop_all_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philosopher->last_time_eaten_mutex));
	return (0);
}
