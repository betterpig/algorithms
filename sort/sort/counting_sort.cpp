#include "sort_function.h"

void counting_sort(int* a,int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	int *c = new int[max + 1];
	int *b = new int[size];
	
	for (int i = 0; i <= max; i++)
		c[i] = 0;

	for (int i = 0; i <size; i++)
	{
		int position = a[i];
		c[position] = c[position] + 1;
	}

	for (int i = 1; i <=max; i++)
		c[i] = c[i - 1] + c[i];
	print_array(c, max + 1);
	for (int i = size-1; i >= 0; i--)
	{
		int value = a[i];
		int position = c[value];
		b[position-1] = value;
		c[value] = c[value] - 1;
	}
	for (int i = 0; i < size; i++)
		a[i] = b[i];
}