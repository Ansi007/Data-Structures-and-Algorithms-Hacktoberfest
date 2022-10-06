

//BSEF19M003
//LAIBA KAMAL
#pragma once
#include"XorNode.cpp"

template<class T>
class XorDLL
{
private:
	XorNode <T>* head;
	XorNode <T>* tail;
public:
	XorDLL();//constructor
	XorDLL(XorNode<T>* h, XorNode<T>* t);//parameterized constructor
	bool isEmpty();
	void insertAtHead(T value);
	void insertAtTail(T value);
	int removeAtHead();
	int removeAtTail();		
	void printList();
	bool search(T key);//Search a node with value “key” from list and return its link.If multiple nodes of same value exist, then return pointer to first node having the key value.
};

//BSEF19M003
//LAIBA KAMAL

