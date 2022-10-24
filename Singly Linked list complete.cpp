#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int d) {   //constructor
		data = d;
		next = nullptr;
	}

	friend class Linkedlist;
};

	class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = nullptr;
		}
		// is empty func
		bool isEmpty()         
		{
			if (head == NULL)
				return true;
			return false;
		}

		//insert at last function  

		void insertAtLast(int d) {         // insert func by the logic of adding node at end
											//create new node
			Node* ptr = new Node(d);

			if (head == nullptr) {        // if no node is present first.
				head = ptr;
			}

			else
			{
				Node* temp = head;          // taking a temp pointer of node type
				while (temp->next != nullptr)   // will find the last node
					temp = temp->next;
				temp->next = ptr;          //we have find the last node
			}
		}

		// display func of linked list
		void displayList()
		{
			if (head == NULL)
				cout << "List is Empty " << endl;
			else
			{
				Node* cur = head;
				while (cur != NULL)
				{
					cout << cur->data << " " ;
					cur = cur->next;
				}
				
			}
		}
		//insert at Start
		void insertAtStart(int d)
		{
			Node* ptr = new Node(d);
			if (head == NULL)
			{
				cout << "list is empty" << endl;
				 head = ptr;   //inserting the first node
			}

			else
			{
				Node* temp = head;
				head = ptr;
				ptr->next = temp;

			}

		}
		//insert at Position
		void insertAtPos(int pos, int value)
			{
			Node* ptr = new Node(value);
			Node* temp = head;
			int count = 1;
			if (pos == 1)
			{
				insertAtStart(value);
			}
			while (temp->next != NULL && count != pos-1)
			{
				temp = temp->next;
				count++;      //agr pos na mily

			}
			if (temp->next == NULL)
			{
				insertAtLast(value);

			}
			else {
				ptr->next = temp->next;
				temp->next = ptr;
			}

			}
		
		// Traversing or Searching or replace
		Node* search(int key)
		{
			if (head == NULL)
				cout << "List is Empty " << endl;
			else
			{
				Node* cur = head;
				while (cur != NULL)
				{
					if (cur->data == key)
						return cur;
					cur = cur->next;
				}
			}

			return NULL;

		}

		//Delete At Start
		void deleteAtStart()
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		//Delete at Last
		void deleteAtLast()
		{
			Node* temp = head;
			Node* pre = head;
			while (temp->next != NULL)
			{
				pre = temp;
				temp = temp->next;
			}
			pre->next = NULL;
			delete temp;
		}

		//Delete at Position
		void deleteAtPos(int pos)
		{
			Node* temp = head;
			Node* pre = head;
			int count = 1;
			while (temp->next != NULL && count != pos)
			{
				pre = temp;
				temp = temp->next;
				count++;

			}

			if (count == pos)
			{
				pre->next = temp->next;
				delete temp;
			}
			else if(pos == 1)
			{
				deleteAtStart();
			}
			else //when pos is invalid or temp->next==NULL (last node)
			{
				deleteAtLast();
			}

		}
		
			//Destructor of Linked List
		~LinkedList()
		{
			Node* temp = head;

			while (head != NULL)
			{
				temp = head->next;
				delete head;
				head = temp;
				
			}
		}


	};
	int main() {
		LinkedList obj;
		obj.insertAtLast(10);
		obj.insertAtLast(20);
		obj.insertAtLast(30);
		obj.insertAtLast(40);
		obj.insertAtLast(50);
		//obj.displayList();

		obj.insertAtPos(3, 100);
		obj.displayList();
		cout << endl;
		obj.insertAtPos(1, 25);
		obj.displayList();
		cout << "\n------------" << endl;
		obj.deleteAtStart();
		obj.displayList();
		cout << "\n---------\n" << endl;
		obj.deleteAtLast();
		obj.displayList();
		cout << "\n===========================\n";
		obj.deleteAtPos(3);
		obj.displayList();

		//obj.delete(30);
		return 0;
	}
