#include <stdbool.h>
#include "../includes/philosophers.h"

void validate_args(int argc, char **string)
{
	if (argc < 5 || argc > 6)
	{
		ft_error();
	}
	if (!is_valid(string[1]) || !is_valid(string[2]) || !is_valid(string[3]) || !is_valid(string[4]))
	{
		ft_error();
	}
	if (argc == 6 && !is_valid(string[5]))
	{
		ft_error();
	}
}

int	is_valid(char *string)
{
	if (!ft_strisdigit(string))
	{
		return (0);
	}
	return (1);
}

int	ft_strisdigit(char *string)
{
	if (!*string)
		return (0);
	if (*string == '-' && *(string + 1) == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}

int ft_isdigit(char i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

long long int ft_atoi(char *string)
{
	int i;
	int sign;
	long long int res;

	i = 0;
	sign = 1;
	res = 0;
	if (string[i] == '-')
		sign = -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		res = res * 10 + string[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}