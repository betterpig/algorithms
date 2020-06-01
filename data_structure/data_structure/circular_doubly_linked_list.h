#pragma once
#include<iostream>
#include"doubly_linked_list.h"

template<class T>
class Circular_doubly_linked_list
{
public:
	Circular_doubly_linked_list() 
	{ 
		sentinel = new node<T>(0); 
		sentinel->next = sentinel;
		sentinel->pre = sentinel;
	}
	~Circular_doubly_linked_list()
	{
		node<T>* p = sentinel->next;
		while (p!=sentinel)
		{
			node<T>* temp = p;
			p = p->next;
			delete temp;
			temp = nullptr;
		}
		delete sentinel;
		sentinel = nullptr;
	}

	node<T>* search(T k);
	void insert(node<T>* x);
	void insert(T k);
	void dele(T k);
	void print_data();
private:
	node<T>* sentinel;
};

template<class T>
node<T>* Circular_doubly_linked_list<T>::search(T k)
{
	node<T>* p = sentinel->next;
	while (p && p->key != k)
		p = p->next;
	return p;
}

template<class T>
void Circular_doubly_linked_list<T>::insert(node<T>* x)
{
	x->next = sentinel->next;
	sentinel->next->pre = x;
	sentinel->next = x;
	x->pre = sentinel;
}

template<class T>
void Circular_doubly_linked_list<T>::insert(T k)
{
	node<T>* temp = new node<T>(k);
	insert(temp);
}

template<class T>
void Circular_doubly_linked_list<T>::dele(T k)
{
	node<T>* temp = search(k);
	if (!temp)
	{
		printf("%s \n", "no such element");
		return;
	}

	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
	delete temp;
}

template<class T>
void Circular_doubly_linked_list<T>::print_data()
{
	node<T>* p = sentinel->next;
	while (p!=sentinel)
	{
		printf("%d  ", p->key);
		p = p->next;
	}
	printf("\n");
}