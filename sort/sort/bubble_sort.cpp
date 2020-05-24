#include "sort_function.h"

void bubble_sort(int *a, int size)
{
	int last = size - 1;
	while (last > 0)
	{
		for (int i = 0; i < last; i++)
		{
			if (a[i] > a[i + 1])
			{
				int temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
			}
		}
		last=last - 1;
	}
	return;
}