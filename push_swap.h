/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:33:46 by asyani            #+#    #+#             */
/*   Updated: 2025/01/17 23:17:50 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int data;
	int index;
} t_list;

//int find_median(t_list *stack, int size);
void	rrb(t_list **stack_b);
t_list	*find_min(t_list **stack_a);
void index_stack(t_list **stack_a);
void	rb(t_list **stack_b);
void	revstack(t_list **stack_a, t_list **stack_b);
int	ft_atoi(char *str);
void	ft_putstr(char *str);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
//int	count_nodes(t_list *stack);
//int	find_pivot(t_list *stack);
void	sort_three(t_list **stack);
void	sort_two(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
int	is_sorted(t_list *stack);
void	sort_stack(t_list **stack_a, t_list **stack_b);
t_list	*create_node(int data);
void	add_to_stack(t_list **stack, int data);
void	free_stack(t_list **stack);

#endif
