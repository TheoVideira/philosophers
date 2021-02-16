/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:56:59 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 16:57:59 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	init_one_sem(sem_t **sem, char *name, int init)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 777, init);
	if (*sem == SEM_FAILED)
		return (0);
	return (1);
}

static int	create_names(t_parameters *params)
{
	int i;
	int len;
	int prefix_len;

	i = -1;
	prefix_len = ft_strlen(SEM_PROTEC_PREFIX);
	params->protec_name = malloc(sizeof(char *) * params->nb_philos);
	if (!(params->protec_name))
		return (0);
	while (++i < params->nb_philos)
	{
		len = prefix_len + ft_uint_len(i) + 1;
		params->protec_name[i] = malloc(sizeof(char) * (len + 1));
		if (!(params->protec_name[i]))
			return (0);
		ft_memcpy(params->protec_name[i], SEM_PROTEC_PREFIX, prefix_len);
		ft_uitoa(i, params->protec_name[i] + prefix_len);
	}
	return (1);
}

int			create_semaphores(t_parameters *params)
{
	int i;

	params->protection = malloc(sizeof(sem_t *) * params->nb_philos);
	if (!(params->protection))
		return (0);
	if (!(create_names(params)))
		return (0);
	if (!(init_one_sem(&(params->forks), SEM_FORKS, params->nb_philos)))
		return (0);
	if (!(init_one_sem(&(params->print_lock), SEM_PRINT, 1)))
		return (0);
	if (!(init_one_sem(&(params->stop_lock), SEM_STOP, 1)))
		return (0);
	i = -1;
	while (++i < params->nb_philos)
	{
		if (!(init_one_sem(&(params->protection[i]),
			params->protec_name[i], 1)))
			return (0);
	}
	return (1);
}
