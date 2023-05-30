#include "../includes/philosophers.h"

void create_forks(t_forks_array *forks, t_philosophers_data *p_data)
{
	int i;

	i = 1;
	forks->fork_array = malloc(sizeof(t_fork) * p_data->number_of_forks);
	if (!forks->fork_array)
		ft_error();
	while (i <= p_data->number_of_forks)
	{
		forks->fork_array[i - 1] = *create_fork(forks, i);
		i++;
	}
}

t_fork *create_fork(t_forks_array *forks, int id)
{
	t_fork *fork;
	fork = malloc(sizeof(t_fork));
	if (!fork)
		ft_error();
	fork->id = id;
	fork->pthread_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork->pthread_mutex, NULL);
	return fork;
}
