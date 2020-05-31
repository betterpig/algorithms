#include"sort_function.h"

void max_heapify(int *a, int index,int heap_size)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int max = index;
	if (left<heap_size && a[left] > a[max])
		max = left;
	if (right<heap_size && a[right] > a[max])
		max = right;
	if (max != index)
	{
		int temp = a[index];
		a[index] = a[max];
		a[max] = temp;
		max_heapify(a, max,heap_size);
	}
}

void build_max_heap(int* a, int size,int heap_size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		max_heapify(a, i,heap_size);
}

void heap_sort(int* a, int size)
{
	build_max_heap(a, size, size);
	print_array(a, size);
	int heap_size = size;
	for (int i = size - 1; i >= 0; i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heap_size = heap_size - 1;
		max_heapify(a, 0, heap_size);
		print_array(a, size);
	}
}