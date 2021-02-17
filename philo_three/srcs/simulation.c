/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:21:06 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/17 09:13:18 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	routine(void *philosopher)
{
	pthread_t		monitor;
	t_philo_info	*philo;
	t_parameters	*params;

	pthread_create(&monitor, NULL, monitoring, philosopher);
	pthread_detach(monitor);
	philo = (t_philo_info *)philosopher;
	params = philo->parameters;
	while (!(params->someone_died))
	{
		get_forks(philo, params);
		eating(philo, params);
		put_forks(params);
		if (params->must_eat && philo->meals_eaten == params->must_eat)
			break ;
		sleeping(philo, params);
		thinking(philo, params);
	}
	if (params->someone_died)
		exit(EXIT_DIED);
	else
		exit(0);
}

static void	kill_processes(pid_t **philo, int nb_philos)
{
	int i;
	int status;

	i = -1;
	while (++i < nb_philos)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_DIED)
		{
			i = -1;
			while (++i < nb_philos)
				if ((*philo)[i])
					kill((*philo)[i], SIGINT);
			break ;
		}
	}
}

void		launch_simulation(t_philo_info *philo_info, pid_t **philo,
				int nb_philos)
{
	int	i;

	i = -1;
	while (++i < nb_philos)
	{
		(*philo)[i] = fork();
		if ((*philo)[i] == 0)
			routine(&(philo_info[i]));
		else if ((*philo)[i] == -1)
		{
			kill_processes(philo, nb_philos);
			printf("Error while creating the processes\n");
			return ;
		}
		usleep(10);
	}
	kill_processes(philo, nb_philos);
}
