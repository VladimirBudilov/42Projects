#include "../includes/philosophers.h"


void eat(t_philosopher *philosopher)
{
	if(philosopher->p_data->stop_all)
		return ;
	pthread_mutex_lock(philosopher->right_fork.pthread_mutex);
	pthread_mutex_lock(philosopher->left_fork.pthread_mutex);
	if(philosopher->p_data->stop_all)
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("%lld Philosopher %d has taken a fork\n", current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	if(philosopher->p_data->stop_all)
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("%lld Philosopher %d is eating\n", current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	philosopher->prev_time_eaten = philosopher->last_time_eaten;
	philosopher->last_time_eaten = current_time(philosopher->p_data->start_time);
	ft_usleep(philosopher->time_to_eat);
	philosopher->number_of_times_eaten++;
	pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
	pthread_mutex_unlock(philosopher->left_fork.pthread_mutex);
}

void thinking(t_philosopher *philosopher)
{
	if(philosopher->p_data->stop_all)
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("%lld Philosopher %d is thinking\n",current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
}

void sleeping(t_philosopher *philosopher)
{
	if(philosopher->p_data->stop_all)
		return ;
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("%lld Philosopher %d is sleeping\n", current_time(philosopher->p_data->start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	ft_usleep(philosopher->time_to_sleep);
}

