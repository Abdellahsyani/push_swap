/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:18:05 by asyani            #+#    #+#             */
/*   Updated: 2025/01/06 14:19:50 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int data;
} t_list;

void	swap(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

t_list	*double_swap(t_list **head)
{
	t_list *temp = NULL;
	t_list *second_node = NULL;

	temp = *head;
	second_node = (*head)->next;

	temp->next = second_node->next;
	second_node->next->prev = temp;
	temp->prev = second_node;
	second_node->next = temp;
	second_node->prev = NULL;

	return (second_node);
}

t_list	*rotate_up(t_list **head)
{
	t_list *temp = NULL;
	t_list *head1 = *head;
	while (head1)
	{
		temp = head1;
		head1 = head1->next;
	}
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;

	return (temp);
}

t_list	*rotate_down(t_list **head)
{
	t_list *temp = NULL;
	t_list *last = NULL;
	t_list *head2 = *head;

	temp = head2->next;
	while (head2)
	{
		last = head2;
		head2 = head2->next;
	}
	temp->prev = NULL;
	(*head)->prev = last;
	(*head)->next = NULL;
	last->next = *head;
	
	return (temp);
}

t_list *add_node(t_list **head, int data) {
	t_list *new_node = malloc(sizeof(t_list));
	t_list *temp = *head;

	if (!new_node) return NULL; 

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL) {
		*head = new_node;
	} else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}

	return *head;
}


int	chose_piv(int *arr)
{
	int pivot = 0;
	if ((arr[0] > arr[1] && arr[0] < arr[2]) || (arr[0] < arr[1] && arr[0] > arr[2]))
		pivot = arr[0];
	if ((arr[1] > arr[0] && arr[1] < arr[2]) || (arr[1] < arr[0] && arr[1] > arr[2]))
		pivot = arr[1];
	else
		pivot = arr[2];
	return (pivot);
}

t_list	push(int *arr)
{
	t_list *head = NULL;
	t_list *stack_a = NULL;
	t_list *current = NULL;

	int	i = 0;
	while (arr[i])
	{
		add_node(&stack_a, arr[i]);
		i++;
	}
	current = stack_a;
	while ()
	{
	}
}

int	*push_swap(int *stack, int low, int high)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	int *arr = malloc(sizeof(int) * 3);
	int midle = low + (high - low) / 2;
	printf("this low: %d\n", low);
	printf("this high: %d\n", high);
	printf("this midle: %d\n", midle);

	arr[0] = stack[low];
	arr[1] = stack[midle];
	arr[2] = stack[high];
	if (low < high)
	{
		int	pivot = chose_piv(arr);
		printf("pivot: %d\n", pivot);
		int	i = low - 1;
		int	j = low;

		while (j < high)
		{
			if (stack[j] < pivot)
			{
				i++;
				swap(&stack[i], &stack[j]);
			}
			j++;
		}
		swap(&stack[i + 1], &stack[high]);
		int k = 1;
		while (k < high)
		{
			if (stack[k] < pivot)
				add_node(&stack_b, stack[k]);
			else if (stack[k] >= pivot)
				add_node(&stack_a, stack[k]);
			k++;
		}
		t_list *temp = stack_b;
		while (temp) {
			printf("%d-->", temp->data);
			temp = temp->next;
		}
		printf("\n");
		t_list *dart = stack_b;
		dart = double_swap(&dart);
		while (dart) {
			printf("%d-->", dart->data);
			dart = dart->next;
		}

	}
	return (stack);
}

int main(int ac, char **av)
{
	t_list *head = NULL;
	int *arr = malloc(sizeof(int) * (ac - 1));
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			arr[i] = atoi(av[i]);
			i++;
		}
		push_swap(arr, 0, ac - 1);
		t_list *temp = head;
		while (temp) {
			printf("%d-->", temp->data);
			temp = temp->next;
		}
	}
	else
	printf("Error\n");
	return (0);
}
/*int main() {
	t_list *head = NULL;

	add_node(&head, 6);
	add_node(&head, 7);
	add_node(&head, 8);
	add_node(&head, 9);
	add_node(&head, 10);

	t_list *temp = head;
	while (temp) {
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("\n");
	head = double_linked(&head);
	while (head)
	{
		printf("%d-->", head->data);
		head = head->next;
	}
	return 0;
}*/
