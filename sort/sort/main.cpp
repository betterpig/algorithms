#include "sort_function.h"
#include <iostream>

using namespace std;

int main()
{
	int a[9] = { 66,23,23,201,38,9,101,21,2};
	int size =9;
	heap_sort(a, size);
	
    return 0;
}

