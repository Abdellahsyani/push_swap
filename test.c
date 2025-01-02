#include <stdio.h>
#include <stdlib.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int data;
} t_list;

t_list	*double_linked(t_list *head)
{
	t_list *temp = NULL;
	t_list *head1 = head;
	t_list *tmp1 = head->next;
	while (head1)
	{
		head1 = head1->next;
		temp = head1;
	}
	temp->next = head;
	head->prev = temp;
	head->next = NULL;

	tmp1->prev = NULL;
	return (head);
}

t_list	*add_node(t_list *head, int node)
{
	t_list *temp = NULL;
	t_list *new_node = malloc(sizeof(t_list));

	if (!head)
	{
		head->data = node;
		head->next = NULL;
		head->prev = NULL;
	}
	if (head)
	{
		while (head)
		{
			head = head->next;
			temp = head;
		}
		new_node->prev = temp;
		temp->next = new_node;
		new_node->next = NULL;
	}
	return (head);
}

int main()
{
	int a = 6;
	int b = 7;
	int c = 8;
	t_list *head = NULL;

	add_node(head, a);
	add_node(head, b);
	add_node(head, c);

	while (head)
	{
		printf("%d-->", *(int *)head->data);
		head = head->next;
	}
	return (0);
}
