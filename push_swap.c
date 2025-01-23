/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:39:50 by asyani            #+#    #+#             */
/*   Updated: 2025/01/17 23:46:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * find_min _ function to find the mini value in stack
 * @stack_a: stack to scane for small value
 *
 * return: min value node
 */
t_list	*find_min(t_list **stack_a)
{
	t_list	*temp;
	t_list	*min_node;

	temp = *stack_a;
	min_node = NULL;
	while (temp)
	{
		if (temp->index == -1 && (min_node == NULL
				|| temp->data < min_node->data))
		{
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

/**
 * index_stack _ indexing stack to sort it easily
 * @stack_a: the stack that will be sorted
 */
void	index_stack(t_list **stack_a)
{
	int		index;
	t_list	*node;

	index = 0;
	node = find_min(stack_a);
	while (node)
	{
		node->index = index;
		index++;
		node = find_min(stack_a);
	}
}

/**
 * count_elements _ count how many node we have in stack
 * stack: stack to be counted
 *
 * return: number of element that we find
 */
int	count_elements(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b, int num_c, int ch_s)
{
	int	remaining;
	t_list	*temp;
	int	min_range;
	int	max_range;
	int	i;
	int	size;

	i = 0;
	size = count_elements(*stack_a);
	while (i < num_c)
	{
		min_range = i * ch_s;
		max_range = min_range + ch_s;
		if (max_range > size)
			max_range = size;
		remaining = 0;
		temp = *stack_a;
		while (temp)
		{
			if (temp->index >= min_range && temp->index < max_range)
				remaining++;
			temp = temp->next;
		}
		while (remaining > 0)
		{
			if ((*stack_a)->index >= min_range && (*stack_a)->index < max_range)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index < (min_range + max_range) / 2)
					rb(stack_b);
				remaining--;
			}
			else
				ra(stack_a);
		}
		i++;
	}
}

void	stack_range(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	num_chunks;

	size = count_elements(*stack_a);
	if (size <= 100)
		chunk_size = size / 5;
	else
		chunk_size = size / 9;
	if (chunk_size < 10)
		chunk_size = 10;
	num_chunks = (size + chunk_size - 1) / chunk_size;
	fill_stack_b(stack_a, stack_b, num_chunks, chunk_size);
}

int	find_max(t_list **stack_b)
{
	t_list	*temp;
	int		max;
	int		max_pos;
	int		curr_pos;

	temp = *stack_b;
	max = -1;
	max_pos = 0;
	curr_pos = 0;
	while (temp)
	{
		if (temp->index > max)
		{
			max = temp->index;
			max_pos = curr_pos;
		}
		curr_pos++;
		temp = temp->next;
	}
	return (max_pos);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_pos;

	stack_range(stack_a, stack_b);
	size = count_elements(*stack_b);
	while (size > 0)
	{
		max_pos = find_max(stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_pos++ < size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

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
			i++;
			continue;
		}
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == ' ')
		{
			if (av[i] == ' ')
			{
				i++;
				continue;
			}
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	check_dup(t_list *stack_a)
{
	int	dup_num;
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

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
	{
		return (0);
	}
	stack_a = verify_stack(stack_a, ac, av);
	if (check_dup(stack_a) != 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	size = count_nodes(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else
	{
		index_stack(&stack_a);
		sort_stack(&stack_a, &stack_b);
	}
	t_list *temp = stack_a;
	while (temp)
	{
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
