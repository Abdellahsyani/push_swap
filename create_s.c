/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:42 by asyani            #+#    #+#             */
/*   Updated: 2025/01/17 23:46:37 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * create_node _ function to create the node
 * @data: the data that node will take
 */
t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	return (new_node);
}

/**
 * add_to_stack _ function to add nodes to stack
 * @stack: the stack that we want to fill
 * @data: the data of node
 */
void	add_to_stack(t_list **stack, int data)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = create_node(data);
	if (!new_node)
	{
		free_stack(stack);
		return ;
	}
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
}

/**
 * find_min _ function to find the mini value in stack
 * @stack_a: stack to scane for small value
 *
 * return: min value node
 */
t_list	*find_min(t_list **stack_a)
{
	t_list	*temp;
	t_list	*min_node;

	temp = *stack_a;
	min_node = NULL;
	while (temp)
	{
		if (temp->index == -1 && (min_node == NULL
			|| temp->data < min_node->data))
		{
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

/**
 * index_stack _ indexing stack to sort it easily
 * @stack_a: the stack that will be sorted
 */
void	index_stack(t_list **stack_a)
{
	int		index;
	t_list	*node;

	index = 0;
	node = find_min(stack_a);
	while (node)
	{
		node->index = index;
		index++;
		node = find_min(stack_a);
	}
}

/**
 * free_stack _ function to free array
 * @stack: the stack that will freed
 */
void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
