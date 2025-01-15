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
	int	rotate_count;
	int	i;

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
	rotate_count = 0;
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->data < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
	{
			ra(stack_a);
			rotate_count++;
		}
		i++;
	}
	while (rotate_count-- > 0)
		rra(stack_a);
	quick_sort_stack(stack_a, stack_b, size - pushed);
	quick_sort_stack(stack_b, stack_a, pushed);
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
	char	*v_stack;

	int j = 1;
	if (ac < 2)
	{
		ft_putstr("Error\n");
		return 1;
	}
	while (av[j])
	{
		dup[i++] = ft_split(av[j], ' ');
		j++;
	}
	while (dup[i])
	{
		j = 0;
		while (*dup[j] && *dup[j] >= '0' && *dup[j] <= '9')
		{
			if (*dup[j + 1] == '\0')
			{
				v_stack = ft_strjoin(v_stack, dup[j]);
				v_stack = ft_strjoin(v_stack, ' ');
			}
			j++;
		}
		i++;
	}
	clean = remove_dup(clean, atoi(v_stack[i]);
	while (i < ac)
	{
		add_to_stack(&stack_a, dup[i]);
		i++;
	}
	size = count_nodes(stack_a);
	quick_sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
