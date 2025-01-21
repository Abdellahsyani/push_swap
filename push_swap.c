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

t_list	*find_min(t_list **stack_a)
{
	t_list *temp = *stack_a;
	t_list *min_node = NULL;

	while (temp)
	{
		if (temp->index == -1 && (min_node == NULL || temp->data < min_node->data))
		{
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}


void	index_stack(t_list **stack_a)
{
	int	index = 0;
	t_list  *node;

	while ((node = find_min(stack_a)) != NULL)
	{
		node->index = index;
		index++;
	}
}

int	count_elements(t_list *stack)
{
	int	count;

	count = 0;
	while (stack) {
		count++;
		stack = stack->next;
	}
	return (count);
}

void	to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int     size;
	int     chunk_size;
	int     num_chunks;
	int     i;
	int     min_range;
	int     max_range;

	size = count_elements(*stack_a);
	if (size <= 100)
		chunk_size = size / 5;
	else
		chunk_size = size / 9;
	if (chunk_size < 10)
		chunk_size = 10;
	num_chunks = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < num_chunks)
	{
		min_range = i * chunk_size;
		max_range = min_range + chunk_size;
		if (max_range > size)
			max_range = size;
		int remaining = 0;
		t_list *temp = *stack_a;
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

void    sort_stack(t_list **stack_a, t_list **stack_b)
{
	int     size;
	to_stack_b(stack_a, stack_b);
	size = count_elements(*stack_b);
	while (size > 0)
	{
		t_list *temp = *stack_b;
		int max = -1;
		int max_pos = 0;
		int curr_pos = 0;
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
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b);
				max_pos--;
			}
		}
		else
	{
			while (max_pos < size)
			{
				rrb(stack_b);
				max_pos++;
			}
		}
		pa(stack_a, stack_b);
		size--;
	}
}

int	clean_stack(char *av)
{
	int	i;
	int	sign = 0;

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

int main(int ac, char **av)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int	i;
	char **dup;

	if (ac == 1)
	{
		return (0);
	}
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
	i = 1;
	while (i < ac)
	{
		dup = ft_split(av[i], ' ');
		int j = 0;
		while (dup[j])
		{
			int num = ft_atoi(dup[j]);
			add_to_stack(&stack_a, num);
			j++;
		}
		i++;
	}
	if (check_dup(stack_a) != 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	index_stack(&stack_a);
	sort_stack(&stack_a, &stack_b);
	t_list *temp = stack_a;
	while (temp)
	{
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
