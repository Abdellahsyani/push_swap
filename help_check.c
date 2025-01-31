/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:56:59 by asyani            #+#    #+#             */
/*   Updated: 2025/01/30 18:04:02 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ss _ function to swap two stack in the same time
 * @stack_a: the first stack
 * @stack_b: the second stack
 * @print: flag to check if we want to print instraction or not
 */
void	ss(t_list **stack_a, t_list **stack_b, int print)
{
	sa(stack_a, 1);
	sa(stack_b, 1);
	if (print == 0)
		ft_putstr("ss\n");
}

/**
 * rrr _ function to rotate_reverse two stack in the same time
 * @stack_a: the first stack
 * @stack_b: the second stack
 * @print: flag to check if we want to print instraction or not
 */
void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (print == 0)
		ft_putstr("rrr\n");
}

/**
 * rr _ function to rotate two stack in the same time
 * @stack_a: the first stack
 * @stack_b: the second stack
 * @print: flag to check if we want to print instraction or not
 */
void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (print == 0)
		ft_putstr("rr\n");
}

/**
 * sb _ function to swap stack_b two stack in the same time
 * @stack_b: the stack that will be swaped
 * @print: flag to check if we want to print instraction or not
 */
void	sb(t_list **stack_b, int print)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_b = second;
	if (print == 0)
		ft_putstr("sb\n");
}

/**
 * is_digit _ the function that check if number or not
 * @c: the character that will be checked
 *
 * return: 1 if digit 0 if not
 */
int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
