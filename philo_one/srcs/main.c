#include "philo_one.h"

int	main(int ac, char **av)
{
	t_parameters params;
	t_philosopher *philos;

	params.start_time = ft_gettime();
	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("You need at least 4 arguments, you had %d\n", ac - 1);
		else
			printf("You need at most 5 arguments, you had %d\n", ac - 1);
		return(1);
	}
	if (!check_inputs(ac, av)
		|| !init_parameters(&params, av)
		|| !init_philosophers(&philos, &params))
	{
		//function that free everything here.
		return (1);
	}
	launch_simulation(philos, &params);
	return (0);
}
