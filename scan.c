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

/**
 * check_dup _ checking for duplicate number 
 * @stack_a: stack to check
 *
 * return: 0 if success 1 if failure
 */
int	check_dup(t_list *stack_a)
{
	int	dup_num;
	t_list	*temp;

	while (stack_a)
	{
		if (stack_a->data > MAX_INT || stack_a < MIN_INT)
			return (1);
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
	int	i;
	char	**dup;
	int	j;
	int	num;

	verify_dup(av);
	i = 1;
	while (i < ac)
	{
		dup = ft_split(av[i], ' ');
		j = 0;
		while (dup[j])
		{
			num = ft_atoi(dup[j]);
			add_to_stack(&stack_a, num);
			j++;
		}
		free(dup);
		i++;
	}
	return (stack_a);
}
