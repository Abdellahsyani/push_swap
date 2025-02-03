/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:39:50 by asyani            #+#    #+#             */
/*   Updated: 2025/01/26 17:42:22 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * is_sorted _ check if the stack is sorted or not
 * @stack: stack to be checked
 *
 * return: 0 if sorted 1 if not
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

/**
 * stack_range _ the fucntion that divied stack into chuncks and fill stack b
 * @stack_a: the main stack that will be sorted
 * @stack_b: the second stack that will be used to sort first
 *
 */
void	stack_range(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;

	size = count_elements(*stack_a);
	if (size <= 100)
		chunk_size = size / 6;
	else
		chunk_size = size / 14;
	fill_stack_b(stack_a, stack_b, chunk_size, size);
}

/**
 * sort_stack _ fucntion to sort stack_a take the big elem and push it to a
 * @stack_a: empty stack to sort all element on it
 * @stack_b: mixed stack and will be sorted to stack_a
 *
 */
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_pos;

	stack_range(stack_a, stack_b);
	size = count_elements(*stack_b);
	while (size > 0)
	{
		max_pos = find_max(stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, 0);
		}
		else
		{
			while (max_pos++ < size)
				rrb(stack_b, 0);
		}
		pa(stack_a, stack_b, 0);
		size--;
	}
}

/**
 * start_sort _ fucntion that sorting start from it begining
 * @stack_a: stack that will be sorted
 * @stack_b: the helper stack to sort stack_a
 */
void	start_sort(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = count_elements(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		index_stack(&stack_a);
		sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	stack_a = verify_stack(stack_a, ac, av);
	if (check_dup(stack_a) != 0)
	{
		free_stack(&stack_a);
		ft_putstr("Error\n");
		exit(1);
	}
	if (!is_sorted(stack_a))
		start_sort(stack_a, stack_b);
	else
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
