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

int main() {
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
}
