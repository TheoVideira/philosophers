#include "philo_one.h"

int	check_inputs(int ac, char **av)
{
	if (ft_atoi(av[1]) > 1
		&& ft_atoi(av[2]) > 0
		&& ft_atoi(av[3]) > 0
		&& ft_atoi(av[4]) > 0
		&& ((ac == 5) || (ac == 6 && ft_atoi(av[5]) > 0)))
		return (1);
	if (ft_atoi(av[1]) < 2)
		printf("MIN VALUE number_of_philosopher : 2\n");
	if (ft_atoi(av[2]) < 1)
		printf("MIN VALUE time_to_die : 1\n");
	if (ft_atoi(av[3]) < 1)
		printf("MIN VALUE time_to_eat : 1\n");
	if (ft_atoi(av[4]) < 1)
		printf("MIN VALUE time_to_sleep : 1\n");
	if (ac == 6 && ft_atoi(av[5]) < 1)
		printf("MIN VALUE number_of_time_each_philosopher_must_eat : 1\n");
	return (0);
}

int	init_parameters(t_parameters *params, char **av)
{
	int i;

	params->nb_philos = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	if (!(av[5]))
		params->must_eat = 0;
	else
		params->must_eat = ft_atoi(av[5]);
	params->someone_died = 0;
	params->forks = malloc(sizeof(pthread_mutex_t) * params->nb_philos);
	if (!(params->forks))
		return (0);
	i = -1;
	while (++i < params->nb_philos)
		pthread_mutex_init(&(params->forks[i]), 0);
	return (1);
}

int		init_philosophers(t_philosopher **philos, t_parameters *params)
{
	int i;

	i = -1;
	*philos = malloc(sizeof(t_philosopher) * params->nb_philos);
	if (!(*philos))
		return (0);
	while(++i < params->nb_philos)
	{
		(*philos)[i].id = i;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].parameters = params;
	}
	return (1);
}

void	print_parameters(t_parameters *parameters)
{
	printf("N_P = %d\n", parameters->nb_philos);
	printf("TTD = %d\n", parameters->time_to_die);
	printf("TTE = %d\n", parameters->time_to_eat);
	printf("TTS = %d\n", parameters->time_to_sleep);
	printf("MMS = %d\n", parameters->must_eat);
	printf("SD? = %d\n", parameters->someone_died);
	printf("Time elapsed since beggining = %ld ms\n", ft_gettime() - parameters->start_time);
}