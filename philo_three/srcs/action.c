#include "philo_three.h"

void	get_forks(t_philo_info *philo, t_parameters *params)
{
	sem_wait(params->forks);
	print_status(philo->id, params, TAKING_FORKS);
	sem_wait(params->forks);	
	print_status(philo->id, params, TAKING_FORKS);
}

void	put_forks(t_parameters *params)
{
	sem_post(params->forks);
	sem_post(params->forks);
}

void	eating(t_philo_info *philo, t_parameters *params)
{
	sem_wait(params->protection[philo->id]);
	print_status(philo->id, params, EATING);
	if (params->must_eat)
		(philo->meals_eaten)++;
	if (params->must_eat && philo->meals_eaten == params->must_eat)
		inc_stop(params);
	philo->last_meal = ft_gettime();
	ft_sleep(params->time_to_eat);
    sem_post(params->protection[philo->id]);
}

void	sleeping(t_philo_info *philo, t_parameters *params)
{
	print_status(philo->id, params, SLEEPING);
	ft_sleep(params->time_to_sleep);
}

void	thinking(t_philo_info *philo, t_parameters *params)
{
	print_status(philo->id, params, THINKING);
}