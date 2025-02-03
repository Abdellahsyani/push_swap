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

# include <stdlib.h>
# include <unistd.h>

typedef struct n_list
{
	struct n_list	*next;
	struct n_list	*prev;
	int				data;
	int				index;
}					t_list;

/*helper functions to sort stack*/
void				max_min(long num, char **dup);
int					count_elements(t_list *stack);
t_list				*find_min(t_list **stack_a);
int					find_max(t_list **stack_b);
void				index_stack(t_list **stack_a);
int					ft_atoi(char *str, char **dup, t_list **stack_a);
void				ft_putstr(char *str);
char				**ft_split(char const *s, char c);
void				fill_stack_b(t_list **stack_a, t_list **stack_b, int ch_s,
						int size);
int					count_nodes(t_list *stack);
void				verify_dup(char **av);
int					check_dup(t_list *stack_a);
t_list				*verify_stack(t_list *stack_a, int ac, char **av);
int					clean_stack(char *av);
void				free_split_result(char **split_result);
int					is_sorted(t_list *stack);
void				ft_putstr_fd(char *s, int fd);
int					is_digit(char c);
void				ft_perror(char **dup, t_list **stack_a);
void				ft_error(char **dup);

/*rotate swap push */
void				rb(t_list **stack_b, int write);
void				rrb(t_list **stack_b, int write);
void				sa(t_list **stack_a, int write);
void				ra(t_list **stack_a, int write);
void				rra(t_list **stack_a, int write);
void				pb(t_list **stack_a, t_list **stack_b, int write);
void				pa(t_list **stack_a, t_list **stack_b, int write);
void				ss(t_list **stack_a, t_list **stack_b, int print);
void				rrr(t_list **stack_a, t_list **stack_b, int print);
void				rr(t_list **stack_a, t_list **stack_b, int print);
void				sb(t_list **stack_b, int print);

/*functions to sort*/
void				sort_three(t_list **stack);
void				sort_two(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_stack(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);

/*create stack and free it*/
t_list				*create_node(int data);
void				add_to_stack(t_list **stack, int data);
void				free_stack(t_list **stack);

#endif
