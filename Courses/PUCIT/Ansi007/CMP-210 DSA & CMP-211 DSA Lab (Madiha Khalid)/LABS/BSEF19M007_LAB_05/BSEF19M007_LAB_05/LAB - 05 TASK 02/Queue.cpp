#include "Queue.h"
#include<iostream>

using namespace std;

template<class T>
Queue<T>::Queue() {
	Count = 0;
	front = -1;
	rear = -1;
	size = 100;
	queue = new T[size];
}

template<class T>
Queue<T>::Queue(const Queue& Q) {
	Count = Q.Count;
	front = Q.front;
	rear = Q.rear;
	size = Q.size;
	queue = new T[size];
}


template<class T>
Queue<T>::Queue(int s) {
	Count = 0;
	front = -1;
	rear = -1;
	size = s;
	queue = new T[size];
}


template<class T>
void Queue<T>::enQueue(T x)
{
	/*
	This function adds an element to the rear of Queue
	:param: Any element 
	*/

	if (isFull())
		resize();

	rear = (rear + 1) % size;
	queue[rear] = x;
	Count++;


}

template<class T>
T Queue<T>::Front()
{
	/*
	This function returns the front element 
	*/

	if (isEmpty())
	{
		cout << "Queue is empty\n";
		return -1;
	}

	return queue[front];
}

template<class T>
T Queue<T>::Rear()
{
	/*
	This function returns the rear element
	*/

	if (isEmpty())
	{
		cout << "Queue is empty\n";
		return -1;
	}

	return queue[rear];
}

template<class T>
T Queue<T>::deQueue()
{
	/*
	This function returns/removes the front element
	:return: Front Element
	*/

	if (!isEmpty()) {
		Count--;
		front = (front + 1) % size;
		return queue[front];
	}

	else {
		resize();
	}
}

template<class T>
bool Queue<T>::isFull() {
	return Count == size;
}

template<class T>
bool Queue<T>::isEmpty() {
	return Count == 0;
}

template<class T>
void Queue<T>::showStructure() {

	/*
	This function shows the complete queue structure
	*/

	if (!isEmpty()) {
		if (front == -1)
			front = 0;

		for (int i = front; i <= rear; i++) {
			cout << queue[i];
			if (i != rear)
				cout << endl;
		}

		if (rear < front) {
			for (int i = front; i < size; i++)
				cout << queue[i] << endl;

			for (int i = 0; i <= rear; i++) {
				cout << queue[i];
				if (i != rear)
					cout << endl;
			}
		}
		cout << "\t <-- rear";
		cout << endl;
	}
}

template<class T>
void Queue<T>::resize() {
	/*
	This function resizes the Queue. Size is 2 times if it is full or if it's empty size if halved.
	*/

	if (isFull()) {
		int oSize = size;
		size *= 2;
		T* temp = new T[size];
		for (int i = 0; i < oSize; i++) {
			temp[i] = queue[i];
		}
		rear = oSize - 1;
		delete[]queue;
		queue = temp;
	}

	else if (isEmpty()) {
		size = ceil(size / 2.0);
		T* temp = new T[size];
		delete[]queue;
		queue = temp;
	}


}

template<class T>
Queue<T>::~Queue() {
	delete[] queue;
}


template<class T>
void Priority_Queue<T>::enQueue(T x)
{	/*
	This function adds an element to the rear of Queue
	:param: Any element 
	*/

	if (this->isFull())
		this->resize();

	this->rear = this->Count;
	this->queue[this->rear] = x;
	this->Count++;
}


template<class T>
T Priority_Queue<T>::deQueue()
{
	/*
	This function removes the element with the highest priority
	:return: Highest priority element
	*/
	//Big-oh(n^2)

	if (!(this->isEmpty())) {
		this->prioritize();
		T ret;
		this->Count--;
		this->front = 0;
		ret = this->queue[this->front];
		this->queue[this->front] = INT_MIN;
		if (ret != INT_MIN)
			return ret;
	}

	else {
		this->resize();
	}
}

template<class T>
void Priority_Queue<T>::prioritize()
{
	/*
	This function sorts/give priority to the queue
	*/
	//Big-oh(n^2)
	T temp;
	for (int i = 0; i < this->size; i++) {
		for (int j = i + 1; j < this->size; j++) {
			if (this->queue[i] < this->queue[j]) {
				temp = this->queue[i];
				this->queue[i] = this->queue[j];
				this->queue[j] = temp;
			}
		}
	}
}
