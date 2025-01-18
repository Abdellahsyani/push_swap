/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:39:50 by asyani            #+#    #+#             */
/*   Updated: 2025/01/17 23:46:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack_a)
{
	t_list *temp = *stack_a;
	t_list *min_node = NULL;

	while (temp)
	{
		if (temp->index == -1 && (min_node == NULL || temp->data < min_node->data))
		{
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}


void	index_stack(t_list **stack_a)
{
	int	index = 0;
	t_list  *node;

	while ((node = find_min(stack_a)) != NULL)
	{
		node->index = index;
		index++;
	}
}

int count_elements(t_list *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int	lower_range = 0;
	int	upper_range = 1;
	int	size = 0;
 	size = count_elements(*stack_a);
    
	while (size > 0)
	{
		if ((*stack_a)->index >= lower_range && (*stack_a)->index < upper_range)
		{
			pb(stack_a, stack_b);
			lower_range++;
            		upper_range++;
			size--;
		}
		else if ((*stack_a)->index < lower_range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			lower_range++;
           		 upper_range++;
			size--;
		}
		else if ((*stack_a)->index >= upper_range)
		{
			ra(stack_a);
		}
	}
}

int main(int ac, char **av)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int	i;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return 1;
	}
	i = 1;
	while (i < ac)
	{
		int num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		i++;
	}
	index_stack(&stack_a);
	sort_stack(&stack_a, &stack_b);
	t_list *temp = stack_b;
	while (temp)
	{
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}

