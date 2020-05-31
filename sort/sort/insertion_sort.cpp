#include "sort_function.h"

void insertion_sort(int *a, int size)
{
	for (int j = 1; j < size; j++)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i+1] = key;
	}
	return;
}

void insertion_sort2(node** head)//如果只是node*，那传进来的是指向头节点的指针，只能修改头节点以后的；如果是node**，那传进来的是指向头节点的指针的地址，可以修改该指针指向的内容
{
	if (!(*head) || !(*head)->next)
		return ;

	node* null_head = new node(0,*head);
	node* p_pre = *head;
	node* p = (*head)->next;
	while (p)
	{
		node* p_compare_pre = null_head;
		node* p_compare = *head;
		while (p_compare != p && p->value > p_compare->value)
		{
			p_compare_pre = p_compare;
			p_compare = p_compare->next;
		}
		if (p->value < p_compare->value)
		{
			node* temp = p;

			p_pre->next = p->next;
			p = p->next;

			p_compare_pre->next = temp;
			temp->next = p_compare;
		}
		else
		{
			p_pre = p;
			p = p->next;
		}
		print_list(null_head->next);
	}
	*head = null_head->next;
}