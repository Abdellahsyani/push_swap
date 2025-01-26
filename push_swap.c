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

/*int	count_min(t_list **stack_a, int min_range, int max_range)*/
/*{*/
/*	t_list	*temp;*/
/*	int	remaining;*/
/**/
/*	remaining = 0;*/
/*	temp = *stack_a;*/
/*	while (temp)*/
/*	{*/
/*		if (temp->index >= min_range && temp->index < max_range)*/
/*			remaining++;*/
/*		temp = temp->next;*/
/*	}*/
/*	return (remaining);*/
/*}*/
/**/
/*void	fill_stack_b(t_list **stack_a, t_list **stack_b, int num_c, int ch_s)*/
/*{*/
/*	int	rem;*/
/*	int	min_range;*/
/*	int	max_range;*/
/*	int	i;*/
/*	int	size;*/
/**/
/*	i = 0;*/
/*	size = count_elements(*stack_a);*/
/*	while (i < num_c)*/
/*	{*/
/*		min_range = i * ch_s;*/
/*		max_range = min_range + ch_s;*/
/*		if (max_range > size)*/
/*			max_range = size;*/
/*		rem = count_min(stack_a, min_range, max_range);*/
/*		while (rem > 0)*/
/*		{*/
/*			if ((*stack_a)->index >= min_range && (*stack_a)->index < max_range)*/
/*			{*/
/*				pb(stack_a, stack_b);*/
/*				if ((*stack_b)->index < (min_range + max_range) / 2)*/
/*					rb(stack_b);*/
/*				rem--;*/
/*			}*/
/*			else*/
/*				ra(stack_a);*/
/*		}*/
/*		i++;*/
/*	}*/
/*}*/

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

/*int	find_max(t_list **stack_b)*/
/*{*/
/*	t_list	*temp;*/
/*	int		max;*/
/*	int		max_pos;*/
/*	int		curr_pos;*/
/**/
/*	temp = *stack_b;*/
/*	max = -1;*/
/*	max_pos = 0;*/
/*	curr_pos = 0;*/
/*	while (temp)*/
/*	{*/
/*		if (temp->index > max)*/
/*		{*/
/*			max = temp->index;*/
/*			max_pos = curr_pos;*/
/*		}*/
/*		curr_pos++;*/
/*		temp = temp->next;*/
/*	}*/
/*	return (max_pos);*/
/*}*/

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
	else
	{
		index_stack(&stack_a);
		sort_stack(&stack_a, &stack_b);

	}
	t_list *temp = stack_a;
	while (temp)
	{
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
