#include "../includes/philosophers.h"

{
	if(argc == 5 || argc == 6)
	{
		philosophers_data->number_of_philosophers = ft_atoi(argv[1]);
		philosophers_data->number_of_forks = philosophers_data->number_of_philosophers;
		philosophers_data->time_to_die = ft_atoi(argv[2]);
		philosophers_data->time_to_eat = ft_atoi(argv[3]);
		philosophers_data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			philosophers_data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		}
	}
	else
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
}
