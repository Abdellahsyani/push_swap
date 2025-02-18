/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:43:35 by asyani            #+#    #+#             */
/*   Updated: 2025/01/26 15:46:16 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * free_split_result _ fucntion to free the garbage of split
 * @split_result: the array that will be freed
 *
 */
void	free_split_result(char **split_result)
{
	int	i;

	i = 0;
	if (!split_result)
		return ;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

/**
 * clean_stack _ function to check the stack: charcter - + ...
 * @av: the stack that we want to check
 *
 * return: 0 if stack clean; 1 if stack not clean
 */
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
			if (sign == 1 || (i > 0 && is_digit(av[i - 1]))
				|| (!is_digit(av[i + 1])))
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

/**
 * check_dup _ checking for duplicate number 
 * @stack_a: stack to check
 *
 * return: 0 if success 1 if failure
 */
int	check_dup(t_list *stack_a)
{
	int		dup_num;
	t_list	*temp;

	while (stack_a)
	{
		dup_num = stack_a->data;
		temp = stack_a->next;
		while (temp)
		{
			if (temp->data == dup_num)
			{
				return (1);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

/**
 * verify_dup _ function for helping in checking stack
 * @av: the stack that will be verified
 *
 */
void	verify_dup(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (clean_stack(av[i]) != 0)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

/**
 * verify_stack _ preparing the stack for sort
 * @stack_a: the stack that will be fill it
 * @ac: the size of the argumenent
 * @av: the argument that will check and fill stack
 *
 * return: stack_a
 */
t_list	*verify_stack(t_list *stack_a, int ac, char **av)
{
	int		i;
	char	**dup;
	int		j;
	long	num;

	verify_dup(av);
	i = 1;
	while (i < ac)
	{
		dup = ft_split(av[i], ' ');
		j = 0;
		if (!dup || !dup[0])
			ft_perror(dup, &stack_a);
		while (dup[j])
		{
			num = ft_atoi(dup[j], dup, &stack_a);
			add_to_stack(&stack_a, (int)num);
			j++;
		}
		free_split_result(dup);
		i++;
	}
	return (stack_a);
}
