 #include "Queue.h"

#include<iostream>
using namespace std;
template<class T>
Queue<T>::Queue(int s)
{
	front = 0;
	back = 0;				//constructor
	size = s;
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
	return que[front];				//front function
}
template<class T>
T Queue<T>::backfun()
{
	return que[back];				//back function
}
template<class T>	
void Queue<T>::Enqueue(T val)			//enqueue function
{
	if (!isfull())
	{
		que[back] = val;
		count++;				//if queueu not full then store value in back index and inc the coubt
		if (back + 1 == size)
		{
			back = 0;
		}
		else
		{
			back++;				//increment the back
		}

	}
	else
	{
		resize();			//if queue is full then call resize function
	}

}
template<class T>
T Queue<T>::Dequeue()			//dequeue fUNCTION
{
	if (!isempty())
	{
		if (front+1 == size)
		{
			front = 0;
		}
		count--;					//DEC THE COUNT
		return que[front++];		//RETURN VALUE AT FRONT

	}
	else
	{
		cout << "QUEUE IS EMPTY";		//IF EMPTY THEN DISPLAY MESSAGE 
	}

}
template<class T>
bool Queue<T>::isempty()
{
	return count == 0;			//CHECK IF COUNT==0 THEN RETURN TRUE
}
template<class T>
bool Queue<T>::isfull()
{
	return count == size;		//IF CHECK==SIZE RETURN TRUE ELSE FALSE
}
template<class T>
void Queue<T>::resize()			//RESIZE FUNCTION
{
	if (isfull())
	{
		size = size * 2;		//IF FULL MULTIPLY SIZE WITH 2
	}
	else if (back <= size / 4)
	{
		size = size / 2;		//IF 3/4 PART OF QUEUE IS EMPTY THEN DIVIDE THE SIZE WITH 2
	}
}
template<class T>
void Queue<T>::showstructure()
{
	for (int i = front; i < back; i++)	//START LOOP FROM FRONT TILL BACK
	{
		cout << que[i];			//COUT QUE;
		if (i == back-1)
		{
			cout << ">>>>back" << endl;		//COUT THIS MESSAGE WHERE BACK INDICATES
		}
		else
		{
			cout << endl;
		}
	}
}




