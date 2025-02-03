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
 * update_ranges _ function to help just for norminette
 * @min_range: the start of range
 * @max_range: the end of range
 * @size: the size of stack
 */
static void	update_ranges(int *min_range, int *max_range, int size)
{
	if (*max_range < size)
		(*max_range)++;
	if (*min_range < *max_range)
		(*min_range)++;
}

/**
 * fill_stack_b _the function to fill stack_b by element
 * @satck_a: the stack that will use to fill stack_b
 * @stack_b: the stack_b that will be filled
 * @ch_s: the size of chunk
 * @size: size of the stack
 * => located at push_swap.c
 */
void	fill_stack_b(t_list **stack_a, t_list **stack_b, int ch_s, int size)
{
	int	min_range;
	int	max_range;

	max_range = ch_s;
	min_range = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= min_range)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			update_ranges(&min_range, &max_range, size);
		}
		else if ((*stack_a)->index >= min_range
			&& (*stack_a)->index <= max_range)
		{
			pb(stack_a, stack_b, 0);
			if (*stack_b && (*stack_b)->next
				&& ((*stack_b)->index < (*stack_b)->next->index))
				sb(stack_b, 0);
			update_ranges(&min_range, &max_range, size);
		}
		else
			ra(stack_a, 0);
	}
}
