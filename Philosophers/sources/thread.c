#include "../includes/philosophers.h"

void create_threads(t_philosophers_data *p_data)
{
	int id;

	id = 1;
	while (id <= p_data->number_of_philosophers)
	{
		pthread_t thread;
		pthread_create(&thread, NULL, &routine, &p_data->philosophers[id-1]);
		p_data->threads[id-1] = thread;
		id++;
	}
}

void *routine(void *arg)
{
	t_philosopher *philosopher;
	philosopher = (t_philosopher *) arg;
	philosopher->last_time_eaten = get_time();
	if(philosopher->id % 2 == 0)
		usleep(10);
	while (1)
	{
		if(is_dead(philosopher))
			break;
		eat(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	return NULL;
}

void join_threads(t_philosophers_data *p_data)
{
	int i;

	i = 0;
	while (i < p_data->number_of_philosophers)
	{
		pthread_join(p_data->threads[i], NULL);
		i++;
	}
}