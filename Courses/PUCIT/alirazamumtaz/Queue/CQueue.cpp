#include <iostream>

using namespace std;

class CQueue{
	int *x, front, rear, size;
public:
	CQueue(int s=10){	
		size = s;
		x = new int[size];
		front = rear = -1;
	}
	bool isFull() const{
		return ( ( front == 0 && rear == size-1 )  || ( front - 1 == rear ) );
	}
	bool isEmpty() const{
		return front == -1;
	}
	void enqueue(int d){
		if (isFull())	throw (0);
		if (front == -1) 
	      	front = rear = 0;
  	 	else {
      		if (rear == size - 1)	rear = 0;
      		else		      		rear++;
   		}
   		x[rear] = d ;
	}
	int dequeue(){
		if (isEmpty())	throw (0);
		int res = x[front];
		if (front == rear) 
      		front = rear = -1;
		else {
      		if (front == size - 1)	    front = 0;
      		else				      	front++;
   		}
   		return res;
	}
	~CQueue(){
		delete []x;
	}
};

int main(){
	CQueue q;
	q.enqueue(23);
	q.enqueue(31);
	q.enqueue(54);
	q.enqueue(13);
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	q.enqueue(14);
	q.enqueue(33);
	q.enqueue(63);
	q.enqueue(37);
	q.enqueue(84);
	q.enqueue(93);
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	q.enqueue(74);
	q.enqueue(3);
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	cout << q.dequeue() << '\n';
	return 0;
}
