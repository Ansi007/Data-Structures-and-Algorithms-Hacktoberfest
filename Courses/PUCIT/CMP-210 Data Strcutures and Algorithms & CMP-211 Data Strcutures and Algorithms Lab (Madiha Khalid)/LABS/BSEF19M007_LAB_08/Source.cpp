#include <iostream>
#include "DList.h"
#include "DList.cpp"

using namespace std;

int main()
{
	
	DList<int> list;
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

	cout << "\n=> The length of Linked List after insertion is: " << list.getLength() << endl;
	cout << "=> List: ";
	list.printList();

	int key;

	cout << "=> Enter the value you want to find in the list: ";	cin >> key;
	cout << "=> Enter the value you want to insert after found value: ";	cin >> inputVal;
	list.insertAfter(inputVal, key);
	cout << "=> List: ";
	list.printList();


	cout << "\n=> Enter the value you want to find in the list: ";	cin >> key;
	cout << "=> Enter the value you want to insert before found value: ";	cin >> inputVal;
	list.insertBefore(inputVal, key);
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


	cout << "\n=> Enter the value you want to delete before in the list: ";	cin >> key;
	list.deleteBefore(key);
	cout << "=> List: ";
	list.printList();

	cout << "\n=> Enter the value you want to delete after in the list: ";	cin >> key;
	list.deleteAfter(key);
	cout << "=> List: ";
	list.printList();

	cout << "\n=> Enter a value to insert at head: ";	cin >> inputVal;
	DNode<int> *Head = new DNode<int>(inputVal);
	list.setHead(Head);
	cout << "=> List: ";
	list.printList();

	cout << "\n=> Enter a value to insert at tail: ";	cin >> inputVal;
	DNode<int>* Tail = new DNode<int>(inputVal);
	list.setTail(Tail);
	cout << "=> List: ";
	list.printList();

	return 0;
}
