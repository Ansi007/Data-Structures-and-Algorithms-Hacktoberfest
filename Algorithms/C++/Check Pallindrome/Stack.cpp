#ifndef STACK
#define STACK

#include<iostream>

using namespace std;

template <class T>
class Stack{
	T* stack;
	int capacity;
	int top;

public:
	Stack(int c)
	{
		this->capacity = c;
		stack = new T[capacity];
		top = -1;
	}

	bool isFull()
	{
		return (top == capacity - 1);
	}

	bool isEmpty()
	{
		return (top == -1);
	}

	T viewTop()
	{
		if( !isEmpty() )
			return stack[top];
		cout << "\nStack is Empty\n";
		return 0;
	}

	void push( T element )
	{
		if( !isFull() )
			stack[++top] = element;
		else
			cout << "\nStack is Full\n";
	}

	T pop()
	{
		if( !isEmpty() )
			return stack[top--];
		cout << "\nStack is Empty\n";
		return 0;
	}
};

#endif