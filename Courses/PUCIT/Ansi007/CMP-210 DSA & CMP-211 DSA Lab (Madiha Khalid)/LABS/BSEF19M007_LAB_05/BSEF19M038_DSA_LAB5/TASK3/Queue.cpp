#include "Queue.h"

#include<iostream>
using namespace std;
template<class T>
Queue<T>::Queue()
{
	front = 0;
	back = 0;			// constructor
	size = 20;
	count = 0;
	que = new T[size];

}
template<class T>
Queue<T>::Queue(const Queue& Q1)
{
	front = Q1.front;
	back = Q1.back;
	size = Q1.size;					//copy constructor
	count = Q1.count;
	que = Q1.que;

}
template<class T>
T Queue<T>::frontfun()
{
	return que[front];			//front function
}
template<class T>
T Queue<T>::backfun()
{		
	return que[back];			//back funciton
}
template<class T>
void Queue<T>::Enqueue(T val)
{
	if (!isfull())
	{
		que[back] = val;
		count++;
		if (back + 1 == size)			//put in queue if not full and inc count and back
		{
			back = 0;
		}
		else
		{
			back++;
		}

	}
	else
	{
		cout << "QUEUE IS FULL";
	}

}
template<class T>
T Queue<T>::Dequeue()
{
	if (!isempty())
	{
		if (front + 1 == size)			//return the queueu at front index
		{
			front = 0;
		}
		count--;
		return que[front++];

	}
	else
	{
		cout << "QUEUE IS EMPTY";
	}

}
template<class T>
bool Queue<T>::isempty()
{
	return count == 0;				//check if queue is empty
}
template<class T>
bool Queue<T>::isfull()
{
	return count == size;			//check if queue is full
}
template<class T>
void Queue<T>::resize()
{
	if (isfull())
	{
		size = size * 2;		//multiply size with 2 if full
	}
	else if (back <= size / 4)
	{
		size = size / 2;		//if 3/4 th part of queue is empty then divide it with 2
	}
}
template<class T>
void Queue<T>::showstructure()
{
	for (int i = front; i < back; i++)
	{
		cout << que[i];			//from front to back cout que;
		if (i == back - 1)
		{
			cout << ">>>>back" << endl;		//print this msg where back points
		}
		else
		{
			cout << endl;
		}
	}
}
template<class T>
void  Stack<T>::push(T a)
{
	while (!Q1.isempty())
	{
		double temp = Q1.Dequeue();   //DEQUE Q1 UNTIL IT BECOMES EMPTY
		Q2.Enqueue(temp);				//AND STORE IT IN Q2
	}
	Q1.Enqueue(a);			//enqueue a in Q1
	while (!Q2.isempty())
	{
		double temp = Q2.Dequeue();				//DEQUE Q2 UNITIL IT BECOME EMPTY AND STORE IN Q1
		Q1.Enqueue(temp);
	}
}
template<class T>
T Stack<T>::pop()
{
	return Q1.Dequeue();		//DEQUE Q1 AND RETURN IT
}
template<class T>
bool Stack<T>::isempty()
{
	if (Q1.isempty())			//CHECK IF STACK IS EMPTY
	{
		return true;
	}
}
template<class T>
bool Stack<T>::isfull()
{
	if (Q1.isfull())			//CHECK IF STACK IS FULL
	{
		return true;
	}
}
template<class T>
Stack<T>::Stack()
{
	size = 0;			//CONSTRUCTOR
}





