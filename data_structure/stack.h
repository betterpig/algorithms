#include<iostream>
#include"common.h"

template<class T>
class Stack
{
public:
	Stack()
	{
		size = CAPACITY;
		top = -1;
		s = new T[size];
	}
	Stack(int size_):size(size_), top(-1)
	{
		s = new T[size];
	}
	~Stack()
	{
		delete []s;
		s = nullptr;
	}

	bool empty();
	void push(T x);
	T pop();
	void print_data();
	T get_top() { return s[top]; }

private:
	int size;
	int top;
	T *s;
};

template<class T>
bool Stack<T>::empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template<class T>
void Stack<T>::push(T x)
{
	if (top == size - 1)
		throw "stack overflow!";

	top = top + 1;
	s[top] = x;
}

template<class T>
T Stack<T>::pop()
{
	if (empty())
		throw "stack underflow!";
	T temp = s[top];
	top = top - 1;
	return temp;
}

template<class T>
void Stack<T>::print_data()
{
	for (int i = 0; i <= top; i++)
		printf("%d  ", s[i]);
	printf("\n");
}