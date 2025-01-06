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

t_list	*double_linked(t_list **head)
{
	t_list *temp = NULL;
	t_list *head1 = *head;
	t_list *tmp1 = (*head)->next;
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


int	*push_swap(int *stack_a, int low, int high)
{
	int	*stack_b = NULL;

	if (low < high)
	{
		int	pivot = stack_a[high];
		int	i = low - 1;
		int	j = low;

		while (j < high)
		{
			if (stack_a[j] < pivot)
			{
				i++;
				swap(&stack_a[i], &stack_a[j]);
			}
			j++;
		}
		swap(&stack_a[i + 1], &stack_a[high]);

	}
}

int main(int ac, char **av)
{
	t_list *head = NULL;
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)  
		{
			int num = atoi(av[i]);
			add_node(&head, num); 
			i++;
		}
		t_list *temp = head;
		while (temp) {
			printf("%d-->", temp->data);
			temp = temp->next;
		}
		push_swap(&head, 0);
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
