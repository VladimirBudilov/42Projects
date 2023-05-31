#ifndef PHILOSOPHERS_PHILOSOPHERS_H
#define PHILOSOPHERS_PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include <limits.h>
#include <pthread.h>
#include <sys/time.h>

struct s_check
{
	pthread_t *is_dead_thread;
	pthread_t *check_eat_thread;
} typedef t_check;



struct s_fork
{
	int id;
	int is_taken;
	pthread_mutex_t *pthread_mutex;
} typedef t_fork;



typedef struct s_philosophers_data t_philosophers_data;

struct s_philosopher
{
	int id;
	t_fork left_fork;
	t_fork right_fork;
	int number_of_times_eaten;
	long long int time_until_die;
	long long int time_to_eat;
	long long int time_to_sleep;
	int is_dead;
	int is_eating;
	int first_meal;
	long long int last_time_eaten;
	long long int prev_time_eaten;
	t_philosophers_data *p_data;
} typedef t_philosopher;


struct s_philosophers_data
{
	t_philosopher *philosophers;
	t_fork *forks_array;
	pthread_t *threads;
	int number_of_philosophers;
	int number_of_forks;
	long long int time_to_die;
	long long int time_to_eat;
	long long int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	int stop_all;
	long long int start_time;
	pthread_mutex_t *printf_mutex;
} typedef t_philosophers_data;


void	ft_error();
long  long int 	ft_atoi(char *string);
int 	ft_isdigit(char i);
int		ft_strisdigit(char *string);
int		is_valid(char *string);
void	validate_args(int argc, char **string);
void	add_main_data(int argc, char **argv, t_philosophers_data *p_data);


t_fork *create_forks(t_philosophers_data *p_data);
t_fork *create_fork(int id);


void create_philosophers(t_philosophers_data *p_data);
t_philosopher *create_philosopher(int id, t_philosophers_data *p_data);
void init_philosopher(t_philosopher *philosopher, int id, t_philosophers_data *p_data);


void create_threads(t_philosophers_data *p_data);
void eat(t_philosopher *philosopher);
void sleeping(t_philosopher *philosopher);
void thinking(t_philosopher *philosopher);
void *routine(void *arg);
void join_threads(t_philosophers_data *p_data);
void free_all(t_philosophers_data *p_data);


void *check_number_of_meals(void *arg);
int	ft_usleep(useconds_t time);

int is_dead(t_philosopher *philosopher);
void *check_dead(void *arg);
void check_all(t_philosophers_data *p_data, t_check *check);






long long int get_time(void);
long long int current_time(long long int start_time);





void print_all(t_philosophers_data *pData);
void print_main_data(t_philosophers_data *pData);
void print_forks_id(t_philosophers_data *pData);
void print_philosophers_data(t_philosophers_data *p_data);






#endif
