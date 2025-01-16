/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:42 by asyani            #+#    #+#             */
/*   Updated: 2025/01/13 18:17:36 by asyani           ###   ########.fr       */
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
	//t_list	*temp;

	new_node = create_node(data);
	//temp = *stack;
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
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
