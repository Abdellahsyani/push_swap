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

/**
 * instraction_cmp _ the function to compare the instraction with stack
 * @str: the string that will be compared
 * @stack_a: the stack_a that will be used to sort
 * @stack_b: teh stack_b that helped to sort
 */
static void	instraction_cmp(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a, 1);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_b, stack_a, 1);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack_a);
		free_stack(stack_b);
		free(str);
		exit(1);
	}
}

/**
 * read_instraction _ function to read the instraction from stdin
 * @stack_a: the stack that contains sorted numbers
 * @stack_b: helped stack to sort
 */
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

/**
 * is_sorted _ check if the stack is sorted or not
 * @stack: stack to be checked
 *
 * return: 0 if sorted 1 if not
 */
int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * ft_putstr_fd _ function to write string in a file descriptor
 * @s: the string that will be written
 * fd: file descriptor to write on it
 */
void	ft_putstr_fd(char *s, int fd)
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
		if (!stack_a || check_dup(stack_a) != 0)
		{
			free_stack(&stack_a);
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
