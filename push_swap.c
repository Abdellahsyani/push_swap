/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:39:50 by asyani            #+#    #+#             */
/*   Updated: 2025/01/14 09:41:15 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	len;

	// Base cases
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (size == 4)
	{
		sort_four(stack_a, stack_b);
		return ;
	}
	pivot = find_pivot(*stack_a);
	pushed = 0;
	len = size;
	while (len-- > 0 && pushed < size - 1)
	{
		if ((*stack_a)->data < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if (len > 0)
			ra(stack_a);
	}
	quick_sort_stack(stack_b, stack_a, pushed);
	quick_sort_stack(stack_a, stack_b, size - pushed);
	//reverse_stack(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}

int main(int ac, char **av)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int	i;
	int	size;

	i = 1;
	if (ac < 2)
	{
		ft_putstr("Error\n");
		return 1;
	}
	while (i < ac)
	{
		add_to_stack(&stack_a, ft_atoi(av[i]));
		i++;
	}

	size = count_nodes(stack_a);
	quick_sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
