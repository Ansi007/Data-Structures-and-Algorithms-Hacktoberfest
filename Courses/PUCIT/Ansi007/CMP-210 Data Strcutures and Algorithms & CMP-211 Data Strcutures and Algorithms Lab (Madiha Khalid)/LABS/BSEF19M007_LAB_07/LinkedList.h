#pragma once
#include <iostream>
using namespace std;

/*
Node class containing information and pointer to the next node.
*/
template<class T>
class Node
{
public:
	T info;
	Node<T>* next;

	Node(T inInfo, Node* nPtr = NULL)
	{
		info = inInfo;
		next = nPtr;
	}
};
/*
Linked List class:
A linked list is a linear dynamic data structure to store data items. 
Every node is mainly divided into two parts, one part holds the data and the other part 
is connected to a different node.
We can add, find and delete nodes.
*/

template<class T>
class LinkedList
{
private:
	Node <T>* head;
	Node <T>* tail;
public:
	LinkedList();
	LinkedList(const LinkedList&);
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	Node<T>* getNode(unsigned int n);
	bool insertAfter(T, T);
	bool insertBefore(T, T);
	bool deleteBefore(T);
	bool deleteAfter(T);
	Node<T>* search(T);
	int getLength();
	~LinkedList();


};

