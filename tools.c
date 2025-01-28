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
static int	count_min(t_list **stack_a, int min_range, int max_range)
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

/**
 * helper_b _ function to help just for norminette
 * @stack_a: teh first stack
 * @stack_b: the second stck
 * @min: the min value in the range
 * @max: the max value in the range
 */
static void	helper_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	rem;

	rem = count_min(stack_a, min, max);
	while (rem > 0)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index < max)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index < (min + max) / 2)
				rb(stack_b);
			rem--;
		}
		else
			ra(stack_a);
	}
}

/**
 * fill_stack_b _the function to fill stack_b by element
 * @satck_a: the stack that will use to fill stack_b
 * @stack_b: the stack_b that will be filled
 * @num_c: the number of chunks that we use to sort the stack
 * @ch_s: the size of each chunk
 * => located at push_swap.c
 */
void	fill_stack_b(t_list **stack_a, t_list **stack_b, int num_c, int ch_s)
{
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
		helper_b(stack_a, stack_b, min_range, max_range);
		i++;
	}
}

/**
 * max_min _ fucntion to check MAX_INT and MAX_MIN
 * @num: the number that will be checked
 * @dup: just for free the memory
 * => this is located at scan.c
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
