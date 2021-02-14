#include "philo_two.h"

static void *ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		*(char *)(b + i++) = (unsigned char)c;
	return (b);
}

void	    *ft_calloc(size_t count, size_t size)
{
	void *p;

	if ((p = malloc(count * size)))
        ft_memset(p, 0, count * size);
	return (p);
}