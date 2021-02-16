/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:13:16 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:17:36 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define SEM_FORKS "/forks"
# define SEM_PRINT "/print"
# define SEM_STOP "/stop"
# define SEM_PROTEC_PREFIX "/protection_"

# define EXIT_DIED 42

typedef enum	e_status{
	TAKING_FORKS,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}				t_status;

/*
** Structures
*/
typedef struct	s_parameters
{
	int		nb_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	int		someone_died;
	int		stop;
	long	start_time;
	sem_t	*print_lock;
	sem_t	*stop_lock;
	sem_t	*forks;
	sem_t	**protection;
	char	**protec_name;
}				t_parameters;

typedef struct	s_philo_info
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	t_parameters	*parameters;
}				t_philo_info;

/*
** Utils functions
*/
int				ft_atoi(const char *str);
void			ft_sleep(long milliseconds);
long			ft_gettime(void);

/*
** Utils2 functions
*/
int				ft_uint_len(unsigned int n);
void			ft_uitoa(unsigned int n, char *str);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
** Utils3 functions
*/
void			*ft_calloc(size_t count, size_t size);

/*
** Init functions
*/
int				check_inputs(int ac, char **av);
int				init_parameters(t_parameters *parameters, char **av);
int				init_philosophers(t_philo_info **philos, t_parameters *params);
void			print_parameters(t_parameters *parameters);
int				init_threads
			(pid_t **philo, t_parameters *params);

/*
** Simulation function
*/
void			launch_simulation(t_philo_info *philo_info, pid_t **philo,
			int nb_philos);

/*
** Action functions
*/
void			get_forks(t_philo_info *philo, t_parameters *params);
void			put_forks(t_parameters *params);
void			eating(t_philo_info *philo, t_parameters *params);
void			sleeping(t_philo_info *philo, t_parameters *params);
void			thinking(t_philo_info *philo, t_parameters *params);

/*
** Print function
*/
void			print_status(int id, t_parameters *params, t_status status);

/*
** Monitor function
*/
void			*monitoring(void *philosopher);

/*
** Stop functions
*/
void			inc_stop(t_parameters *params);
int				get_stop(t_parameters *params);

/*
** Destroy function
*/
void			ft_destroy(t_parameters *params, t_philo_info **ph_info,
			pid_t **philo);
void			ft_failsafe(t_parameters *params, t_philo_info **ph_info,
			pid_t **philo);

/*
** Semaphore function
*/
int				create_semaphores(t_parameters *params);

#endif
