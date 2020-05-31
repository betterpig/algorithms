#include "sort_function.h"

void bucket_sort(int* a, int size)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int bucket_size = 5;
	int interval = (max - min) / 5+1;
	node* bucket[5] = {};//如果写成node* bucket[5]; 则bucket数组只是声明，没有定义，没有分配内存空间，所以访问不了！加了=｛｝就是定义，就分了内存，可以访问，尽管是空指针

	for (int i = 0; i < size; i++)
	{
		int position = (a[i] - min) / interval;
		node* p = bucket[position];
		if (!p)
		{
			bucket[position] = new node(a[i]);
		}
		else 
		{
			while (p->next)
			{
				p = p->next;
			}
			node* temp = new node(a[i]);
			p->next = temp;
		}
	}

	int j = 0;
	for (int i = 0; i < bucket_size; i++)
	{
		
		insertion_sort2(&bucket[i]);
		node* p = bucket[i];
		while (p)
		{
			a[j] = p->value;
			j++;
			p = p->next;
		}
	}
}