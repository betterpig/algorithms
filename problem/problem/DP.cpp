#include "method.h"

int* DP(int* a, int low, int high, int* result)
{
	int sum = 0;
	for (int i = low; i <= high; i++)
	{
		sum = sum + a[i];
		if (sum > result[2])
		{
			result[1] = i;
			result[2] = sum;
		}
		else if (sum < 0)
		{
			sum = 0;
			result[0] = i + 1;
		}
	}
	return result;
}