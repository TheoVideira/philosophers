#include "philo_three.h"

void	print_status(int id, t_parameters *params, t_status status)
{
	long timestamp;

	sem_wait(params->print_lock);
	if (params->someone_died)
	{
		sem_post(params->print_lock);
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
		printf("%10ld %3d died\n", timestamp, id);
	if (status != DEAD)
		sem_post(params->print_lock);
}