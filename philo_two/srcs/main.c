#include "philo_two.h"

int	main(int ac, char **av)
{
	t_parameters params;
	t_philo_info *philo_info;
	pthread_t *philo;
	pthread_t *monitor;

	params.start_time = ft_gettime();
	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("You need at least 4 arguments, you had %d\n", ac - 1);
		else
			printf("You need at most 5 arguments, you had %d\n", ac - 1);
		return(1);
	}
	if (!check_inputs(ac, av) || !init_parameters(&params, av)
		|| !init_threads(&philo, &monitor, &params)
		|| !init_philosophers(&philo_info, &params))
	{
		ft_destroy(&params, &philo_info, &philo, &monitor);
		return (1);
	}
	launch_simulation(philo_info, philo, monitor);
	ft_destroy(&params, &philo_info, &philo, &monitor);
	return (0);
}
