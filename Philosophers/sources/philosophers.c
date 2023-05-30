#include "../includes/philosophers.h"

void create_philosophers(t_philosophers_data *p_data, t_forks_array *forks)
{
	int id;

	id = 1;
	p_data->kill_all = 0;
	p_data->threads = malloc(sizeof(pthread_t) * p_data->number_of_philosophers);
	p_data->printf_mutex = malloc(sizeof(pthread_mutex_t));
	p_data->forks = forks;
	p_data->philosophers = malloc(sizeof(t_philosopher) * p_data->number_of_philosophers);
	if(p_data->philosophers == NULL)
		ft_error();
	while (id <= p_data->number_of_philosophers)
	{
		p_data->philosophers[id-1] = *(create_philosopher(id, p_data));
		id++;
	}

}

t_philosopher *create_philosopher(int id, t_philosophers_data *p_data)
{
	t_philosopher *philosopher;
	philosopher = malloc(sizeof(t_philosopher));
	if(philosopher == NULL)
		ft_error();
	init_philosopher(philosopher, id, p_data);
	return philosopher;
}

void init_philosopher(t_philosopher *philosopher, int id, t_philosophers_data *p_data)
{
	philosopher->id = id;
	philosopher->time_until_die = p_data->time_to_die;
	philosopher->time_to_eat = p_data->time_to_eat;
	philosopher->time_to_sleep = p_data->time_to_sleep;
	philosopher->is_dead = 0;
	philosopher->p_data = p_data;
	philosopher->left_fork = p_data->forks->fork_array[(id-1) % p_data->number_of_forks];
	philosopher->right_fork = p_data->forks->fork_array[id % p_data->number_of_forks];
}
