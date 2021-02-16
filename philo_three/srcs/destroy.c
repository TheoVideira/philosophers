/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:18:22 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:18:41 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	ft_destroy_semaphores(t_parameters *params)
{
	int i;

	i = -1;
	if (params->forks)
		sem_close(params->forks);
	if (params->print_lock)
		sem_close(params->print_lock);
	if (params->stop_lock)
		sem_close(params->stop_lock);
	i = -1;
	if (params->protection)
	{
		while (++i < params->nb_philos)
		{
			if (params->protection[i])
				sem_close(params->protection[i]);
			else
				break ;
		}
		free(params->protection);
	}
}

void		ft_destroy(t_parameters *params, t_philo_info **ph_info,
				pid_t **philo)
{
	int i;

	i = -1;
	ft_destroy_semaphores(params);
	if (*ph_info)
		free(*ph_info);
	if (*philo)
		free(*philo);
	if (params->protec_name)
	{
		while (++i < params->nb_philos)
		{
			if (params->protec_name[i])
				free(params->protec_name[i]);
			else
				break ;
		}
		free(params->protec_name);
	}
}

void		ft_failsafe(t_parameters *params, t_philo_info **ph_info,
				pid_t **philo)
{
	params->print_lock = NULL;
	params->stop_lock = NULL;
	params->forks = NULL;
	params->protection = NULL;
	params->protec_name = NULL;
	*philo = NULL;
	*ph_info = NULL;
}
