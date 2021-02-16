/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:32:38 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:32:44 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	ft_destroy_mutex(t_parameters *params)
{
	int i;

	i = -1;
	if (params->forks)
	{
		while (++i < params->nb_philos)
			pthread_mutex_destroy(&(params->forks[i]));
		free(params->forks);
	}
	i = -1;
	if (params->protection)
	{
		while (++i < params->nb_philos)
			pthread_mutex_destroy(&(params->protection[i]));
		free(params->protection);
	}
	if (params->forks && params->protection)
	{
		pthread_mutex_destroy(&(params->print_lock));
		pthread_mutex_destroy(&(params->stop_lock));
	}
}

void		ft_destroy(t_parameters *params, t_philo_info **ph_info,
					pthread_t **philo, pthread_t **monitor)
{
	ft_destroy_mutex(params);
	if (*ph_info)
		free(*ph_info);
	if (*philo)
		free(*philo);
	if (*monitor)
		free(*monitor);
}

void		ft_failsafe(t_parameters *params, t_philo_info **ph_info,
					pthread_t **philo, pthread_t **monitor)
{
	params->forks = NULL;
	params->protection = NULL;
	*philo = NULL;
	*monitor = NULL;
	*ph_info = NULL;
}
