#include "method.h"

int* brute_force(int* a, int low, int high, int* result)
{
	
	for (int num = 1; num < high + 1; num++)
	{
		for (int i = 0; i + num -1<= high; i++)
		{
			int sum = 0;
			for (int j = 0; j <= num-1; j++)
			{
				sum = sum + a[i+j];
			}
			if (sum > result[2])
			{
				result[0] = i;
				result[1] = i + num-1;
				result[2] = sum;
			}
		}
	}
	return result;
}

int* brute_force2(int* a, int low, int high, int* result)
{
	for (int i = low; i <= high; i++)
	{
		int sum = 0;
		for (int j = i ; j <= high; j++)
		{
			sum = sum + a[j];
			if (sum > result[2])
			{
				result[0] = i;
				result[1] = j;
				result[2] = sum;
			}
		}
	}
	return result;
}