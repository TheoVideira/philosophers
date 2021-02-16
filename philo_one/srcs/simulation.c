/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:35:42 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:37:49 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*routine(void *philosopher)
{
	t_philo_info	*philo;
	t_parameters	*params;

	philo = (t_philo_info *)philosopher;
	params = philo->parameters;
	while (!(params->someone_died) && !get_stop(params))
	{
		get_forks(philo, params);
		eating(philo, params);
		put_forks(philo, params);
		sleeping(philo, params);
		thinking(philo, params);
	}
	return (NULL);
}

void		launch_simulation(t_philo_info *philo_info, pthread_t *philo,
				pthread_t *monitor, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		pthread_create(&(philo[i]), NULL, routine, &(philo_info[i]));
		pthread_create(&(monitor[i]), NULL, monitoring, &(philo_info[i]));
		i += 2;
	}
	ft_sleep(1);
	i = 1;
	while (i < nb_philos)
	{
		pthread_create(&(philo[i]), NULL, routine, &(philo_info[i]));
		pthread_create(&(monitor[i]), NULL, monitoring, &(philo_info[i]));
		i += 2;
	}
	i = -1;
	while (++i < nb_philos)
	{
		pthread_join(philo[i], NULL);
		pthread_join(monitor[i], NULL);
	}
}
