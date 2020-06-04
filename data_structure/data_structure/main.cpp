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

	data.insert(8);
	data.insert(2);
	data.insert(5);
	data.insert(4);
	data.insert(1);

	data.inorder2_print(data.get_root());
	printf("\n");
	data.preorder2_print(data.get_root());
	printf("\n");
	data.postorder2_print(data.get_root());
}