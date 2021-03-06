/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:22:18 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:22:18 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** 'stop' is the variable that equals the number of philosopher that have eaten
** at least 'must_east' meals
*/

void	inc_stop(t_parameters *params)
{
	sem_wait(params->stop_lock);
	(params->stop)++;
	sem_post(params->stop_lock);
}

int		get_stop(t_parameters *params)
{
	int stop_sim;

	sem_wait(params->stop_lock);
	stop_sim = (params->stop == params->nb_philos);
	sem_post(params->stop_lock);
	return (stop_sim);
}
