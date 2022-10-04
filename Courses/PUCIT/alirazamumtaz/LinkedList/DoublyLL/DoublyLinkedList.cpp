#include <iostream>

using namespace std;
class DNode{
public:
	int data;
	DNode *prev, *next;
	DNode(int d=0){
		data = d;
		prev = NULL;
		next = NULL;
	}
};
class DLinkedList{
	DNode *head;
public:
	DLinkedList(){
		head = new DNode(0);
		head->next = head;
		head->prev = head;
	}
	void push_front(int d){
		DNode *newNode = new DNode(d);
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}
	void push_back(int d){
		DNode *newNode = new DNode(d);
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}
	DNode * addInOrder(int d, DNode *t){
		if ( t == head || t->data > d){
			DNode *newNode  = new DNode(d);
			newNode -> next = t;
			newNode -> prev = t -> prev;
			t -> prev = newNode;
			return newNode;	
		}
		else
			t -> next = addInOrder(d, t->next);
		return t;
	}
	void addInOrder(int d){
		head -> next = addInOrder(d, head->next);
	}


	void reverseList(){
		DNode *p1,*p2,*p3;
		p1 = head, p2 = head->next;
		while(p2 != NULL){
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		head->prev = head -> next;
		// tail->next = NULL;
		head->next = p1;
	}

	void print(){
		for(DNode *t = head->next; t != head; t = t->next)
			cout << t->data << ' ';
		cout << '\n';
		for(DNode *t = head->prev; t != head; t = t->prev)
			cout << t->data << ' ';
		cout << '\n';
	}
};
int main(int argc, char const *argv[]){
	DLinkedList list;
	for (int i = 2; i < 16; i+=2)
		list.push_back(i+1);
	list.print();
	list.reverseList();
	list.print();
	return 0;
}