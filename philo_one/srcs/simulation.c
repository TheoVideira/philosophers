#include "philo_one.h"

static void	print_status(int id, long start_time, t_status status)
{
	long timestamp;

	id = id + 1;
	timestamp = ft_gettime() - start_time;
	if (status == TAKING_FORKS)
		printf("%10ld %3d has taken a fork\n", timestamp, id);
	if (status == EATING)
		printf("%10ld %3d is eating\n", timestamp, id);
	if (status == SLEEPING)
		printf("%10ld %3d is sleeping\n", timestamp, id);
	if (status == THINKING)
		printf("%10ld %3d is thinking\n", timestamp, id);
	if (status == DEAD)
		printf("%10ld %3d died\n", timestamp, id);
}

static void	get_forks(t_philosopher *philo, t_parameters *params)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(&(params->forks[philo->id]));
		print_status(philo->id, params->start_time, TAKING_FORKS);
		if (!(philo->id))
			pthread_mutex_lock(&(params->forks[params->nb_philos - 1]));
		else
			pthread_mutex_lock(&(params->forks[philo->id - 1]));
		print_status(philo->id, params->start_time, TAKING_FORKS);
	}
	else
	{
		pthread_mutex_lock(&(params->forks[philo->id - 1]));
		print_status(philo->id, params->start_time, TAKING_FORKS);
		pthread_mutex_lock(&(params->forks[philo->id]));
		print_status(philo->id, params->start_time, TAKING_FORKS);
	}
}

static void	put_forks(t_philosopher *philo, t_parameters *params)
{
	pthread_mutex_unlock(&(params->forks[philo->id]));
	if (!(philo->id))
		pthread_mutex_unlock(&(params->forks[params->nb_philos - 1]));
	else
		pthread_mutex_unlock(&(params->forks[philo->id - 1]));

}

static void	*routine(void *philosopher)
{
	t_philosopher	*philo;
	t_parameters	*params;

	philo = (t_philosopher *)philosopher;
	params = philo->parameters;
	while(!(params->someone_died))
	{
		get_forks(philo, params);
		print_status(philo->id, params->start_time, EATING);
		ft_sleep(params->time_to_eat);
		put_forks(philo, params);
		print_status(philo->id, params->start_time, SLEEPING);
		ft_sleep(params->time_to_sleep);
		print_status(philo->id, params->start_time, THINKING);
	}
	return NULL;
}

void		launch_simulation(t_philosopher *philos, t_parameters *params)
{
	int	i;

	i = -1;
	params->start_time = ft_gettime();
	while(++i < params->nb_philos)
	{
		philos[i].last_meal = params->start_time;
		pthread_create(&(philos[i].thread), NULL, routine, &(philos[i]));
	}
	while(--i >= 0)
	{
		pthread_join(philos[i].thread, NULL);
	}
}