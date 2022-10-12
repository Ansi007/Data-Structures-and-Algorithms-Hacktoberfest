#ifndef QUEUE
#define QUEUE
#include<iostream>


using namespace std;

template <class T>
class Queue{
    T* queue;
    int size;
    int front, rear;
public:
    Queue(int s=50)
    {
        this->size = s;
        queue = new T[size];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == size - 1);
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    void enqueue( T element )
    {
        if( !isFull() )
        {
            queue[++rear] = element;
            if( front == -1 )
                front  = 0;
        }
    }

    T dequeue()
    {
        if( !isEmpty() )
        {
            T e = queue[front];
            if( front == rear )
            {
                front = -1;
                rear = -1;
            }
            else
                front++;
            return e;
        }
        return 0;
    }
};
#endif
