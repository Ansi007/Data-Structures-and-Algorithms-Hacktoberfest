
//BSEF19M003
// //LAIBA KAMAL
//TO TEST LINEAR DOUBLY LINKED LIST

#include "XorDLL.cpp"
int main()
{
	int inputVal = 0, choice = 0;
	bool b = true;
	char c = 'y';
	XorNode<int>* n;
	XorDLL<int> list;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at head: ";
		cin >> inputVal;
		list.insertAtHead(inputVal);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);
	}
	list.printList();

	while (c == 'y')
	{
		cout << "\nMENU\n";
		cout << "Enter 1 to insertAtHead.\n";
		cout << "Enter 2 to insertAtTail.\n";
		cout << "Enter 3 to removeAtHead.\n";
		cout << "Enter 4 to removeAtTail.\n";
		cout << "Enter 5 to search data from linked list.\n";
		cout << "Enter 6 to print the list.\n";
		cin >> choice;
		switch (choice)
		{
		case 1://insertAtHead
		{
			cout << "Enter the data you wanna insert at head: ";
			cin >> inputVal;
			list.insertAtHead(inputVal);
			break;
		}
		case 2://insertAtTail
		{
			cout << "Enter the data you wanna insert at tail: ";
			cin >> inputVal;
			list.insertAtTail(inputVal);
			break;
		}
		case 3://deleteAtHead
		{
			b = list.removeAtHead();
			if (b == true)
				cout << "Value deleted successfully,\n";
			else if (b == false)
				cout << "Value couldn't be deleted.\n";
			break;
		}
		case 4://deleteAtTail
		{
			b = list.removeAtTail();
			if (b == true)
				cout << "Value deleted successfully,\n";
			else if (b == false)
				cout << "Value couldn't be deleted.\n";
			break;
		}
		case 5://search
		{
			cout << "Enter the data value you wanna search in the list: ";
			cin >> inputVal;
			b = list.search(inputVal);
			break;
		}
		case 6://print list
		{
			break;
		}
		}

		cout << "\nThe list is:\n";
		list.printList();

		cout << "\nEnter y if you wanna run again and n to exit: ";
		cin >> c;
	}

		return 0;
	}
	//BSEF19M003
	//LAIBA KAMAL