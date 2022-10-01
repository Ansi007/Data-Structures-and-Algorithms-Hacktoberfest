#pragma once
/*
Queue class having functionality of Enqueue, Dequeue and some associative features (isEmpty etc.)
*/

template<class T>
class Queue {
public:
	T* queue;
	int size;
	int rear, front;
	int Count;

public:
	Queue();
	Queue(const Queue&);
	Queue(int);
	void enQueue(T);
	T deQueue();
	T Front();
	T Rear();
	bool isFull();
	bool isEmpty();
	void showStructure();
	void resize();
	~Queue();
};

/*
*ASSUMPTIONS*
Priority queues are a type of container adapters, specifically designed such that the first element of the queue 
is the greatest of all elements in the queue and elements are in non increasing order 
(hence we can see that each element of the queue has a priority {fixed order}).
*/

template <class T>
class Priority_Queue : public Queue<T> {
public:
	void enQueue(T);
	T deQueue();
	void prioritize();
};
