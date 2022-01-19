#include<iostream>
#include"Queue.h"
#include"Queue.cpp"

using namespace std;

int main() {
	Priority_Queue<int> queue;

	queue.enQueue(10);
	queue.enQueue(30);
	queue.enQueue(20);
	queue.enQueue(5);
	queue.enQueue(1); 

	cout << "=> The priority queue is : ";
	while (!queue.isEmpty()) 
		cout << queue.deQueue() << " ";
	cout << endl;

	return 0;
}
