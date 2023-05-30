#include "../includes/philosophers.h"

void add_main_data(int argc, char **argv, t_philosophers_data *p_data)
{
	p_data->number_of_philosophers = ft_atoi(argv[1]);
	p_data->number_of_forks = p_data->number_of_philosophers;
	p_data->time_to_die = ft_atoi(argv[2]);
	p_data->time_to_eat = ft_atoi(argv[3]);
	p_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		p_data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}

}

void validate_args(int argc, char **argv, t_philosophers_data *philosophers_data)
{
	if(argc == 5 || argc == 6)
	{
		if (argc == 6)
		{
			if(!is_valid(argv[5]))
				ft_error();
		}
		while(argc-- > 0)
		{
			if(!is_valid(argv[argc]))
				ft_error();
		}
	}
	else
		ft_error();
}

int	is_validate_atoi(const char *str)
{
	int				index;
	long long int	sign;
	long long int	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - '0');
		index++;
		if (check_overflow(res, sign))
			return (0);
	}
	return (1);
}

int	check_overflow(long long int res, long long int sign)
{
	if (res * sign > INT_MAX)
		return (1);
	if (res * sign < INT_MIN)
		return (1);
	return (0);
}
