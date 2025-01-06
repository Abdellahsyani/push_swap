#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct n_list {
	struct n_list *next;
	struct n_list *prev;
	int	data;
} t_list;


int	*create_list(t_list *head)
{
}

void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
		create_list(stack_a, )
		/*int u = low;
		while (u <= high)
		{
			printf("stack_a here: %d\n", stack_a[u]);
			u++;
		}
		int piv = i;
		stack_b = malloc(sizeof(int) * (piv + 1));
		int k = 0;
		int rev = piv;
		while (k < piv)
		{
			stack_b[k] = stack_a[rev];
			printf("this is stack_b[%d]: %d\n", k, stack_b[k]);
			k++;
			rev--;
		}*/
	}
	return (stack_a);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int *stack_a = malloc(sizeof(int) * (ac - 1));
		if (!stack_a)
			return (1);

		int i = 1;
		while (i < ac)  
		{
			stack_a[i] = atoi(av[i]); 
			i++;
		}

		push_swap(stack_a, 0, ac - 1); 
		free(stack_a); 
	}
	else
	printf("Error\n");
	return (0);
}
