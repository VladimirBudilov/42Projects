#include "../includes/philosophers.h"

void create_forks(t_forks *forks, t_philosophers_data *p_data, int argc)
{
	int i;

	i = 1;
	forks = malloc(sizeof(t_forks) * p_data->number_of_forks);
	if (!forks)
		ft_error();
	while (i <= p_data->number_of_forks)
	{
		create_fork(&forks[i], i);
	}
}

void create_fork(t_forks *forks, int id)
{
	forks->forks_id[id] = id;

}
