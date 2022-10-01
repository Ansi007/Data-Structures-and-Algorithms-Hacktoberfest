#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() :head(NULL), tail(NULL)	//Empty --- NULL
{
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& L)
{
	Node<T>* temp = L.head;
	while (temp)
	{
		insertAtTail(temp->info);
		temp = temp->next;
	}
}

template<class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}

template<class T>
void LinkedList<T>::insertAtHead(T value)
{
	/*
	This function inserts a node in the start of the list.
	*/

	Node<T>* newNode = new Node<T>(value);

	if (isEmpty())	//NewNode is head & tail
	{
		this->head = this->tail = newNode;
	}
	else
	{
		newNode->next = this->head;
		this->head = newNode;
	}
}

template<class T>
void LinkedList<T>::insertAtTail(T value)
{	
	/*
	This function inserts a node at the end of the list.
	*/

	Node<T>* temp = new Node<T>(value);

	if (isEmpty())	//New node is head & tail
	{
		head = tail = temp;
	}

	else
	{
		tail->next = temp;
		tail = temp;
	}
}

template<class T>
bool LinkedList<T>::deleteAtHead()
{

	/*
	This function delets a node from the start of the list.
	*/


	if (!isEmpty())	
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		if (isEmpty())
			tail = NULL;
		return true;
	}

	else
		return false;
}

template<class T>
bool LinkedList<T>::deleteAtTail()
{
	/*
	This function deletes a node from the end of the list.
	*/

	if (!isEmpty()) {
		Node<T>* temp = head;	//To be pointed at tail
		Node<T>* temp1 = NULL;	//To be pointed 1 step behind the tail

		while (temp != tail)
		{
			temp1 = temp;
			temp = temp->next;
		}

		tail = temp1;
		if (tail) 
			tail->next = NULL;
		
		delete temp;

		if (tail == NULL)
			head = NULL;

		return true;
	}

	else
		return false;
}

template<class T>
void LinkedList<T>::printList()
{
	/*
	This function prints the list.
	*/

	Node<T>* temp = head;
	while (temp)
	{
		cout << temp->info << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

template<class T>
Node<T>* LinkedList<T>::getNode(unsigned int n)
{
	/*
	This function returns the nth index's node. Where n can be 0 to N. 0 is the first node and so on.
	*/

	if (!isEmpty()) {
		int size = getLength();
		if (n >= size)
			return tail;

		Node<T>* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		return temp;
	}

	else
		return nullptr;
}

template<class T>
bool LinkedList<T>::insertAfter(T value, T key)
{
	/*
	This function inserts a node after the founded value.
	*/

	Node<T>* found = search(key);	//founded node
	if (found)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = found->next;
		found->next = newNode;
		if (found == tail)
			tail = newNode;
		return true;
	}

	else
		return false;
}

template<class T>
bool LinkedList<T>::insertBefore(T value, T key)
{
	/*
	This function inserts a node before the founded value.
	*/

	Node<T>* found = head;	//founded node
	Node<T>* temp = NULL;	//one behind that

	while (found)
	{
		if (found->info == key) {
			break;
		}
		else {
			temp = found;
			found = found->next;
		}
	}

	if (found)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = found;
		if (found == head)
			head = newNode;
		else 
			temp->next = newNode;

		return true;
	}

	else
		return false;
}

template<class T>
bool LinkedList<T>::deleteBefore(T key)
{
	/*
	This function deletes a node before the founded value.
	*/

	Node<T>* temp = head;	//1 behind finded node/node to be deleted
	Node<T>* temp1 = NULL; //2 behind finded node
	bool found = false;

	while (temp->next)
	{
		if (temp->next->info == key) {
			found = true;
			break;
		}

		else {
			temp1 = temp;
			temp = temp->next;
		}
	}

	if (found) {		
			if (temp == head) {
				deleteAtHead();
				return true;
			}

			else if (temp) {
				temp1->next = temp->next;
				delete temp;
				return true;
			}	

			return false;
	}

	else 
		return false;
}

template<class T>
bool LinkedList<T>::deleteAfter(T key)
{
	/*
	This function deletes a node after the founded value.
	*/

	Node<T>* found = search(key);
	if (found)
	{
		if (found == tail)
			return false;
		
		Node<T>* temp = found->next;
		found->next = temp->next;
		if (temp == tail)
			tail = found;

		delete temp;
		return true;
	}

	else
		return false;
}

template<class T>
Node<T>* LinkedList<T>::search(T key)
{
	/*
	This function returns the founded value's node.
	*/

	Node<T>* temp = head;
	while (temp)
	{
		if (temp->info == key)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

template<class T>
int LinkedList<T>::getLength()
{
	/*
	This function returns the length of list.
	*/

	int count = 0;
	if (!isEmpty()) {
		Node<T>* temp = head;
		while (temp != tail) {
			temp = temp->next;
			count++;
		}
		return ++count;
	}

	else
		return count;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	//deletes the list.
	Node<T> *temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}


