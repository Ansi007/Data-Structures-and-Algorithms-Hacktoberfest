#include "Queue.h"
#include "Queue.cpp"
#include <iostream>

using namespace std;
/*
Class MyStack: Implemented with the help of Queue ADT.
*/

template<class T>
class MyStack {
private:
	Queue<T> Main, temp;		//One is Main queue and the other is secondary
public:
	void push(T x) {

		/*
		This function uses two queues to stimulate stack behaviour.
		*/
		while (!Main.isEmpty()) {
			temp.enQueue(Main.deQueue());
		}

		Main.enQueue(x);

		while (!temp.isEmpty()) {
			Main.enQueue(temp.deQueue());
		}
	}

	T pop() {
		// It returns the top element
		return Main.deQueue();
	}

	bool isFull() {
		return Main.isFull();
	}

	bool isEmpty() {
		return Main.isEmpty();
	}

};


int main() {
	MyStack<int> S;

	for (int i = 0; i < 15; i++)
		S.push(i);

	while (!S.isEmpty())
		cout << S.pop() << " ";

	return 0;

}