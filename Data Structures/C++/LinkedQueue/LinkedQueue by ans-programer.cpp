#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node()
	{
		info = 0;
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
	
	
};

template <typename T>
class LinkedQueue
{
private:
	Node<T>* head;
	Node<T>* tail;//this pointer always points to last element entered in queue.
	int noOfElements;
public:
	LinkedQueue()
	{
		
		head = nullptr;
		tail = nullptr;
		noOfElements = 0;
	}
	~LinkedQueue()
	{
		if (head == nullptr)
			return;
		while (head != nullptr)
		{
			
			Node<T>* temp = head->next;
			delete head;
			head = temp;
		}
		tail = nullptr;
		noOfElements = 0;
	}
	LinkedQueue(const LinkedQueue<T>& orig)
	{
		if (this->head != nullptr)
		{
			this->~LinkedQueue();
		}
		if (orig.head == nullptr)
		{
			return;
		}
		Node<T>* traversingOrignal = orig.head;
		
		while (traversingOrignal != nullptr)
		{
			Node<T>* forStoringValues = new Node<T>;
			forStoringValues->info = traversingOrignal->info;
			forStoringValues->next=nullptr;
			noOfElements++;
			if (noOfElements == 1)
			{

			}
			else
			{
				tail->next = forStoringValues;
			}
			
			tail = forStoringValues;
			
			if (noOfElements == 1)
			{
				head = forStoringValues;
			}
			traversingOrignal = traversingOrignal->next;
		}
	}
	LinkedQueue<T>& operator=(const LinkedQueue<T>& rhs)//same logic as implemented in copy constructor.
	{
		if (this->head != nullptr)
		{
			this->~LinkedQueue();
		}
		if (rhs.head == nullptr)
		{
			return *this;
		}
		Node<T>* traversingOrignal = rhs.head;

		while (traversingOrignal != nullptr)
		{
			Node<T>* forStoringValues = new Node<T>;
			forStoringValues->info = traversingOrignal->info;
			forStoringValues->next = nullptr;
			noOfElements++;
			if (noOfElements == 1)
			{

			}
			else
			{
				this->tail->next = forStoringValues;
			}

			this->tail = forStoringValues;

			if (noOfElements == 1)
			{
				this->head = forStoringValues;
			}
			traversingOrignal = traversingOrignal->next;
		}

		return *this;
	
	}
	void enQueue(T val)
	{
		if (head == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->info = val;
			temp->next = nullptr;
			head = tail = temp;
			noOfElements++;
		}
		else
		{
			Node<T>* temp = new Node<T>;
			temp->info = val;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
			noOfElements++;
		}
	}
	T deQueue()
	{
		noOfElements--;
		Node<T>* temp = head;
		head = head->next;
		return temp->info;
	}
	T getElementAtFront()const //first number entered in queue is at front,in my logic head in back and tail is front.
	{
		return tail->info;
	}
	bool isEmpty()const
	{
		if (noOfElements == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int getNoOfElements()
	{
		return noOfElements;
	}
};
int main()
{
	LinkedQueue<int> list;
	list.enQueue(10);
	list.enQueue(100);
	list.enQueue(1000);

	LinkedQueue<int> list2;
	list2 = list;
	cout<<"number of elements is: "<<list2.getNoOfElements();
	cout << endl;
	cout << list2.getElementAtFront();
}