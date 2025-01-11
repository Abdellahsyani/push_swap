/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:42:01 by asyani            #+#    #+#             */
/*   Updated: 2025/01/11 10:46:44 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int data;
} t_list;

int	ft_atoi(char *str);
void	swap(int *a, int *b);
t_list	*double_swap(t_list **head);
t_list	*rotate_up(t_list **head);
t_list	*rotate_down(t_list **head);
t_list *add_node(t_list **head, int data);
t_list	*push_a(t_list **stack_b, t_list *stack_a);
t_list	*push_b(t_list **stack_a, t_list *stack_b);
int	chose_piv(int *arr);
int	get_pivot(int *stack, int low, int high);
int	*push_swap(int *stack, int low, int high);

#endif
