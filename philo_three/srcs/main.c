/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:19:19 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:19:21 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	main(int ac, char **av)
{
	t_parameters	params;
	t_philo_info	*philo_info;
	pid_t			*philo;

	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("You need at least 4 arguments, you had %d\n", ac - 1);
		else
			printf("You need at most 5 arguments, you had %d\n", ac - 1);
		return (1);
	}
	ft_failsafe(&params, &philo_info, &philo);
	if (!check_inputs(ac, av) || !init_parameters(&params, av)
		|| !init_threads(&philo, &params)
		|| !init_philosophers(&philo_info, &params))
	{
		ft_destroy(&params, &philo_info, &philo);
		return (1);
	}
	launch_simulation(philo_info, &philo, params.nb_philos);
	ft_destroy(&params, &philo_info, &philo);
	return (0);
}
