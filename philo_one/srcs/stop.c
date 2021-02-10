#include "philo_one.h"

/*
** 'stop' is the variable that equals the number of philosopher that have eaten
** at least 'must_east' meals
*/

void	inc_stop(t_parameters *params)
{
	pthread_mutex_lock(&(params->stop_lock));
	(params->stop)++;
	pthread_mutex_unlock(&(params->stop_lock));
}

int		get_stop(t_parameters *params)
{
	int stop_sim;

	pthread_mutex_lock(&(params->stop_lock));
	stop_sim = (params->stop == params->nb_philos);
	pthread_mutex_unlock(&(params->stop_lock));
	return (stop_sim);
}