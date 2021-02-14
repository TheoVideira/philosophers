#include "philo_two.h"

static void	*routine(void *philosopher)
{
	t_philo_info	*philo;
	t_parameters	*params;

	philo = (t_philo_info *)philosopher;
	params = philo->parameters;
	while(!(params->someone_died) && !get_stop(params))
	{
		get_forks(philo, params);
        eating(philo, params);
		put_forks(params);
        sleeping(philo, params);
        thinking(philo, params);				
	}
	return (NULL);
}

void		launch_simulation
			(t_philo_info *philo_info, pthread_t *philo, pthread_t *monitor)
{
	int	i;
	t_parameters *params;

	params = philo_info[0].parameters;
	i = 0;
	params->start_time = ft_gettime();
	while(i < params->nb_philos)
	{
		philo_info[i].last_meal = params->start_time;
		philo_info[i].meals_eaten = 0;
		pthread_create(&(philo[i]), NULL, routine, &(philo_info[i]));
		pthread_create(&(monitor[i]), NULL, monitoring, &(philo_info[i]));
		i+=2;
	}
	i = 1;
	while(i < params->nb_philos)
	{
		philo_info[i].last_meal = params->start_time;
		philo_info[i].meals_eaten = 0;
		pthread_create(&(philo[i]), NULL, routine, &(philo_info[i]));
		pthread_create(&(monitor[i]), NULL, monitoring, &(philo_info[i]));
		i+=2;
	}
	while(--i >= 0)
	{
		pthread_join(philo[i], NULL);
		pthread_join(monitor[i], NULL);
	}	
}