#include <iostream>
#include"method.h"

int main()
{
	int a[5] = { 1,-3,4,-2,3 };
	int result[3] = { 0 }; 
	DP(a, 0, 4,result);
	std::cout<<result[0]<<"  "<<result[1]<<"  "<<result[2];
	return 1;
}

