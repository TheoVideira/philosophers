/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:01:58 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:02:27 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		*(char *)(b + i++) = (unsigned char)c;
	return (b);
}

void		*ft_calloc(size_t count, size_t size)
{
	void *p;

	if ((p = malloc(count * size)))
		ft_memset(p, 0, count * size);
	return (p);
}
