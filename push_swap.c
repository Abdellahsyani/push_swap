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
/*void	sort_stack(t_list **stack_a, t_list **stack_b)*/
/*{*/
/*	t_list	*current;*/
/*	int	lower_range = 0;*/
/*	int	upper_range = 1;*/
/*	int	size = 0;*/
/* 	size = count_elements(*stack_a);*/
/**/
/*	while (size > 0)*/
/*	{*/
/*		if ((*stack_a)->index >= lower_range && (*stack_a)->index < upper_range)*/
/*		{*/
/*			pb(stack_a, stack_b);*/
/*			lower_range++;*/
/*            		upper_range++;*/
/*			size--;*/
/*		}*/
/*		else if ((*stack_a)->index < lower_range)*/
/*		{*/
/*			pb(stack_a, stack_b);*/
/*			rb(stack_b);*/
/*			lower_range++;*/
/*           		 upper_range++;*/
/*			size--;*/
/*		}*/
/*		else if ((*stack_a)->index >= upper_range)*/
/*		{*/
/*			ra(stack_a);*/
/*		}*/
/*	}*/
/*}*/
void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    int     size;
    int     chunk_size;
    int     num_chunks;
    int     i;
    int     min_index;
    int     max_index;
    
    size = count_elements(*stack_a);
    
    if (size <= 100)
        chunk_size = size / 5;
    else
        chunk_size = size / 10;
        
    if (chunk_size < 10)
        chunk_size = 10;
        
    num_chunks = (size + chunk_size - 1) / chunk_size;
    
    for (i = 0; i < num_chunks; i++)
    {
        min_index = i * chunk_size;
        max_index = min_index + chunk_size;
        if (max_index > size)
            max_index = size;
            
        int remaining = 0;
        t_list *temp = *stack_a;
        while (temp)
        {
            if (temp->index >= min_index && temp->index < max_index)
                remaining++;
            temp = temp->next;
        }
        
        while (remaining > 0)
        {
            if ((*stack_a)->index >= min_index && (*stack_a)->index < max_index)
            {
                pb(stack_a, stack_b);
                if ((*stack_b)->index < (min_index + max_index) / 2)
                    rb(stack_b);
                remaining--;
            }
            else
                ra(stack_a);
        }
    }
    
    // Push everything back to A in descending order
    size = count_elements(*stack_b);
    while (size > 0)
    {
        t_list *temp = *stack_b;
        int max = -1;
        int max_pos = 0;
        int curr_pos = 0;
        
        // Find the maximum number and its position
        while (temp)
        {
            if (temp->index > max)
            {
                max = temp->index;
                max_pos = curr_pos;
            }
            curr_pos++;
            temp = temp->next;
        }
        if (max_pos <= size / 2)
        {
            while (max_pos > 0)
            {
                rb(stack_b);
                max_pos--;
            }
        }
        else
        {
            while (max_pos < size)
            {
                rrb(stack_b);
                max_pos++;
            }
        }
        
        pa(stack_a, stack_b);
        size--;
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

	/*while (stack_a)*/
	/*{*/
	/*	printf("%d[%d]-->", stack_a->data, stack_a->index);*/
	/*	stack_a = stack_a->next;*/
	/*}*/
	sort_stack(&stack_a, &stack_b);
	t_list *temp = stack_a;
	while (temp)
	{
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
