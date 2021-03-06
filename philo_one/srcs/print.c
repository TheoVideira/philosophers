/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:34:54 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:35:32 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_status(int id, t_parameters *params, t_status status)
{
	long timestamp;

	pthread_mutex_lock(&(params->print_lock));
	if (params->someone_died)
	{
		pthread_mutex_unlock(&(params->print_lock));
		return ;
	}
	id = id + 1;
	timestamp = ft_gettime() - params->start_time;
	if (status == TAKING_FORKS)
		printf("%10ld %3d has taken a fork\n", timestamp, id);
	if (status == EATING)
		printf("%10ld %3d is eating\n", timestamp, id);
	if (status == SLEEPING)
		printf("%10ld %3d is sleeping\n", timestamp, id);
	if (status == THINKING)
		printf("%10ld %3d is thinking\n", timestamp, id);
	if (status == DEAD)
	{
		printf("%10ld %3d died\n", timestamp, id);
		params->someone_died = 1;
	}
	pthread_mutex_unlock(&(params->print_lock));
}
