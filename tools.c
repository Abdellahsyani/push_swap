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
 * helper_b _ function to help just for norminette
 * @stack_a: teh first stack
 * @stack_b: the second stck
 * @min: the min value in the range
 * @max: the max value in the range
 */
/*static void	helper_b(t_list **stack_a, t_list **stack_b, int min, int max)*/
/*{*/
/*	int	size;*/
/**/
/*	size = count_elements(*stack_a);*/
/*	pb(stack_a, stack_b, 0);*/
/*	rb(stack_b, 0);*/
/*	if (max < size)*/
/*		max++;*/
/*	if (min < max)*/
/*		min++;*/
/*}*/

/**
 * fill_stack_b _the function to fill stack_b by element
 * @satck_a: the stack that will use to fill stack_b
 * @stack_b: the stack_b that will be filled
 * @num_c: the number of chunks that we use to sort the stack
 * @ch_s: the size of each chunk
 * => located at push_swap.c
 */
void	fill_stack_b(t_list **stack_a, t_list **stack_b, int ch_s)
{
	int	min_range;
	int	max_range;
	int	size;

	size = count_elements(*stack_a);
	max_range = ch_s;
	min_range = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= min_range)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			if (max_range < size)
				max_range++;
			if (min_range < max_range)
				min_range++;
		}
		else if ((*stack_a)->index >= min_range && (*stack_a)->index <= max_range)
		{
			pb(stack_a, stack_b, 0);
			if (*stack_b && (*stack_b)->next && ((*stack_b)->index < (*stack_b)->next->index))
				sb(stack_b, 0);
			if (max_range < size)
				max_range++;
			if (min_range < max_range)
				min_range++;
		}
		else
			ra(stack_a, 0);
	}
}
