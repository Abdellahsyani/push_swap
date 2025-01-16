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
 * find_median - fucntion to find the meduim of three digits
 * @a: the first digit
 * @b: the second digit
 * @c: the third digit
 *
 * return: the meduim one
 */
/*int find_median(int a, int b, int c)
{
	if ((a >= b && a <= c) || (a <= b && a >= c))
		return (a);
	if ((b >= a && b <= c) || (b <= a && b >= c))
		return (b);
	return (c);
}*/

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

/**
 * find_pivot - the fucntion that find the pivot in the list
 * @stack: teh stack that we want to sort
 *
 * return: pivot
 */
/*int find_pivot(t_list *stack)
{
	int size = count_nodes(stack);
	if (size <= 1)
		return stack->data;

	t_list *mid = stack;
	t_list *last = stack;

	int i = 0;
	while (i < size / 2)
	{
		mid = mid->next;
		i++;
	}
	while (last->next)
		last = last->next;

	return (find_median(stack->data, mid->data, last->data));
}*/

