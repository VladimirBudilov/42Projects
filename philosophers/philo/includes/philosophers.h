/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:19:15 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 18:19:17 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_check
{
	pthread_t	is_dead_thread;
	pthread_t	check_eat_thread;
}			t_check;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	*pthread_mutex;
}			t_fork;

typedef struct s_philosophers_data	t_philosophers_data;

typedef struct s_philosopher
{
	int					id;
	t_fork				left_fork;
	t_fork				right_fork;
	pthread_t			thread;
	int					number_of_times_eaten;
	long long int		time_until_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	int					finished_eating;
	long long int		last_time_eaten;
	t_philosophers_data	*p_data;
	pthread_mutex_t		increment_mutex;
	pthread_mutex_t		last_time_eaten_mutex;
}			t_philosopher;

typedef struct s_philosophers_data
{
	t_philosopher	*philosophers;
	t_fork			*forks_array;
	int				number_of_philosophers;
	int				number_of_forks;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				stop_all;
	long long int	start_time;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	stop_all_mutex;
}			t_philosophers_data;

void			ft_error(void);
long long int	ft_atoi(char *string);
int				ft_isdigit(char i);
int				ft_strisdigit(char *string);
int				is_valid(char *string);
int				is_not_validate_args(int argc, char **string);
void			add_main_data(int argc, char **argv,
					t_philosophers_data *p_data);
t_fork			*create_forks(t_philosophers_data *p_data);
t_fork			create_fork(int id);
int				can_start_to_eat(t_philosopher *pPhilosopher);
void			create_philosophers(t_philosophers_data *p_data);
t_philosopher	create_philosopher(int id, t_philosophers_data *p_data);
void			create_threads(t_philosophers_data *p_data);
void			eat(t_philosopher *philosopher);
void			sleeping(t_philosopher *philosopher);
void			thinking(t_philosopher *philosopher);
void			*routine(void *arg);
void			stop_all(t_philosophers_data *pData, int j);
void			join_threads(t_philosophers_data *p_data, t_check *check);
void			free_all(t_philosophers_data *p_data, t_check *check);
int				is_stop_all(t_philosopher *philosopher);
void			*check_number_of_meals(void *arg);
int				ft_usleep(useconds_t time);
int				is_dead(t_philosopher *philosopher);
int				is_stopped(t_philosopher *philosopher);
void			*check_dead(void *arg);
void			check_all(t_philosophers_data *p_data, t_check *check);
long long int	get_time(void);
long long int	current_time(long long int start_time);
void			meal_counter(t_philosophers_data *p_data, int i, int *pInt);
void			philosopher_is_eating(t_philosopher *philosopher);
int				only_one_philosopher(t_philosopher *philosopher);

#endif
