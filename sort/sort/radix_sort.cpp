#include"sort_function.h"

void radix_sort(int* a, int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	int digits = log10(max)+1;

	for (int i = 1; i <= digits; i++)
	{
		node* bucket[10] = {};
		int mod = pow(10, i);
		int dev = pow(10, i - 1);
		for (int j = 0; j < size; j++)
		{
			int position = (a[j] % mod) / dev;
			node* p = bucket[position];
			if (!p)
			{
				bucket[position] = new node(a[j]);
			}
			else
			{
				while (p->next)
				{
					p = p->next;
				}
				node* temp = new node(a[j]);
				p->next = temp;
			}
		}

		int j = 0;
		for (int i = 0; i < 10; i++)
		{
			node* p = bucket[i];
			while (p)
			{
				a[j] = p->value;
				j++;
				p = p->next;
			}
		}
	}
}