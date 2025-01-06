#include <stdio.h>
#include <stdlib.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int	data;
} t_list;

void	swap(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

int	*Quick_sort(int *arr, int low, int high)
{
	t_list *head = NULL;
	t_list *new_node = NULL;
	t_list *temp = NULL;
	int data;

	new_node = malloc(sizeof(t_list));
	int k = 0;
	while (arr[k])
	{
		new_node->data = arr[k];
		new_node->next = NULL;
		new_node->prev = NULL;
		if (!head)
			head = new_node;
		else
		{
			temp = head;
			temp->prev = new_node;
			new_node->next = temp;
		}
	}
	while (temp)
	{
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	/*if (low < high)
	{
		int	pivot = arr[high];
		int 	i = low - 1;
		int	j = low;
		while (j < high)
		{
			if (arr[j] < pivot)
	 		{
	 			i++;
				swap(&arr[i], &arr[j]);
			}
			j++;
		}
		swap(&arr[i + 1], &arr[high]);
		int piv = i + 1;
		Quick_sort(arr, low, piv - 1);
		Quick_sort(arr, piv + 1, high);
	}*/
	return (arr);
}

int main()
{
	int arr[6] = {4,8,3,10,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);

	Quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
