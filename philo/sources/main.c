#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophers_data *philosophers_data;
	t_check *check;

	validate_args(argc, argv);
	philosophers_data = malloc(sizeof (t_philosophers_data));
	check = malloc(sizeof(t_check));
	add_main_data(argc, argv, philosophers_data);
	create_forks(philosophers_data);
	create_philosophers(philosophers_data);
	create_threads(philosophers_data);
	check_all(philosophers_data, check);
	join_threads(philosophers_data, check);
	free_all(philosophers_data, check);
	return 0;
}












