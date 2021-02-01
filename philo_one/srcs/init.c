#include "philo_one.h"

int	check_inputs(int argc, char **argv)
{
	if (ft_atoi(argv[1]) > 1 &&
		ft_atoi(argv[2]) > 0 &&
		ft_atoi(argv[3]) > 0 &&
		ft_atoi(argv[4]) > 0 &&
		((argc == 5) || (argc == 6 && ft_atoi(argv[5]) > 0)))
		return (1);
	if (ft_atoi(argv[1]) < 2)
		printf("MIN VALUE number_of_philosopher : 2\n");
	if (ft_atoi(argv[2]) < 1)
		printf("MIN VALUE time_to_die : 1\n");
	if (ft_atoi(argv[3]) < 1)
		printf("MIN VALUE time_to_eat : 1\n");
	if (ft_atoi(argv[4]) < 1)
		printf("MIN VALUE time_to_sleep : 1\n");
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		printf("MIN VALUE number_of_time_each_philosopher_must_eat : 1\n");
	return (0);
}

int set_parameters(t_parameters *parameters, char **argv)
{
	parameters->number_of_philosopher = ft_atoi(argv[1]);
	parameters->time_to_die = ft_atoi(argv[2]);
	parameters->time_to_eat = ft_atoi(argv[3]);
	parameters->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		parameters->must_eat = ft_atoi(argv[5]);
	else
		parameters->must_eat = 0;
	return (1);
}

int set_forks(t_parameters *t_parameters)
{
	
}