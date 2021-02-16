#include "philo_three.h"

void	*monitoring(void *philosopher)
{
	t_philo_info	*philo;
	t_parameters	*params;

	philo = (t_philo_info *)philosopher;
	params = philo->parameters;
	while (!(params->someone_died) && !get_stop(params))
	{
		sem_wait(params->protection[philo->id]);
		if (ft_gettime() > philo->last_meal + params->time_to_die)
			{
				print_status(philo->id, params, DEAD);
				params->someone_died = 1;
				exit(EXIT_DIED);
			}
		sem_post(params->protection[philo->id]);
		ft_sleep(6);
	}
	return (NULL);
}