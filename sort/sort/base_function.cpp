#include"sort_function.h"

void print_array(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

void print_list(node* head)
{
	node* p = head;
	while (p)
	{
		printf("%d  ", p->value);
		p = p->next;
	}
	printf("\n");
}