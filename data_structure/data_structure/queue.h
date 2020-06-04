#pragma once
#include"common.h"

template<class T>
class Queue
{
public:
	Queue():size(CAPACITY), head(0), tail(0) { q = new T[size]; }
	Queue(int size_):size(size_),head(0),tail(0){ q = new T[size]; }
	~Queue()
	{
		delete[]q;
		q = nullptr;
	}
	bool empty();
	void enqueue(T x);
	T dequeue();
	void print_data();

private:
	int size;
	int head;
	int tail;
	T* q;
};

template<class T>
bool Queue<T>::empty()
{
	if (head == tail)
		return true;
	else
		return false;
}

template<class T>
void Queue<T>::enqueue(T x)
{
	if (head == (tail+1)%size)
		throw "queue overflow!";
	q[tail] = x;
	tail = (tail + 1)%size;
}

template<class T>
T Queue<T>::dequeue()
{
	if (empty())
		throw "queue underflow!";
	T temp = q[head];
	head = head + 1;
	return temp;
}

template<class T>
void Queue<T>::print_data()
{
	for (int i = head; i != tail; i=(i+1)%size)
		printf("%d  ", q[i]);
	printf("\n");
}