#include <iostream>
using namespace std;

template <typename T>
class XORLinkList;

template <typename T>
class Node{
	friend class XORLinkList<T>;
private:
	T data;
	Node* npx;
public:
	Node()
	{
		npx = NULL;
	}
	Node<T>* Xor(Node<T>* x, Node<T>* y)
	{
		return reinterpret_cast<Node*>(
			reinterpret_cast<uintptr_t>(x)
			^ reinterpret_cast<uintptr_t>(y));
	}
	Node(T value,Node* prev, Node* next)
	{
		data = value;
		npx = Xor(prev , next);
	}

};

template<typename T>
class XORLinkList
{
private:
	Node<T>* head;
public:
	XORLinkList()
	{
		head = nullptr;
	}
	Node<T>* Xor(Node<T>* x, Node<T>* y)
	{
		return reinterpret_cast<Node<T>*>(
			reinterpret_cast<uintptr_t>(x)
			^ reinterpret_cast<uintptr_t>(y));
	}
	void insertAtHead(T val)
	{
		Node<T>* newNode = new Node<T>(val, NULL, NULL);
		if (head == nullptr)
		{
			head = newNode;
		}
		else if (head!=nullptr)
		{
			//Node<T>* newNode = new Node<T>(val, NULL, head);
			head->npx = Xor(newNode, (Xor(NULL, head->npx)));
			newNode->npx = Xor(NULL , head);
			head = newNode;
		}
	}
	int removeAtHead()
	{
		if (head == nullptr)
		{
			cout << "\nList is Empty\n";
			return 0;
		}
		else if (head != nullptr)
		{
			Node<T>* temp = head;
			head = Xor(head->npx, NULL);
			head->npx = Xor(NULL,Xor(temp, head->npx));
			delete temp;
			temp = nullptr;
			return 1;
		}
	}
	void insertAtTail(T val)
	{
		Node<T>* newNode = new Node<T>(val, NULL, NULL);
		if (head == nullptr)
		{
			head = newNode;
		}
		else if (head != nullptr)
		{
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			Node<T>* next;
			while (curr != NULL)
			{
				next = Xor(prev, curr->npx);
				prev = curr;
				curr = next;
			}
			newNode->npx = Xor(prev, NULL);
			prev->npx = Xor(Xor(prev->npx, NULL), newNode);
		}
	}
	int RemoveAtTail()
	{
		
		if (head == nullptr)
		{
			cout << "\nList is Empty\n";
			return 0;
		}
		else if (head != nullptr)
		{
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			Node<T>* next;
			while (curr!= NULL)
			{
				next = Xor(prev, curr->npx);
				prev = curr;
				curr = next;
			}
			//prev pointer points to last node of LL.
			curr = Xor(prev->npx, NULL);//curr is 2nd last node pointer i m using it beacuse it has null right now
			if(curr)
				curr->npx = Xor(Xor(curr->npx, prev), NULL);
			else
			{
				head = nullptr;
			}
			delete prev;
			prev = nullptr;
			return 1;
		}
	}
	Node<T>* returnNextNodeOfSearched(T val)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		else if (head != nullptr)
		{
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			Node<T>* next;
			while (curr != NULL && curr->data != val)
			{
				next = Xor(prev, curr->npx);
				prev = curr;
				curr = next;
			}
			if (curr == NULL)
			{
				return nullptr;
			}
			else if (curr && curr->data == val)
			{
				curr = Xor(curr->npx, prev);
				return curr;
			}
		}
	}
	Node<T>* search(T val)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		else if (head != nullptr)
		{
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			Node<T>* next;
			while (curr != NULL && curr->data!=val)
			{
				next = Xor(prev, curr->npx);
				prev = curr;
				curr = next;
			}
			if (curr == NULL)
			{
				return nullptr;
			}
			else if(curr && curr->data ==val)
			{
				return curr;
			}
		}
	}

	void insertAfter(T val,T val2)
	{
		if (head == nullptr)
		{
			insertAtTail(val2);
		}
		else
		{
			Node<T>* curr = search(val);
			Node<T>* next = returnNextNodeOfSearched(val);
			if(curr == nullptr)
			{
				insertAtTail(val2);
			}
			else if (curr)
			{
				Node<T>* newNode = new Node<T>(val2, curr, next);
				curr->npx = Xor(Xor(curr->npx, next), newNode);
				next->npx = Xor(Xor(next->npx, curr), newNode);
			}
		}
	}
	Node<T>* returnPrevNodeOfSearched(T val)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		else if (head != nullptr)
		{
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			Node<T>* next;
			while (curr != NULL && curr->data != val)
			{
				next = Xor(prev, curr->npx);
				prev = curr;
				curr = next;
			}
			if (curr == NULL)
			{
				return nullptr;
			}
			else if (curr && curr->data == val)
			{
				return prev;
			}
		}
	}
	void deleteBefore(T val)
	{
		if (head == nullptr)
		{
			cout << "No node is present: \n";
		}
		else
		{
			Node<T>* curr = search(val);
			Node<T>* prev = returnPrevNodeOfSearched(val);
			if (curr == nullptr)
			{
				cout << "node value cant be found:\n ";
			}
			else if (curr && prev)
			{
				curr->npx = Xor(Xor(curr->npx, prev), Xor(prev->npx, curr));
				Xor(prev->npx, curr)->npx = Xor(Xor(Xor(prev->npx, curr)->npx, prev),curr);
				delete prev;
			}
		}

	}

	void insertBefore(T val,T val2)
	{
		if (head == nullptr)
		{
			insertAtTail(val2);
		}
		else
		{
			Node<T>* curr = search(val);
			Node<T>* prev = returnPrevNodeOfSearched(val);
			if (curr == nullptr)
			{
				insertAtTail(val2);
			}
			else if (curr && prev)
			{
				Node<T>* newNode = new Node<T>(val2, curr, prev);
				curr->npx = Xor(Xor(curr->npx, prev), newNode);
				prev->npx = Xor(Xor(prev->npx, curr), newNode);
			}
			else
			{
				Node<T>* newNode = new Node<T>(val2, curr, prev);
				curr->npx = Xor(Xor(curr->npx, prev), newNode);
			}
		}
	}
	
	
	void printList()
	{
		Node<T>* curr = head;
		Node<T>* prev = NULL;
		Node<T>* next;

		cout << "The nodes of Linked List are: \n";

		// Till condition holds true
		while (curr != NULL) {
			// print current node
			cout << curr->data << " ";

			// get address of next node: curr->xnode is
			// next^prev, so curr->xnode^prev will be
			// next^prev^prev which is next
			next = Xor(prev, curr->npx);

			// update prev and curr for next iteration
			prev = curr;
			curr = next;
		}
	}

};

int main()
{
	XORLinkList<int> bca;
	int choice = 0;
	while (choice != -99)
	{
		cout << "Enter 1 to insert at head: \n";
		cout << "Enter 2 to remove at head: \n";
		cout << "Enter 3 to insert at tail: \n";
		cout << "Enter 4 to insert before:\n";
		cout << "Enter 5 to insert after:\n";
		cout << "Enter 6 to print list:\n";
		cout << "Enterr -99 to exit: \n Your choice";
		cin >> choice;

		if (choice == 1)
		{
			int val;
			cout << "Enter value that you want to insert: ";
			cin >> val;
			bca.insertAtHead(val);
		}
		else if (choice == 2)
		{
			bca.removeAtHead();
			cout << "Value removed\n";
		}
		else if (choice == 3)
		{
			int val;
			cout << "Enter value that you want to insert: ";
			cin >> val;
			bca.insertAtTail(val);
		}
		else if (choice == 4)
		{
			int val,search;
			cout << "Enter value that you want to insert: ";
			cin >> val;
			cout << "Enter value that you want to insert before: ";
			cin >> search;
			bca.insertBefore(search,val);
		}
		else if (choice == 5)
		{
			int val, search;
			cout << "Enter value that you want to insert: ";
			cin >> val;
			cout << "Enter value that you want to insert after: ";
			cin >> search;
			bca.insertAfter(search, val);
		}
		else if (choice == 6)
		{
			bca.printList();
			cout << "\n";
		}
		else {
			cout << "\n\nExiting\n\n\n";
		}
	}
	
}