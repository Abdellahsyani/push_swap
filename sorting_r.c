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


/*void	sort_five(t_list **stack)*/
/*{*/
/*	t_list	*temp;*/
/*	int	min;*/
/**/
/*	if (!stack)*/
/*		return ;*/
/*	while (*stack)*/
/*	{*/
/**/
/*	}*/
/*}*/

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
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
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
		sa(stack_a);
}

/**
 * sort_four _ function to sort 4 numbers
 * @stack_a: the stack that we want to sort
 * @stack_b: the stack that we use to sort the a
 */
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int	min;
	int	min_pos;
	int	pos;

	temp = *stack_a;
	min = temp->data;
	min_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	while (min_pos-- > 0)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

/**
 * is_sorted _ checking if the stack are sorted
 * @stack: the stack that we are checking
 * 
 * return: 0 if success 1 if failure
 */
int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
