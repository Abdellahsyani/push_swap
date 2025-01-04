#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

int	*Quick_sort(int *arr, int low, int high)
{
	if (low < high)
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
	}
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
