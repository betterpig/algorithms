#include"stack.h"
#include"queue.h"
#include"doubly_linked_list.h"
#include"circular_doubly_linked_list.h"


int main()
{
	Circular_doubly_linked_list<int> data;

	data.insert(1);
	data.insert(2);
	data.insert(3);

	data.print_data();
	data.dele(2);
	data.print_data();
}