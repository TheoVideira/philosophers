#include "philo_one.h"

int main(int argc, char **argv)
{
	t_parameters parameters;

	if (argc < 5 || argc > 6)
	{
		printf("You need between 4 and 5 parameters. You had %d.\n", argc - 1);
		return (1);
	}
	if (!check_inputs(argc, argv) || !set_parameters(&parameters, argv))
			return (1);
	return (0);
}