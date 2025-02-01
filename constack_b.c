/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:25:58 by asyani            #+#    #+#             */
/*   Updated: 2025/01/14 09:38:17 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rb _ function to rotate stack_b in reverse
 * @stack_b: the stack that will rotated
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 *
 */
void	rrb(t_list **stack_b, int write)
{
	t_list	*last;
	t_list	*prev_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	prev_last->next = NULL;
	last->next = *stack_b;
	last->prev = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	if (write == 0)
		ft_putstr("rrb\n");
}

/**
 * rb _ function to rotate stack_b
 * @stack_b: the stack that will rotated
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 *
 */
void	rb(t_list **stack_b, int write)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (write == 0)
		ft_putstr("rb\n");
}

/**
 * pb _ function that push from stack a to stack b
 * @stack_a: the first stack
 * @stack_b: the second stack
 * @write: flag to check if we want to print instraction
 * 	if write == 0; print if 1 don't print
 *
 */
void	pb(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*first_a;

	if (!*stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = first_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = first_a;
	*stack_b = first_a;
	first_a->prev = NULL;
	if (write == 0)
		ft_putstr("pb\n");
}

/**
 * ft_putstr _ function to print steps that we do in sort
 * @str: string that will print
 *
 */
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/**
 * ft_atoi _ function to convert string to number
 * @str: the string that e want to convert
 *
 * return: string converted to number
 */
int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res * sign) < -2147483648 || (res * sign) > 2147483647)
		ft_error(str);
	return ((int)(res * sign));
}
