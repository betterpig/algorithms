#pragma once
#include"common.h"

template<class T>
class Hash_table
{
public:
	Hash_table() 
	{
		size = CAPACITY;
		for (int i = 0; i < size; i++)
		{
			h[i] = nullptr;
		}
	}
	~Hash_table()
	{
		for (int i = 0; i < size; i++)
		{
			node<T>* p = h[i];
			while(p)
			{
				node<T>* temp = p;
				p = p->next;
				delete[]temp;
				temp = nullptr;
			}
		}
	}
	void insert(T k);
	int hash(T k);
	void print_data();

private:
	int size;
	node<T>* h[CAPACITY];
};

template<class T>
void Hash_table<T>::insert(T k)
{
	int hash_value = hash(k);
	if (h[hash_value] == nullptr)
		h[hash_value] = new node<T>(k);
	else
	{
		node<T>* p = h[hash_value];
		while (p->next)
			p = p->next;
		node<T>* temp = new node<T>(k);
		p->next = temp;
	}
}

template<class T>
int Hash_table<T>::hash(T k)
{
	int hash_value = k % size;
	return hash_value;
}

template<class T>
void Hash_table<T>::print_data()
{
	for (int i = 0; i < size; i++)
	{
		node<T>* p = h[i];
		while (p)
		{
			printf("%d  ", p->key);
			p = p->next;
		}
		printf("\n");
	}
}