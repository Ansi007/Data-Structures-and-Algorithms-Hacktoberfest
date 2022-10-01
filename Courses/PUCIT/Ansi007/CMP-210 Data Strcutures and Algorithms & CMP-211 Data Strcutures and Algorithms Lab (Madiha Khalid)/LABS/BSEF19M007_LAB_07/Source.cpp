#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList<int> list;
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

	return 0;
}
