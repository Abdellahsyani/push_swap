/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:53:55 by asyani            #+#    #+#             */
/*   Updated: 2025/01/24 22:54:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	clean_stack(char *av)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (av[i] == ' ' || av[i] == '\t')
		i++;
	while (av[i])
	{
		if (av[i] == '-' || av[i] == '+')
		{
			if (sign == 1)
				return (1);
			sign = 1;
		}
		else if ((av[i] >= '0' && av[i] <= '9') || av[i] == ' ')
			sign = 0;
		else
			return (1);
		i++;
	}
	return (0);
}

void	verify(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (clean_stack(av[i]) != 0)
		{
			putstr("KO\n");
			exit(1);
		}
		else
		{
			putstr("OK\n");
			exit(0);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**dup;
	int	i;
	char	*arr[1024];
	int	j;
	int	num;

	verify(av);
	i = 1;
	while (i < ac)
	{
		dup = ft_split(av[i], ' ');
		j = 0;
		while (dup[j])
		{
			num = atoi(dup[j]);
			arr[j] = num;
			j++;
		}
		i++;
	}
	//check_dup(arr);
	return (0);
}
