#pragma once

template<class T>
class Heap
{
public:
	Heap(int n) :capacity(n), size(0) 
	{ 
		heap = new T[capacity];
		heap[0] = 10000;
	}
	~Heap() {delete[]heap;}

	void adjust(int i);
	void insert(T x);
	T dele();
	void create(T a[],int num);

private:
	int capacity;
	int size;
	T *heap;
};

template<class T>
void Heap<T>::adjust(int parent)
{
	int temp = heap[parent];
	for (int child = 2 * parent; child<=size; child=parent*2)
	{
		if (child + 1 <= size && heap[child + 1] > heap[child])
			child++;
		if (temp > heap[child])
			break;
		else
		{
			heap[parent] = heap[child];
			parent = child;
		}
	}
	heap[parent] = temp;
	return ;
}

template<class T>
void Heap<T>::insert(T x)
{
	size++;
	int child = size;
	for (int parent = child / 2; parent>=1; parent = child / 2)
	{
		if (x < heap[parent])
			break;
		else
		{
			heap[child] = heap[parent];
			child = parent;
		}
	}
	heap[child] = x;
	return;
}

template<class T>
T Heap<T>::dele()
{
	T result = heap[1];
	heap[1] = heap[size];
	heap[size] = -1;
	size--;
	adjust(1);
	return result;
}

template<class T>
void Heap<T>::create(T a[],int num)
{
	size = num;
	for (int i = 1; i <= num; i++)
	{
		heap[i] = a[i-1];
	}
	for (int parent = size / 2; parent >= 1; parent--)
	{
		adjust(parent);
	}
}