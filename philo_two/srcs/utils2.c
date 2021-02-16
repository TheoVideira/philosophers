/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:01:36 by tvideira          #+#    #+#             */
/*   Updated: 2021/02/16 17:01:40 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	ft_power(int n, int p)
{
	int res;

	res = 1;
	if (p < 0)
		return (0);
	if (!p || n == 1)
		return (1);
	if (n == -1)
		return ((p % 2) ? -1 : 1);
	while (p)
	{
		res *= n;
		p -= 1;
	}
	return (res);
}

int			ft_uint_len(unsigned int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i += 1;
	return (i);
}

void		ft_uitoa(unsigned int n, char *str)
{
	size_t	i;
	size_t	j;

	i = ft_uint_len(n);
	j = 0;
	while (i > 0)
	{
		str[j++] = n / ft_power(10, i) + '0';
		n -= n / ft_power(10, i) * ft_power(10, i);
		i--;
	}
	str[j++] = n + '0';
	str[j] = '\0';
}

size_t		ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		i += 1;
	}
	return (dst);
}
