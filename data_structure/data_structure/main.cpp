#include"common.h"
#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"
#include"hash_table.h"
#include"binary_search_tree.h"
#include"heap.h"
#include"union_find.h"
#include "trie.h"
int main()
{
	vector<string> data = { "w","wo","wor","worl", "world" };
	Trie t;
	for (int i = 0; i < data.size(); i++)
		t.insert(data[i]);
	string result;
	t.destruct(t.GetRoot());
}