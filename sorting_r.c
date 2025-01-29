/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:59:46 by asyani            #+#    #+#             */
/*   Updated: 2025/01/13 18:08:36 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack)
{
	t_list	*temp;
	int		min;
	int		cur_pos;
	int		pos;

	temp = *stack;
	min = temp->data;
	cur_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			cur_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (cur_pos);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	cur_pos;
	int	i;

	i = 0;
	cur_pos = 0;
	while (i < 2)
	{
		cur_pos = get_min(stack_a);
		if (cur_pos <= 5 / 2)
		{
			while (cur_pos-- > 0)
				ra(stack_a, 0);
		}
		else
		{
			while (cur_pos++ < 5)
				rra(stack_a, 0);
		}
		pb(stack_a, stack_b, 0);
		i++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
}

/**
 * sort_three _ the function that sort 3 numbers
 * @stack: the stack that we want to sort
 */
void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack, 0);
	else if (first > second && second > third)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 0);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 0);
		ra(stack, 0);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 0);
}

/**
 * sort_two _ function to sort 2 numbers
 * @stack_a: the stack that contain 2 numbers
 */
void	sort_two(t_list **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 0);
}

/**
 * sort_four _ function to sort 4 numbers
 * @stack_a: the stack that we want to sort
 * @stack_b: the stack that we use to sort the a
 */
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;

	min_pos = get_min(stack_a);
	while (min_pos-- > 0)
		ra(stack_a, 0);
	pb(stack_a, stack_b, 0);
	sort_three(stack_a);
	pa(stack_a, stack_b, 0);
}
