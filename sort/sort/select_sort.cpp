#include "sort_function.h"

void select_sort(int *a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for (int j = i+1; j < size; j++)
		{
			if (a[j] < a[j - 1])
				min_index = j;
		}
		int min = a[min_index];
		a[min_index] = a[i];
		a[i] = min;
	}
}