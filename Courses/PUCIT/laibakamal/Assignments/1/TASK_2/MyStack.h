//BSEF19M003
//LAIBA KAMAL



#pragma once

template <class T>//template class type specification
class MyStack//template class "MyStack" to implement stack
{
	T* myStackArray;//It will allocate dynamic memory (for type T variables) through new keyword 
	int size;//size of stack (dynamic array)
	int top;//always represent the top index of stack
	void resize();//(maintains capacity of stack) if the stack is full, increases the size by 2 times. Likewise when there are less than 1/4 elements in the stack compared to the available capacity, it decreases the size it by 1/2 times
public:
	MyStack();
	MyStack(int);//parameterized constructor : sets the data members of class to some specific values
	void push(T value);//takes some value as its parameter and pushes the value on stack (puts it at the end of stack array)
	T pop();//always returns last element of stack array and decrements top
	T peak();//always returns the last element of stack array
	bool isEmpty();//returns true if stack is empty and false if not.
	bool isFull();//returns true if stack is full and false if not.
	void printStack();//prints the stack from open end to the close end
	int getTop();//returns the last index of stack array
};


//BSEF19M003
//LAIBA KAMAL
