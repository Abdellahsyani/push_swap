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

/*void	quick_sort_stack(t_list **stack_a, t_list **stack_b, int size)
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
	while (*stack_b)
	{
		//revstack(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}*/
void quick_sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
    int pivot;
    int pushed;
    int i;
    
    // Protect against invalid inputs
    if (!stack_a || !*stack_a || size <= 0)
        return;

    // Handle small sizes first
    if (size <= 1 || is_sorted(*stack_a))
        return;
    if (size == 2)
    {
        sort_two(stack_a);
        return;
    }
    if (size == 3)
    {
        sort_three(stack_a);
        return;
    }

    // Find median as pivot to better split the data
    pivot = find_median(*stack_a, size);
    pushed = 0;

    // Partition phase
    for (i = 0; i < size && *stack_a; i++)
    {
        if ((*stack_a)->data <= pivot)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
        {
            ra(stack_a);
        }
    }

    // Restore stack_a position
    for (i = 0; i < (size - pushed) && *stack_a; i++)
    {
        rra(stack_a);
    }

    // Only recurse if we actually partitioned something
    if (pushed > 0 && pushed < size)
    {
        // Sort larger elements in stack_a
        quick_sort_stack(stack_a, stack_b, size - pushed);
        
        // Move smaller elements back and sort them
        for (i = 0; i < pushed && *stack_b; i++)
        {
            pa(stack_a, stack_b);
        }
        quick_sort_stack(stack_a, stack_b, pushed);
    }
}

// Helper function to find median (add this)
int find_median(t_list *stack, int size)
{
    t_list *current;
    int *arr;
    int i;
    int median;

    // Allocate temporary array
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return 0;

    // Copy stack values to array
    current = stack;
    i = 0;
    while (current && i < size)
    {
        arr[i++] = current->data;
        current = current->next;
    }

    // Simple bubble sort to find median
    for (i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Get median value
    median = arr[size / 2];
    free(arr);
    return median;
}

void	revstack(t_list **stack_a, t_list **stack_b)
{
	t_list *temp = *stack_b;
	int max = temp->data;
	int max_pos = 0;
	int pos = 0;

	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	while (max_pos-- > 0)
		ra(stack_b);

	pa(stack_a, stack_b);
}

int main(int ac, char **av)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int	i;
	int	size;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return 1;
	}
	/*while (av[j])
	{
		dup[i] = ft_split(av[j], ' ');
		i++;
		j++;
	}
	while (dup[i])
	{
		j = 0;
		while (*dup[j])
		{
			if (*dup[j] >= '0' && *dup[j] <= '9')
			{
				if (*dup[j + 1] == '\0')
				{
					v_stack = ft_strjoin(v_stack, dup[i]);
					v_stack = ft_strjoin(v_stack, );
				}
			}
			else
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}*/
	//clean = remove_dup(clean, atoi(v_stack[i]);
	i = 1;
	while (i < ac)
	{
		add_to_stack(&stack_a, ft_atoi(av[i]));
		i++;
	}
	size = count_nodes(stack_a);
	quick_sort_stack(&stack_a, &stack_b, size);
	while (stack_a)
	{
		printf("%d-->", stack_a->data);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
