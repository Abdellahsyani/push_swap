#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int	main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			int to_num = atoi(av[i]);
			printf("%d\n", to_num);
			i++;
		}
	}
	else
		printf("Error\n");
	return (0);
}
