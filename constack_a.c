/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:37:05 by asyani            #+#    #+#             */
/*   Updated: 2025/01/13 17:58:26 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa _ function to swap stack_a
 * @stack_a: the stack that we swap
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 */
void	sa(t_list **stack_a, int write)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_a = second;
	if (write == 0)
		ft_putstr("sa\n");
}

/**
 * ra _ the function to rotate up stack_a
 * @stack_a: stack that we are rotate
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 */
void	ra(t_list **stack_a, int write)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (write == 0)
		ft_putstr("ra\n");
}

/**
 * rra _ the function that rotate stacks in reverse
 * @stack_a: teh stack that we reverse
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 */
void	rra(t_list **stack_a, int write)
{
	t_list	*last;
	t_list	*prev_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	prev_last->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	if (write == 0)
		ft_putstr("rra\n");
}

/**
 * pa _ the function to push from b to a
 * @stack_a: the first stack
 * @stack_b: teh second stack
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 */
void	pa(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*first_b;

	if (!*stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = first_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	*stack_a = first_b;
	first_b->prev = NULL;
	if (write == 0)
		ft_putstr("pa\n");
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
