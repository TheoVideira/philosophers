#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <pthread.h>

typedef enum		e_status{
	WAITING,
	DEAD,
	EATING,
	SLEEPING
}					t_status;

typedef struct		s_parameters
{
	int 			number_of_philosopher;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			must_eat;
	pthread_mutex_t	*forks;
}					t_parameters;

typedef struct		t_philosopher
{
	int				id;
	int				eaten_meals;
	unsigned int	last_meal;
	t_status		status;
}					s_philosopher;


/*utils function*/
int	ft_atoi(const char *str);

/*init function*/
int	check_inputs(int argc, char **argv);
int set_parameters(t_parameters *parameters, char **argv);

#endif