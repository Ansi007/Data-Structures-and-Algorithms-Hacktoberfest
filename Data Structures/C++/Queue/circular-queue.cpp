#include <iostream>

using namespace std;

class Queue {

int *arr ;
int size , rear , front;

public:
    Queue (int size) {
        this->size = size ;
        arr = new int[size] ;
        front = rear = -1;
    }

    void enqueue (int data) {
        if (!isfull()) {
            rear = (rear + 1) % size ;
            arr[rear] = data ;
        }
        else cout << "Queue is full\n" ;
    }

    int dequeue () {
        if (!isempty()) {
            front = (front + 1) % size ;
            return arr[front];
        }
        else return -1;     
    }

    bool isempty() {
        if (front == (rear + 1) % size) return true;
        return false ;
    }

    bool isfull(){
        if ((rear + 1) % size == front) return true;
        return false;
    }

};

int main () {
    int size ;
    cout << "Enter size of queue: " ;
    cin >> size ;
    Queue q(size);
    q.enqueue(2) ;
    q.enqueue(5) ;
    cout << q.dequeue();
    q.enqueue(13) ;
    q.enqueue(12) ;
}