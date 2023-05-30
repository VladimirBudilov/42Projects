#ifndef PHILOSOPHERS_PHILOSOPHERS_H
#define PHILOSOPHERS_PHILOSOPHERS_H

#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include <limits.h>

struct s_fork
{
	int id;
	pthread_mutex_t *fork_mutex;
} typedef t_fork;

struct  s_forks
{
	int *forks_id;
	t_fork **forks;
} typedef t_forks;

struct s_philosopher
{
	int id;
	t_fork left_fork;
	t_fork right_fork;
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


struct s_philosophers_data
{
	t_philosopher **philosophers;
	int number_of_philosophers;
	int number_of_forks;
	int number_of_times_eaten;
	int number_of_times_each_philosopher_must_eat;
	long long int time_to_die;
	long long int time_to_eat;
	long long int time_to_sleep;
} typedef t_philosophers_data;


int		is_valid_number(char *string);
int		ft_strisdigit(char *string);
int		is_valid(char *string);
int		has_repeat(t_list **stack);
int		is_validate_atoi(const char *str);
void	ft_error();
void	free_stack(t_list **stack);
int	check_overflow(long long int res, long long int sign);


void create_forks(t_forks *forks, t_philosophers_data *p_data, int argc);

void create_fork(t_forks *forks, int id);




void	init_philosophers_data(t_philosophers_data *philosophers_data, int argc, char **argv);

void create_philosophers(t_philosophers_data *p_data);




void create_trheads(t_philosophers_data *p_data);







#endif
