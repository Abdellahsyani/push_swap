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
	struct	n_list *next;
	struct	n_list *prev;
	int	data;
	int	index;
} t_list;

/*helper functions to sort stack*/
int	count_elements(t_list *stack);
t_list	*find_min(t_list **stack_a);
void	index_stack(t_list **stack_a);
int	ft_atoi(char *str);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
void	fill_stack_b(t_list **stack_a, t_list **stack_b, int num_chunks, int chunk_size);
int	count_nodes(t_list *stack);


/*rotate swap push */
void	rb(t_list **stack_b);
void	rrb(t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);

/*functions to sort*/
void	sort_three(t_list **stack);
void	sort_two(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);

/*create stack and free it*/
t_list	*create_node(int data);
void	add_to_stack(t_list **stack, int data);
void	free_stack(t_list **stack);

#endif
