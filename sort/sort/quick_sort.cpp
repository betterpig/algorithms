#include "sort_function.h"


void sort(int *a, int left, int right)
{
	if (left >= right)
		return;
	int pivot = a[left];
	int i = left, j = right;
	while (i != j)
	{
		while (a[j] >= pivot && i<j)
			j--;

		while (a[i] <= pivot && i < j)
			i++;

		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	a[left] = a[i];
	a[i] = pivot;
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);

	sort(a, left, i - 1);
	sort(a, i + 1, right);
	
}

void quick_sort(int *a, int size)
{
	int left = 0;
	int right = size - 1;
	sort(a, left, right);
}

