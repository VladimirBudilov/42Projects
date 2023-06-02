#include "../includes/philosophers.h"

void add_main_data(int argc, char **argv, t_philosophers_data *p_data)
{
	p_data->number_of_philosophers = (int)ft_atoi(argv[1]);
	p_data->number_of_forks = p_data->number_of_philosophers;
	p_data->time_to_die = ft_atoi(argv[2]);
	p_data->time_to_eat = ft_atoi(argv[3]);
	p_data->time_to_sleep = ft_atoi(argv[4]);
	p_data->number_of_times_each_philosopher_must_eat = -1;
	if(argc == 6)
		p_data->number_of_times_each_philosopher_must_eat = (int) ft_atoi(argv[5]);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void free_all(t_philosophers_data *p_data, t_check *check)
{
	int i;

	i = -1;
	while (++i < p_data->number_of_philosophers)
		pthread_mutex_destroy(p_data->forks_array[i].pthread_mutex);
	i = -1;
	while (++i < p_data->number_of_philosophers)
		free(p_data->forks_array[i].pthread_mutex);
	pthread_mutex_destroy(p_data->printf_mutex);
	free(p_data->printf_mutex);
	free(p_data->threads);
	free(p_data->philosophers);
	free(p_data->forks_array);
	free(check);
	free(p_data);
}
