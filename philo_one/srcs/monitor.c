/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:00 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:34:33 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*monitoring(void *philosopher)
{
	t_philo_info	*philo;
	t_parameters	*params;

	philo = (t_philo_info *)philosopher;
	params = philo->parameters;
	while (!(params->someone_died) && !get_stop(params))
	{
		pthread_mutex_lock(&(params->protection[philo->id]));
		if (ft_gettime() > philo->last_meal + params->time_to_die)
			print_status(philo->id, params, DEAD);
		pthread_mutex_unlock(&(params->protection[philo->id]));
		ft_sleep(8);
	}
	return (NULL);
}
