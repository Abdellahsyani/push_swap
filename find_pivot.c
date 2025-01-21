/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:29:25 by asyani            #+#    #+#             */
/*   Updated: 2025/01/13 17:31:08 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * count_nodes - fucntion to count how many nodes we have in the satck
 * @stack: the list that we want  to count
 *
 * return: how many nodes
 */
int count_nodes(t_list *stack)
{
	int count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return count;
}
