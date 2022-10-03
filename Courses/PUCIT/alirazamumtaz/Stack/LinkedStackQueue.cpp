#include <iostream>

using namespace std;

#define DUMMY 0

class Node{
public:
	int data;
	Node* next;
	Node(int n=0){
		data = n;
		next = NULL;
	}
};
class LinkedStackQueue{ 
	Node *first, *last;
	int getFirstElement(){
		if (first->next==NULL)	throw ("does not exist");
		Node *t = first -> next;
		first -> next = t -> next;
		int res = t -> data;
		delete t;
		return res;
	}
	int seeFirstElement(){
		if (first->next==NULL)	throw (0);
		return first -> next -> data ;
	}
public:
	LinkedStackQueue(){	first = new Node(DUMMY);	last = NULL;	}
	void push(int d){
		first -> next = new Node (d, first -> next);
	}
	void enqueue(int d){
		if (last == NULL)	first -> next = last = new Node(d);
		else 				last = last -> next = new Node (d);
	}
	int pop(){
		if (first->next==NULL)	throw (0);
		Node *t = first -> next;
		first -> next = t -> next;
		int res = t -> data;
		delete t;
		return res;
	}
	int dequeue(){
		return getFirstElement();
	}
	int seeTop(){
		return seeFirstElement();
	}
	int seeFirst(){
		return seeFirstElement();
	}
};
int main(){
	LinkedStackQueue stackQueue;
	try{
		stackQueue.pop();
	}catch(int i){
		cout << "Stack is empty\n";
	}
	stackQueue.push(23);
	stackQueue.push(33);
	stackQueue.push(43);
	cout << stackQueue.pop() << '\n';
	cout << stackQueue.pop() << '\n';
	stackQueue.push(53);
	cout << stackQueue.pop() << '\n';
	cout << stackQueue.pop() << '\n';
	cout << "Now test queue\n";
	stackQueue.enqueue(32);
	stackQueue.enqueue(42);
	stackQueue.enqueue(52);
	cout << stackQueue.dequeue() << '\n';
	cout << stackQueue.dequeue() << '\n';
	stackQueue.enqueue(62);
	cout << stackQueue.dequeue() << '\n';
	cout << stackQueue.dequeue() << '\n';
	return 0;
}
