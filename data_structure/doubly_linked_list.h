#pragma once
#include"common.h"

template<class T>
class Doubly_linked_list
{
public:
	Doubly_linked_list() { head = nullptr; }
	~Doubly_linked_list()
	{
		while (head)
		{
			node<T>* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
	}
	
	node<T>* search(T k);
	void insert(node<T>* x);
	void insert(T k);
	void dele(T k);
	void print_data();
private:
	node<T>* head;
};

template<class T>
node<T>* Doubly_linked_list<T>::search(T k)
{
	node<T>* p = head;
	while (p && p->key != k)
		p = p->next;
	return p;
}

template<class T>
void Doubly_linked_list<T>::insert(node<T>* x)
{
	x->next = head;
	if (head)
		head->pre = x;
	head = x;
	x->pre = nullptr;
}

template<class T>
void Doubly_linked_list<T>::insert(T k)
{
	node<T>* temp = new node<T>(k);
	insert(temp);
}

template<class T>
void Doubly_linked_list<T>::dele(T k)
{
	node<T>* temp = search(k);
	if (!temp)
	{
		printf("%s \n","no such element");
		return;
	}
	if (temp->pre)
		temp->pre->next = temp->next;
	else
		head = temp->next;
	if (temp->next)
		temp->next->pre = temp->pre;
	delete temp;
}

template<class T>
void Doubly_linked_list<T>::print_data()
{
	node<T>* p = head;
	while (p)
	{
		printf("%d  ",p->key);
		p = p->next;
	}
	printf("\n");
}