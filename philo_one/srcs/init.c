/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:32:57 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:33:24 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	params->stop = 0;
	params->forks = malloc(sizeof(pthread_mutex_t) * params->nb_philos);
	params->protection = malloc(sizeof(pthread_mutex_t) * params->nb_philos);
	if (!(params->forks) || !(params->protection))
		return (0);
	i = -1;
	while (++i < params->nb_philos)
	{
		pthread_mutex_init(&(params->forks[i]), 0);
		pthread_mutex_init(&(params->protection[i]), 0);
	}
	pthread_mutex_init(&(params->print_lock), 0);
	pthread_mutex_init(&(params->stop_lock), 0);
	return (1);
}

int	init_philosophers(t_philo_info **philo_info, t_parameters *params)
{
	int i;

	i = -1;
	*philo_info = malloc(sizeof(t_philo_info) * params->nb_philos);
	if (!(*philo_info))
		return (0);
	params->start_time = ft_gettime();
	while (++i < params->nb_philos)
	{
		(*philo_info)[i].id = i;
		(*philo_info)[i].meals_eaten = 0;
		(*philo_info)[i].parameters = params;
		(*philo_info)[i].last_meal = params->start_time;
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
