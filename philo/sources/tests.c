#include "../includes/philosophers.h"


void print_all(t_philosophers_data *pData)
{
	print_main_data(pData);
	printf("\n");
	print_forks_id(pData);
	printf("\n");
	print_philosophers_data(pData);

}

void print_philosophers_data(t_philosophers_data *p_data)
{
	int i;

	i = 0;
	while (i < p_data->number_of_philosophers)
	{
		printf("philosopher id: %d\n", p_data->philosophers[i].id);
		printf("philosopher time_until_die: %lld\n", p_data->philosophers[i].time_until_die);
		printf("philosopher time_to_eat: %lld\n", p_data->philosophers[i].time_to_eat);
		printf("philosopher time_to_sleep: %lld\n", p_data->philosophers[i].time_to_sleep);
		printf("philosopher is_dead: %d\n", p_data->philosophers[i].is_dead);
		printf("philosopher left_fork: %d\n", p_data->philosophers[i].left_fork.id);
		printf("philosopher right_fork: %d\n", p_data->philosophers[i].right_fork.id);
		printf("\n");
		i++;
	}
}

void print_forks_id(t_philosophers_data *pData)
{
	int i;

	i = 0;
	while (i < pData->number_of_forks)
	{
		printf("fork_ id: %d\n", pData->forks_array[i].id);
		i++;
	}

}

void print_main_data(t_philosophers_data *pData)
{
	printf("number_of_philosophers: %d\n", pData->number_of_philosophers);
	printf("number_of_forks: %d\n", pData->number_of_forks);
	printf("time_to_die: %lld\n", pData->time_to_die);
	printf("time_to_eat: %lld\n", pData->time_to_eat);
	printf("time_to_sleep: %lld\n", pData->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n", pData->number_of_times_each_philosopher_must_eat);
}