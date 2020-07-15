#include"common.h"
#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"
#include"hash_table.h"
#include"binary_search_tree.h"
#include"heap.h"
#include"union_find.h"

int main()
{
	string data="5,3,6,2,4,#,7 ";
	tree_node<int>* root = deserialize(data);

	BST<int> bst(root);
	
	bst.dele(bst.get_root(),5);
}