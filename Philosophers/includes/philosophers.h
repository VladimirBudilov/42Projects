#ifndef PHILOSOPHERS_PHILOSOPHERS_H
#define PHILOSOPHERS_PHILOSOPHERS_H

#include <stdio.h>
#include "../libft/libft.h"

struct s_philosophers_data
{
	int number_of_philosophers;
	int number_of_forks;
	int number_of_times_eaten;
	int number_of_times_each_philosopher_must_eat;
	long long int time_to_die;
	long long int time_to_eat;
	long long int time_to_sleep;
} typedef t_philosophers_data;

struct s_philosopher
{
	int id;
	int number_of_times_eaten;
	long long int time_until_die;
	long long int time_until_eat;
	long long int time_until_sleep;
	int is_eating;
	int is_sleeping;
	int is_thinking;
	int is_dead;
	int is_has_fork;
	int can_eat;
} typedef t_philosopher;

struct s_philosophers_list
{
	t_philosopher *philosopher;
	t_philosopher next;
	t_philosopher prev;
} typedef t_philosophers_list;

void				init_philosophers_data(t_philosophers_data *philosophers_data, int argc, char **argv);


#endif
