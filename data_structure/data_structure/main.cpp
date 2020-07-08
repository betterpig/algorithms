#include"common.h"
#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"
#include"hash_table.h"
#include"binary_search_tree.h"
#include"heap.h"

int main()
{
	Heap<int> h(1000);
	int a[] = { 1,2,3,4,5 };
	h.create(a, 5);

	h.insert(8);
	h.dele();
}