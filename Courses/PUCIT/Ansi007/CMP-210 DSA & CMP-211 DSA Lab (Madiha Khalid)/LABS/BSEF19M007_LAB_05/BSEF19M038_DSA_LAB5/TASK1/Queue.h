#pragma once
template<class T>			//TEMPLATE CLASS
class Queue
{
private:
	int back;
	int front;		//DATA MEMBERS
	int size;
	int count;
	T* que;
public:
	Queue(int);
	Queue(const Queue&);
	void Enqueue(T);
	T Dequeue();
	T frontfun();				//FUNCTION DECLRATIONS
	T backfun();
	void resize();
	bool isempty();
	bool isfull();
	void showstructure();

};

