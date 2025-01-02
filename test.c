#include <stdio.h>
#include <stdlib.h>

typedef struct n_list {
	n_list *next;
	n_list *prev;
	int data;
} t_list;

t_list	double_linked(t_list head)
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
	head->next = NULL:

	tmp1->prev = NULL;
	return (head);
}

int main()
{
	t_list *list = NULL;
}
