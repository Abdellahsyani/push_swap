/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:40:23 by asyani            #+#    #+#             */
/*   Updated: 2025/01/26 17:42:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * find_max _ the function to find the maximume value in stack_b
 * @stack_b: the stack where we look for max value
 *
 * return: the max value
 */
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

/**
 * count_min _ fucntion to find the end of chunk to help in sort chunck
 * @stack_a: the chunks stack
 * @min_range: teh begining of the range
 * @max_range: the max of the range
 *
 * return: the length of the chunck that will be sorted
 */
int	count_min(t_list **stack_a, int min_range, int max_range)
{
	t_list	*temp;
	int		remaining;

	remaining = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index >= min_range && temp->index < max_range)
			remaining++;
		temp = temp->next;
	}
	return (remaining);
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b, int num_c, int ch_s)
{
	int	rem;
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
		rem = count_min(stack_a, min_range, max_range);
		while (rem > 0)
		{
			if ((*stack_a)->index >= min_range && (*stack_a)->index < max_range)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index < (min_range + max_range) / 2)
					rb(stack_b);
				rem--;
			}
			else
				ra(stack_a);
		}
		i++;
	}
}

/**
 * max_min _ fucntion to check MAX_INT and MAX_MIN
 * @num: the number that will be checked
 * @dup: just for free the memory
 *
 */
void	max_min(long num, char **dup)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr("Error\n");
		free_split_result(dup);
		exit(1);
	}
}
