#include "sort_function.h"
#include <iostream>

using namespace std;

int main()
{
	int a[9] = { 9,8,7,6,5,4,3,2,1 };
	int size = 9;
	select_sort(a, size);
	
    return 0;
}

