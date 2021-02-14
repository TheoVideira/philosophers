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
	pthread_mutex_destroy(&(params->print_lock));
	pthread_mutex_destroy(&(params->stop_lock));
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