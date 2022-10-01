#include<iostream>
#include"Queue.h"
#include"Queue.cpp"

using namespace std;


int main() {
	Queue<double> queue;

	queue.enQueue(5.0);
	queue.enQueue(6.5);
	queue.showStructure();
	cout << endl;

	queue.enQueue(-3.0);
	queue.enQueue(-8.0);
	queue.showStructure();
	cout << endl;

	queue.deQueue();
	queue.deQueue();
	queue.showStructure();

	return 0;
}
