#include "philo_two.h"

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
					pthread_t **philo, pthread_t **monitor)
{
	int i;

	i = -1;
	ft_destroy_semaphores(params);
	if (*ph_info)
		free(*ph_info);
	if (*philo)
		free(*philo);
	if (*monitor)
		free(*monitor);
	if (params->protec_name)
	{
		while (++i < params->nb_philos)
		{
			if (params->protec_name[i])
				free(params->protec_name[i]);
			else
				break;
		}
		free(params->protec_name);
	}
}

void		ft_failsafe(t_parameters *params, t_philo_info **ph_info,
					pthread_t **philo, pthread_t **monitor)
{
	params->print_lock = NULL;
	params->stop_lock = NULL;
	params->forks = NULL;
	params->protection = NULL;
	params->protec_name = NULL;
	*philo = NULL;
	*monitor = NULL;
	*ph_info = NULL;
}