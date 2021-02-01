#include "philo_one.h"

static int  ft_isdigit(int c)
{
	return (!(c < '0' || c > '9'));
}

static int	ft_isspace(int c)
{
	return (c == 32 || !(c < '\t' || c > '\r'));
}

int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	while (ft_isspace(*(str + i)))
		i += 1;
	sign = (*(str + i) == '-') ? -1 : 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i += 1;
	while (ft_isdigit(*(str + i)))
	{
		res = (res * 10) + ((*(str + i) - '0') * sign);
		i += 1;
	}
	return (res);
}