#include "method.h"

void max_crossing_subarray(int *a, int low, int mid, int high,int* result)
{
	int left_sum = -INF;
	int sum = 0;
	result[0] = mid;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			result[0] = i;
		}
	}

	int right_sum = -INF;
	sum = 0;
	result[1] = mid+1;
	for (int i = mid+1; i <= high; i++)
	{
		sum = sum + a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			result[1] = i;
		}
	}

	result[2] = left_sum + right_sum;
	return ;
}

int* divide_conquer(int* a, int low, int high,int* result)
{
	if (low == high)
	{
		result[0] = low;
		result[1] = high;
		result[2] = a[low];
		return result;
	}
	
	int mid = (low + high) / 2;
	int left_result[3] = { 0 }; 
	int right_result[3] = { 0 };
	int cross_result[3] = { 0 };
	divide_conquer(a, low, mid, left_result);
	divide_conquer(a, mid + 1, high, right_result);
	max_crossing_subarray(a, low, mid, high, cross_result);
	if (left_result[2] > right_result[2] && left_result[2] > cross_result[2])
	{
		result[0] = left_result[0];
		result[1] = left_result[1];
		result[2] = left_result[2];
		return result;
	}
	else if ((right_result[2] > left_result[2] && right_result[2] > cross_result[2]))
	{
		result[0] = right_result[0];
		result[1] = right_result[1];
		result[2] = right_result[2];
		return result;
	}
	else
	{
		result[0] = cross_result[0];
		result[1] = cross_result[1];
		result[2] = cross_result[2];
		return result;
	}
}
