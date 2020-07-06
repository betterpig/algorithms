#include"common.h"
#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"
#include"hash_table.h"
#include"binary_search_tree.h"


int main()
{
	BST<int> data;

	data.insert(9);
	data.insert(3);
	data.insert(20);
	data.insert(15);
	data.insert(25);

	data.inorder2_print(data.get_root());
	printf("\n");
	data.preorder3_print(data.get_root());
	printf("\n");
	data.levelorder_print(data.get_root());
}