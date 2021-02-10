#include "philo_one.h"

void	get_forks(t_philo_info *philo, t_parameters *params)
{
//	if ((params->someone_died) || get_stop(params))
//		return ;
	/*if (!(philo->id % 2))
	{
		pthread_mutex_lock(&(params->forks[philo->id]));
		print_status(philo->id, params, TAKING_FORKS);
		if (!(philo->id))
			pthread_mutex_lock(&(params->forks[params->nb_philos - 1]));
		else
			pthread_mutex_lock(&(params->forks[philo->id - 1]));
		print_status(philo->id, params, TAKING_FORKS);
	}
	else
	{
		pthread_mutex_lock(&(params->forks[philo->id - 1]));
		print_status(philo->id, params, TAKING_FORKS);
		pthread_mutex_lock(&(params->forks[philo->id]));
		print_status(philo->id, params, TAKING_FORKS);
	}*/
	pthread_mutex_lock(&(params->forks[philo->id]));
	if (!(philo->id))
		pthread_mutex_lock(&(params->forks[params->nb_philos - 1]));
	else
		pthread_mutex_lock(&(params->forks[philo->id - 1]));
}

void	put_forks(t_philo_info *philo, t_parameters *params)
{
	pthread_mutex_unlock(&(params->forks[philo->id]));
	if (!(philo->id))
		pthread_mutex_unlock(&(params->forks[params->nb_philos - 1]));
	else
		pthread_mutex_unlock(&(params->forks[philo->id - 1]));
}

void	eating(t_philo_info *philo, t_parameters *params)
{
//	if ((params->someone_died) || get_stop(params))
//		return ;
	pthread_mutex_lock(&(params->protection[philo->id]));
	print_status(philo->id, params, EATING);
	if (params->must_eat)
		(philo->meals_eaten)++;
	if (params->must_eat && philo->meals_eaten == params->must_eat)
		inc_stop(params);
	philo->last_meal = ft_gettime();
	ft_sleep(params->time_to_eat);
    pthread_mutex_unlock(&(params->protection[philo->id]));
}

void	sleeping(t_philo_info *philo, t_parameters *params)
{
	if ((params->someone_died) || get_stop(params))
		return ;
	print_status(philo->id, params, SLEEPING);
	ft_sleep(params->time_to_sleep);
}

void	thinking(t_philo_info *philo, t_parameters *params)
{
//	if ((params->someone_died) || get_stop(params))
//		return ;
	print_status(philo->id, params, THINKING);
}