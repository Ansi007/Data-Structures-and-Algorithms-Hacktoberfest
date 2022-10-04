#include <iostream>

using namespace std;

class LinkedList{
	class Node{
	public:
		int data;
		Node *next;
		Node (int d, Node *n = NULL){
			data = d;
			next = n;
		}
	};
	Node *head, *tail;
	void freeList(Node* t){
		if(t != NULL)	freeList(t->next);
		delete t;
	}
public:
	LinkedList(){	head = new Node(0);	tail = NULL;	}
	void addNodeAtStart(int d){
		Node *newN = new Node (d);
		newN -> next = head -> next;
		head -> next = newN;
		if (tail == NULL)	tail = newN; 
	}
	void addNodeAtEnd(int d){
		if (tail == NULL)	addNodeAtStart(d);
		else{
			tail -> next = new Node (d);
			tail = tail -> next;
		}
	}
	void swap(Node *t1, Node *t2){
		int temp = t1->data;
		t1->data = t2->data;
		t2->data = temp;
	}
	void reverseList(){
		Node *p1,*p2,*p3;
		p1 = head, p2 = head->next;
		while(p2 != NULL){
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		tail = head -> next;
		tail->next = NULL;
		head->next = p1;
	}
private:
	void bubbleSort(){
		Node *t1, *t2;
		for (t1=head->next;t1->next!=NULL;t1=t1->next)
			for (t2=head->next;t2->next!=NULL;t2=t2->next)
				if (t2->data > t2->next->data)
					swap(t2, t2->next);
	}
	void selectionSort(){
		Node *t1, *t2, *minNode;
		for (t1=head->next;t1->next!=NULL;t1=t1->next){
			minNode = t1;
			for (t2=t1->next;t2!=NULL;t2=t2->next)
				if (t2->data < minNode->data)
					minNode = t2;
			if (minNode != t1)
					swap(t1, minNode);
		}
	}
public:

	void show(){
		cout << *this << '\n' ;
	}
	void sort(){
		selectionSort();
	}
	friend ostream& operator << (ostream& out, LinkedList& list){
		for ( Node *t = list.head -> next ; t != NULL ; t = t -> next )
			out << t -> data << ' ';
		return out;
	}
	~LinkedList(){
		freeList(head->next);
		head = tail = NULL;
	}
};

int main(){
	LinkedList list;
	list.addNodeAtStart(23);
	list.addNodeAtStart(31);
	list.addNodeAtStart(45);
	list.addNodeAtStart(13);
	list.addNodeAtEnd(73);
	list.addNodeAtEnd(61);
	list.show();
	list.reverseList();
	list.show();
	cout << "LinkedList is deleting\n";
	return 0;
}
