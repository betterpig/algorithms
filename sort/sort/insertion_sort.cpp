#include "sort_function.h"

void insertion_sort(int *a, int size)
{
	for (int j = 1; j < size; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i+1] = key;
	}
	return;
}
