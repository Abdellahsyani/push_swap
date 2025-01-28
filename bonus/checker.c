/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:53:55 by asyani            #+#    #+#             */
/*   Updated: 2025/01/24 22:54:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"


/*static void	free_all(t_list **stack_a, t_list **stack_b, char *str)*/
/*{*/
/*	free(str);*/
/*	free_stack(stack_a);*/
/*	free_stack(stack_b);*/
/*	ft_putstr_fd("Error\n", 2);*/
/*}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] == '\0' || ss2[i] == '\0')
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

static void	instraction_cmp(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(str, "rra\n", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(str, "rrb\n", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_b, stack_a);
	else
	{
		free(str);
		free_stack(stack_a);
		free_stack(stack_b);
		//ft_putstr_fd("Error\n", 2);
	}
}

static void	read_instraction(t_list *stack_a, t_list *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		instraction_cmp(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
}

static int is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd == -1)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = verify_stack(stack_a, ac, av);
		if (check_dup(stack_a) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		read_instraction(stack_a, stack_b);
		if (is_sorted(stack_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	return (1);
}
