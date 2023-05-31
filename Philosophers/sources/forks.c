#include "../includes/philosophers.h"

t_fork *create_forks(t_philosophers_data *p_data)
{
	int i;
	t_fork *fork_array;

	i = 1;
	fork_array = malloc(sizeof(t_fork) * p_data->number_of_forks);
	if (!fork_array)
		ft_error();
	while (i <= p_data->number_of_forks)
	{
		fork_array[i - 1] = *create_fork(i);
		i++;
	}
	return fork_array;
}

t_fork *create_fork(int id)
{
	t_fork *fork;
	fork = malloc(sizeof(t_fork));
	if (!fork)
		ft_error();
	fork->id = id;
	fork->is_taken = 0;
	fork->pthread_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork->pthread_mutex, NULL);
	return fork;
}
