#include"common.h"
#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"
#include"hash_table.h"
#include"binary_search_tree.h"
#include"heap.h"
#include"set.h"

int main()
{
	int a[] = { -1,0,0,-1,3 };
	Set s(a, 5);

	s.find(2);
	s.union_set(2, 3);
}