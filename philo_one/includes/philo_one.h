#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_status{
	TAKING_FORKS,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}t_status;

/*
** Structures
*/
typedef struct s_parameters
{
	int				nb_philos;	
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				someone_died;
	long			start_time;
	pthread_mutex_t	*forks;
}t_parameters;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	t_parameters	*parameters;
	pthread_t 		thread;
}t_philosopher;


/*
** Utils function
*/
int		ft_atoi(const char *str);
void	ft_sleep(long milliseconds);
long	ft_gettime(void);

/*
** Init function
*/
int		check_inputs(int ac, char **av);
int		init_parameters(t_parameters *parameters, char **av);
int		init_philosophers(t_philosopher **philos, t_parameters *params);
void	print_parameters(t_parameters *parameters);


/*
** Simulation function
*/
void    launch_simulation(t_philosopher *philos, t_parameters *params);

#endif