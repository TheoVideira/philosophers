#include "philo_two.h"

static int	ft_isdigit(int c)
{
	return (!(c < '0' || c > '9'));
}

static int	ft_isspace(int c)
{
	return (c == 32 || !(c < '\t' || c > '\r'));
}

int		ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i += 1;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0') * sign;
		i += 1;
	}
	return (res);
}

void	ft_sleep(long milliseconds)
{
	long start;

	start = ft_gettime();
	while (ft_gettime() < start + milliseconds)
	{
		usleep(250);
	}
}

long	ft_gettime(void)
{	
	static struct timeval timeval;
	
	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);	
}