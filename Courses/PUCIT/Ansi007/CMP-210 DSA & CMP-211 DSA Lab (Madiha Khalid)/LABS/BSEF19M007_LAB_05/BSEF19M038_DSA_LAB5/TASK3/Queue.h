#pragma once
template<class T>		//TEMPLATE CLASS
class Queue
{
private:
	int back;
	int front;
	int size;
	int count;
	T* que;
public:
	Queue();
	Queue(const Queue&);
	void Enqueue(T);
	T Dequeue();			//FUNCTION DECLRATION
	T frontfun();
	T backfun();
	void resize();
	bool isempty();
	bool isfull();
	void showstructure();

};
template<class T>
class Stack	       //STACK CLASS
{
private:
	int size;
public:
	Stack();
	Queue<double> Q1;
	Queue<double> Q2;		//OBJECTS OF QUEUEES
	void push(T);
	T pop();
	bool isempty();			//FUNCTION DECLARATION
	bool isfull();
};
