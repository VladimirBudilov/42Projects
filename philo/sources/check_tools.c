#include "../includes/philosophers.h"

void check_all(t_philosophers_data *p_data, t_check *check)
{
	pthread_create(&check->is_dead_thread, NULL, check_dead, (void *) p_data);
	if(p_data->number_of_times_each_philosopher_must_eat != -1)
		pthread_create(&check->check_eat_thread, NULL, check_number_of_meals, (void *) p_data);
}

void *check_number_of_meals(void *arg)
{
	t_philosophers_data *p_data;
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	p_data = (t_philosophers_data *) arg;
	count = p_data->number_of_philosophers;
	while (1)
	{
		if(p_data->stop_all)
			break ;
		if(i == p_data->number_of_philosophers)
			i = 0;
		if(p_data->philosophers[i].number_of_times_eaten == p_data->number_of_times_each_philosopher_must_eat && !p_data->philosophers[i].finished_eating)
		{
			p_data->philosophers[i].finished_eating = 1;
			j++;
		}
		if(j == count)
		{
			p_data->philosophers->p_data->stop_all = 1;
			break ;
		}
		i++;
	}
	return NULL;
}

void *check_dead(void *arg)
{
	t_philosophers_data *p_data;
	int i;

	i = 0;
	p_data = (t_philosophers_data *) arg;
	while (1)
	{
		if(p_data->stop_all)
			break ;
		if(i == p_data->number_of_philosophers)
			i = 0;
		if((is_dead(&p_data->philosophers[i])))
			break ;
		i++;
	}
	return NULL;
}

int is_dead(t_philosopher *philosopher)
{
	if(philosopher->p_data->stop_all)
		return 1;
	if ((current_time(philosopher->p_data->start_time) - philosopher->last_time_eaten) > philosopher->time_until_die)
	{
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		printf("%lld  philosopher %d died\n", current_time(philosopher->p_data->start_time), philosopher->id);
		pthread_mutex_lock(philosopher->p_data->printf_mutex);
		philosopher->is_dead = 1;
		philosopher->p_data->stop_all = 1;
		return 1;
	}
	return 0;
}