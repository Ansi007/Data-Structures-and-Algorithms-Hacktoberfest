#include <iostream>

using namespace std;

class CircularQueue{
	int *arr, size, front, rear;
public:
	CircularQueue(int size){
		this->size = size;
		arr = new int[size];
		front = rear = -1;
	}
	void enQueue(int val){
		if((front == 0 and rear == size-1) or rear == front-1)
			throw (0);
		if(front==-1)  front = 0;
		rear = (rear+1) % size;
		arr[rear] = val;
	}
	int deQueue(){
		if(front == -1) throw(0);
		int result = arr[front];
		if(front == rear) front = rear = -1;
		else if(front == size-1) front = 0;
		else front += 1;
		return result;
	}
	void printQueue(){
		if(front == -1 and rear == -1){
			cout << "Queue is empty.\n";
			return;
		}
		for(int i = front; i <= rear; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	~CircularQueue(){
		delete []arr;
	}
};
int main(int argc, char const *argv[]){
	CircularQueue q(5);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	// q.enqQeue(1);
	// q.enqQeue(4);.
	q.printQueue();
	for (int i = 0; i < 4; ++i){
		cout << q.deQueue() << ' ';
	}
	cout << '\n';
	q.printQueue();
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(1);
	// q.enqQeue(4);.
	q.printQueue();

	return 0;
}