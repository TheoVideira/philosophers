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
	int				stop;
	long			start_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*protection;
}t_parameters;

typedef struct s_philo_info
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	t_parameters	*parameters;
}t_philo_info;


/*
** Utils functions
*/
int		ft_atoi(const char *str);
void	ft_sleep(long milliseconds);
long	ft_gettime(void);

/*
** Init functions
*/
int		check_inputs(int ac, char **av);
int		init_parameters(t_parameters *parameters, char **av);
int		init_philosophers(t_philo_info **philos, t_parameters *params);
void	print_parameters(t_parameters *parameters);
int		init_threads
			(pthread_t **philo, pthread_t **monitor, t_parameters *params);

/*
** Simulation function
*/
void	launch_simulation(t_philo_info *philo_info, pthread_t *philo,
			pthread_t *monitor, int nb_philos);


/*
** Action functions
*/
void	get_forks(t_philo_info *philo, t_parameters *params);
void	put_forks(t_philo_info *philo, t_parameters *params);
void	eating(t_philo_info *philo, t_parameters *params);
void	sleeping(t_philo_info *philo, t_parameters *params);
void	thinking(t_philo_info *philo, t_parameters *params);


/*
** Print function
*/
void	print_status(int id, t_parameters *params, t_status status);

/*
** Monitor function
*/
void    *monitoring(void *philosopher);

/*
** Stop functions
*/
void	inc_stop(t_parameters *params);
int		get_stop(t_parameters *params);

/*
** Destroy functions
*/
void	ft_destroy(t_parameters *params, t_philo_info **ph_info,
			pthread_t **philo, pthread_t **monitor);
void	ft_failsafe(t_parameters *params, t_philo_info **ph_info,
			pthread_t **philo, pthread_t **monitor);


#endif