#include"sort_function.h"

void shell_sort(int* a, int size)
{
	int exponent = log(size)/log(2)-2;
	for (int d = pow(2, exponent)-1; exponent > 0; exponent--)
	{
		for (int j = d; j < size; j++)
		{
			int key = a[j];
			int i = j - d;
			while (i >= 0 && a[i] > key)
			{
				a[i + d] = a[i];
				i = i - d;
			}
			a[i + d] = key;
		}
	}
}