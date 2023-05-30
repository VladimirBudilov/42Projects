#include "../includes/philosophers.h"


void				init_philosophers_data(t_philosophers_data *p_data, int argc, char **argv)
{
	(void ) p_data;
	(void ) argc;
	(void ) argv;

}

void add_main_data(int argc, char **argv, t_philosophers_data *p_data)
{
	p_data->number_of_philosophers = ft_atoi(argv[1]);
	p_data->number_of_forks = p_data->number_of_philosophers;
	p_data->time_to_die = ft_atoi(argv[2]);
	p_data->time_to_eat = ft_atoi(argv[3]);
	p_data->time_to_sleep = ft_atoi(argv[4]);
	p_data->number_of_times_each_philosopher_must_eat = -1;
	if(argc == 6)
		p_data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

