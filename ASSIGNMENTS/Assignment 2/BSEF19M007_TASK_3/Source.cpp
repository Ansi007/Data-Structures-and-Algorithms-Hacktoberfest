#pragma once
#include <iostream>
using namespace std;

template<class T>
class XList;

/*
XNode class containing information and pointer to the next node.
*/

template<class T>
class XNode
{
public:
	friend XList<T>;
	T info;
	XNode<T>* npx;

	XNode(T inInfo, XNode* nPtr = NULL)
	{
		info = inInfo;
		npx = nPtr;
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
class XList
{
private:
	XNode <T>* head;
	XNode <T>* tail;
public:
	XList();
	XList(const XList&);
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	T deleteAtHead();
	T deleteAtTail();
	void printList();
	bool search(T);
	XNode<T>* XOR(XNode<T>*, XNode<T>* );
	~XList();

};

template<class T>
XList<T>::XList() : head(NULL), tail(NULL)	//Empty --- NULL
{
}

template<class T>
XList<T>::XList(const XList& L)
{
	XNode<T>* curr = L.head;	//Current 
	XNode<T>* prev = NULL;		//Previous to the current
	XNode<T>* temp = NULL;		//To hold a pointer for sometime to use it again.

	while (curr)
	{
		insertAtTail(curr->info);
		temp = curr;	//holding current
		curr = XOR(prev, curr->npx);	//moving current to the curr->next
		prev = temp;	//putting old current in previous
	}
}

template<class T>
bool XList<T>::isEmpty()
{
	return(head == NULL);
}

template<class T>
void XList<T>::insertAtHead(T x)
{

	XNode<T>* newNode = new XNode<T>(x);
	if (isEmpty()) {
		newNode->npx = NULL;	//if its empty
		head = newNode;	tail = newNode;
	}

	else {
		newNode->npx = XOR(NULL, head);	//Adjusting npx of newNode, and old head.
		head->npx = XOR(newNode, head->npx);
		head = newNode;
	}
}

template<class T>
void XList<T>::insertAtTail(T x)
{
	XNode<T>* newNode = new XNode<T>(x);
	if (isEmpty()) {
		newNode->npx = NULL;	//if empty
		head = newNode;	tail = newNode;
	}

	else {
		newNode->npx = XOR(tail,NULL);	//adjustiing npx of newNode, and tail
		tail->npx = XOR(newNode, tail->npx);
		tail = newNode;
	}
}

template<class T>
T XList<T>::deleteAtHead()
{
		/*
		This function delets a node from the start of the list.
		*/

	if (!isEmpty())
	{
		int value = head->info;
		XNode<T>* temp = head;	//Points to head
		XNode<T>* next = head;	//Will point to head->next
		head = XOR(NULL,head->npx);
		next = XOR(next, head->npx);
		delete temp;
		head->npx = XOR(NULL, next);
			
		if (isEmpty())	//if list is empty after deletion
			tail = NULL;
		return value;
	}

	else
		return -1;	//if empty cant delete

}

template<class T>
T XList<T>::deleteAtTail()
{
		/*
		This function deletes a node from the end of the list.
		*/

	if (!isEmpty()) {
		int found = tail->info;
		XNode<T>* temp = tail;	//To be pointed at tail
		XNode<T>* temp1 = XOR(NULL,tail->npx);	//To be pointed 1 step behind the tail
		XNode <T>* prev = XOR(temp1->npx,tail);
		tail = temp1;

		if (tail) {
			tail->npx = XOR(prev, NULL);
		
		}
		delete temp;

		if (tail == NULL)
			head = NULL;

		return found;
	}

	else
		return -1;
}


template<class T>
void XList<T>::printList()
{
	XNode<T>* curr = head;	//points to the current
	XNode<T>* prev = NULL;	//points 1 behind current
	XNode<T>* temp = NULL;	//holds a pointer

	while (curr) {
		cout << curr->info << " --> ";
		temp = curr;
		curr = XOR(prev, curr->npx);
		prev = temp;
	}
	cout << "NULL" << endl;
}

template<class T>
bool XList<T>::search(T key)
{
	/*
	This function returns the founded value's node.
	*/

	XNode<T>* curr = head;
	XNode<T>* prev = NULL;
	XNode<T>* temp = NULL;

	while (curr)
	{
		if (curr->info == key)
			return true;

		else {
			temp = curr;
			curr = XOR(prev, curr->npx);
			prev = temp;
		}
	}

	return false;

}

template<class T>
XList<T>::~XList()
{
	//deletes the list.
	XNode<T>* curr = head;
	XNode<T>* prev = NULL;
	XNode<T>* temp = NULL;

	while (curr)
	{
		temp = curr;
		curr = XOR(prev, curr->npx);
		prev = temp;
		delete head;
		head = curr;
	}

}

template<class T>
XNode<T>* XList<T>::XOR(XNode<T>* A, XNode<T>* B)
{
	return reinterpret_cast<XNode<T>*>(reinterpret_cast<uintptr_t>(A) ^ reinterpret_cast<uintptr_t>(B));
	// Simple XORing was giving an error, so I searched about how to XOR two Nodes, and this is what I found from the net.
}

int main() {


	XList<int> list;
	int inputVal;

	for (int i = 0; i < 5; i++)
	{
		cout << "=> Enter a value to insert at head: ";	cin >> inputVal;
		list.insertAtHead(inputVal);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "=> Enter a value to insert at tail: ";	cin >> inputVal;
		list.insertAtTail(inputVal);
	}

	cout << "=> List: ";
	list.printList();

	cout << "\n=> Deleting Head of the list: " << endl;
	list.deleteAtHead();
	cout << "=> List: ";
	list.printList();

	cout << "\n=> Deleting Tail of the list: " << endl;
	list.deleteAtTail();
	cout << "=> List: ";
	list.printList();

	int key;
	cout << "\n=> Give info to find in the linked list: "; cin >> key;
	if (list.search(key))
		cout << "=> Info found. " << endl;
	else cout << "=> Info not found. " << endl;

	return 0;
}