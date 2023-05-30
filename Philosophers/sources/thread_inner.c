#include "../includes/philosophers.h"

int is_dead(t_philosopher *philosopher)
{
	if (philosopher->is_dead == 1)
	{
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		printf("Philosopher %d is dead\n", philosopher->id);
		pthread_mutex_unlock(philosopher->p_data->printf_mutex);
		return 1;
	}
	if (get_time() - philosopher->last_time_eaten > philosopher->time_until_die)
	{
		philosopher->is_dead = 1;
		philosopher->p_data->kill_all = 1;
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		printf("Philosopher %d is dead\n", philosopher->id);
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		return 1;
	}
	philosopher->last_time_eaten = get_time();
	return 0;
}

void thinking(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("Philosopher %d is thinking\n", philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
}

void sleeping(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("Philosopher %d is sleeping\n", philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	usleep(philosopher->time_to_sleep * 1000);
}

void eat(t_philosopher *philosopher)
{

	pthread_mutex_lock(philosopher->right_fork.pthread_mutex);
	pthread_mutex_lock(philosopher->left_fork.pthread_mutex);
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("Philosopher %d has taken a fork\n", philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	pthread_mutex_lock(philosopher->p_data->printf_mutex);
	printf("Philosopher %d is eating\n", philosopher->id);
	pthread_mutex_unlock(philosopher->p_data->printf_mutex);
	usleep(philosopher->time_to_eat * 1000);
	philosopher->number_of_times_eaten++;
	pthread_mutex_unlock(philosopher->right_fork.pthread_mutex);
	pthread_mutex_unlock(philosopher->left_fork.pthread_mutex);
}