#include "philo_two.h"

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
	params->nb_philos = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	if (!(av[5]))
		params->must_eat = 0;
	else
		params->must_eat = ft_atoi(av[5]);
	params->someone_died = 0;
	params->stop = 0;
	return (create_semaphores(params));
}

int	init_philosophers(t_philo_info **philo_info, t_parameters *params)
{
	int i;

	i = -1;
	*philo_info = malloc(sizeof(t_philo_info) * params->nb_philos);
	if (!(*philo_info))
		return (0);
	while(++i < params->nb_philos)
	{
		(*philo_info)[i].id = i;
		(*philo_info)[i].meals_eaten = 0;
		(*philo_info)[i].parameters = params;
	}
	return (1);
}

int	init_threads(pthread_t **philo, pthread_t **monitor, t_parameters *params)
{
	*philo = malloc(sizeof(t_philo_info) * params->nb_philos);
	*monitor = malloc(sizeof(t_philo_info) * params->nb_philos);
	if (!(*philo) || !(*monitor))
		return (0);
	return (1);
}