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
		{
			params->someone_died = 1;
			print_status(philo->id, params, DEAD);
		}
		pthread_mutex_unlock(&(params->protection[philo->id]));
		ft_sleep(6);
	}
	return (NULL);
}