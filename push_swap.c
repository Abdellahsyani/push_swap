#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**int	*push_swap(int *stack_a, int low, int high)
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
		int u = low;
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
		}
	}
	return (stack_a);
}*/
int	*push_swap(int *stack_a, int low, int high)
{
    printf("\nStarting push_swap with low: %d, high: %d\n", low, high);
    
    int	*stack_b = NULL;
    if (low < high)
    {
        int	pivot = stack_a[high];
        printf("Pivot value: %d\n", pivot);
        
        int	i = low - 1;
        int	j = low;
        
        // Partition part
        while (j < high)
        {
            printf("Comparing stack_a[%d]=%d with pivot %d\n", j, stack_a[j], pivot);
            if (stack_a[j] < pivot)
            {
                i++;
                printf("Swapping positions %d and %d\n", i, j);
                swap(&stack_a[i], &stack_a[j]);
            }
            j++;
        }
        printf("Final i value before pivot swap: %d\n", i);
        swap(&stack_a[i + 1], &stack_a[high]);
        
        printf("\nStack A after partition:\n");
        for (int u = low; u <= high; u++)
        {
            printf("stack_a[%d]: %d\n", u, stack_a[u]);
        }
        
        int piv = i;
        printf("\nCalculated piv: %d\n", piv);
        
        // Check if piv is valid for malloc
        if (piv < 0)
        {
            printf("Error: Invalid pivot value for malloc\n");
            return stack_a;
        }
        
        printf("Attempting to malloc size: %zu bytes\n", sizeof(int) * (piv + 1));
        stack_b = malloc(sizeof(int) * (piv + 1));
        if (!stack_b)
        {
            printf("Malloc failed!\n");
            return stack_a;
        }
        
        int k = 0;
        int rev = piv;
        printf("\nCopying elements to stack_b:\n");
        while (k <= piv && rev >= 0)  // Added safety check for rev
        {
            printf("Copying from stack_a[%d] to stack_b[%d]\n", rev, k);
            stack_b[k] = stack_a[rev];
            printf("stack_b[%d]: %d\n", k, stack_b[k]);
            k++;
            rev--;
        }
    }
    return (stack_a);
}


/*int	main(int ac, char **av)
{
	int i = 1;
	int *stack_a = malloc(sizeof(int) * (ac - 1));
	if (ac > 1)
	{
		while (i < ac)
		{
			stack_a[i] = atoi(av[i]);
			i++;
		}
		push_swap(stack_a, 0, ac - 1);
	}
	else
		printf("Error\n");
	return (0);
}*/

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int *stack_a = malloc(sizeof(int) * (ac - 1));
        if (!stack_a)
            return (1);
            
        // Fill array starting from index 0
        int i = 0;                      // Start from 0
        while (i < ac - 1)              // Go up to ac - 1
        {
            stack_a[i] = atoi(av[i + 1]); // Use av[i + 1] to skip program name
            i++;
        }
        
        push_swap(stack_a, 0, ac - 2);    // High should be (ac-1)-1
        free(stack_a);                     // Don't forget to free
    }
    else
        printf("Error\n");
    return (0);
}
