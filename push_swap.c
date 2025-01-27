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
 * stack_range _ the fucntion that divied stack into chuncks and fill stack b
 * @stack_a: the main stack that will be sorted
 * @stack_b: the second stack that will be used to sort first
 *
 */
void	stack_range(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	num_chunks;

	size = count_elements(*stack_a);
	if (size <= 100)
		chunk_size = size / 5;
	else
		chunk_size = size / 10;
	if (chunk_size < 10)
		chunk_size = 10;
	num_chunks = (size + chunk_size - 1) / chunk_size;
	fill_stack_b(stack_a, stack_b, num_chunks, chunk_size);
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
				rb(stack_b);
		}
		else
	{
			while (max_pos++ < size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
	{
		return (0);
	}
	stack_a = verify_stack(stack_a, ac, av);
	if (check_dup(stack_a) != 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
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
	/*t_list *temp = stack_a;*/
	/*while (temp)*/
	/*{*/
	/*	printf("%d, ", temp->data);*/
	/*	temp = temp->next;*/
	/*}*/
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
