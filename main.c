#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void sa(t_list **stack_a)
{
	t_list *first, *second;

	if (!*stack_a || !(*stack_a)->next)
		return;
	first = *stack_a;
	second = (*stack_a)->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_a = second;
	ft_putstr("sa\n");
}

void sb(t_list **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	t_list *first = *stack_b;
	t_list *second = (*stack_b)->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_b = second;
	ft_putstr("sb\n");
}

void ra(t_list **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	t_list *first = *stack_a;
	t_list *last = *stack_a;

	while (last->next)
		last = last->next;

	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putstr("ra\n");
}

void rra(t_list **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	t_list *last = *stack_a;
	t_list *prev_last;

	while (last->next)
		last = last->next;

	prev_last = last->prev;
	prev_last->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_putstr("rra\n");
}

void pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	t_list *first_a = *stack_a;

	*stack_a = first_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;

	first_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = first_a;
	*stack_b = first_a;
	first_a->prev = NULL;
	ft_putstr("pb\n");
}

void pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return;
	t_list *first_b = *stack_b;

	*stack_b = first_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;

	first_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	*stack_a = first_b;
	first_b->prev = NULL;
	ft_putstr("pa\n");
}

int find_median(int a, int b, int c)
{
	if ((a >= b && a <= c) || (a <= b && a >= c))
		return (a);
	if ((b >= a && b <= c) || (b <= a && b >= c))
		return (b);
	return (c);
}

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

int find_pivot(t_list *stack)
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
}

void sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
	sa(stack);
	rra(stack);
}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
	sa(stack);
	ra(stack);
}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void sort_two(t_list **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list *temp = *stack_a;
	int min = temp->data;
	int min_pos = 0;
	int pos = 0;

	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	while (min_pos-- > 0)
		ra(stack_a);

	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

int is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return 1;
}

/*void	quick_sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	len;

	// Base cases
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (size == 4)
	{
		sort_four(stack_a, stack_b);
		return ;
	}
	pivot = find_pivot(*stack_a);
	pushed = 0;
	len = size;
	while (len-- > 0 && pushed < size - 1)
	{
		if ((*stack_a)->data < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else if (len > 0)
			ra(stack_a);
	}
	quick_sort_stack(stack_b, stack_a, pushed);
	quick_sort_stack(stack_a, stack_b, size - pushed);
	//reverse_stack(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}*/
void quick_sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size <= 1 || is_sorted(*stack_a))
		return;
	if (size == 2)
	{
		sort_two(stack_a);
		return;
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return;
	}
	if (size == 4)
	{
		sort_four(stack_a, stack_b);
		return;
	}

	int pivot = find_pivot(*stack_a);
	printf("pivot: %d\n", pivot);
	int push_count = 0;
	int rotate_count = 0;
	int i = 0;

	while (i < size)
	{
		if ((*stack_a)->data < pivot)
		{
			pb(stack_a, stack_b);
			push_count++;
		}
		else
		{
			ra(stack_a);
			rotate_count++;
		}
		i++;
	}
	while (rotate_count-- > 0)
		rra(stack_a);
	quick_sort_stack(stack_a, stack_b, size - push_count);
	quick_sort_stack(stack_b, stack_a, push_count);

	// Move elements back to stack A
	while (*stack_b)
		pa(stack_a, stack_b);
}


t_list *create_node(int data)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!new_node)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void add_to_stack(t_list **stack, int data)
{
	t_list *new_node = create_node(data);
	t_list *temp = *stack;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("Stack A: ");
	while (stack_a)
	{
		printf("%d ", stack_a->data);
		stack_a = stack_a->next;
	}
	printf("\nStack B: ");
	while (stack_b)
	{
		printf("%d ", stack_b->data);
		stack_b = stack_b->next;
	}
	printf("\n");
}

void free_stack(t_list **stack)
{
	while (*stack)
	{
		t_list *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int main(int ac, char **av)
{
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	int	i;
	int	size;

	i = 1;
	if (ac < 2)
	{
		ft_putstr("Error\n");
		return 1;
	}
	while (i < ac)
	{
		add_to_stack(&stack_a, ft_atoi(av[i]));
		i++;
	}

	size = count_nodes(stack_a);
	quick_sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
