#include "sort_function.h"

void merge(int *a, int left, int mid, int right, int *temp)
{
	int left_pointer = left;
	int right_pointer = mid + 1;
	int temp_pointer = left;

	while (left_pointer <= mid && right_pointer <= right)
	{
		if (a[left_pointer] <= a[right_pointer])
		{
			temp[temp_pointer] = a[left_pointer];
			left_pointer++;
		}
		else
		{
			temp[temp_pointer] = a[right_pointer];
			right_pointer++;
		}
		temp_pointer++;
	}

	for(;left_pointer <= mid;left_pointer++)
	{
		temp[temp_pointer] = a[left_pointer];
		temp_pointer++;
	}

	for (;right_pointer <= right;right_pointer++)
	{
		temp[temp_pointer] = a[right_pointer];
		temp_pointer++;
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = temp[i];
	}
	//std::cout << "left" << left << "    right" << right << "    a" << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << a[6] << a[7] << a[8] << std::endl;
	return;
}

void sort(int *a, int left, int right, int *temp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		sort(a, left, mid, temp);
		sort(a, mid + 1, right, temp);
		merge(a, left, mid, right, temp);
	}
	return;
}

void merge_sort(int *a, int size)
{
	int left = 0;
	int right = size - 1;
	int *temp = new int[size];
	sort(a, left, right, temp);
	return;
}