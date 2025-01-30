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

#include "get_next_line.h"


void    ss(t_list **stack_a, t_list **stack_b, int print)
{
    sa(stack_a);
    sa(stack_b);
    if (print == 0)
        ft_putstr("ss\n");
}

void    rrr(t_list **stack_a, t_list **stack_b, int print)
{
    rra(stack_a);
    rrb(stack_b);
    if (print == 0)
        ft_putstr("rrr\n");
}

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	ra(stack_a);
	rb(stack_b);
	if (print == 0)
		ft_putstr("rr\n");
}

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
