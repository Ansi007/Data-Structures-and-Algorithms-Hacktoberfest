#pragma once
#include <iostream>
using namespace std;

template<class T>
class DList;

/*
DNode class containing information and pointer to the next node.
*/

template<class T>
class DNode
{
public:
	friend DList<T>;
	T info;
	DNode<T>* next;
	DNode<T>* prev;

	DNode(T inInfo, DNode* nPtr = NULL, DNode* pPtr = NULL)
	{
		info = inInfo;
		next = nPtr;
		prev = pPtr;
	}
};

/*
Double Linked List class:
A Double linked list is a linear dynamic data structure to store data items. 
Every node is mainly divided into three parts, one part holds the data and the other two parts 
is connected to a different node. One next and one to the previous
We can add, find and delete nodes.
*/

template<class T>
class DList
{
private:
	DNode <T>* head;
	DNode <T>* tail;
public:
	DList();
	DList(const DList&);
	void setHead(DNode<T>* head);
	void setTail(DNode<T>* tail);
	DNode<T>* getHead();
	DNode<T>* getTail();
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	DNode<T>* getNode(unsigned int n);
	DNode<T>* search(T);
	bool insertAfter(T, T);
	bool insertBefore(T, T);
	bool deleteBefore(T);
	bool deleteAfter(T);
	int getLength();
	~DList();


};
