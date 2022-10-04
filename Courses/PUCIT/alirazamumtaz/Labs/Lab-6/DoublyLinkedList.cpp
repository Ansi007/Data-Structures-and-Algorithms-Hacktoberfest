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

	void print(){
		cout << "Forward  Direction: ";
		for(DNode *t = head->next; t != head; t = t->next)
			cout << t->data << ' ';
		cout << '\n';
		cout << "Backward Direction: ";
		for(DNode *t = head->prev; t != head; t = t->prev)
			cout << t->data << ' ';
		cout << "\n-------------------------------------\n";
	}
	DNode* find(int d){
		for(DNode* t = head->next; t != head; t = t ->next)
			if(t -> data == d)
				return t;
		return NULL;
	}
// -----------------------------------------------------------
	void swapNodes(int d1, int d2){
		DNode *n1, *n2, *tNext, *tPrev;
		n1 = find(d1);
		n2 = find(d2);
		tNext = n2->next;
		tPrev = n2->prev;
		if(!(n1->next == n2 or n1->prev == n2)){
			n1->next->prev = n2;
			n1->prev->next = n2;
			n2->next->prev = n1;
			n2->prev->next = n1;
		}
		n2->next = n1->next;
		n2->prev = n1->prev;
		n1->next = tNext;
		n1->prev = tPrev;
	}
};
int main(int argc, char const *argv[]){
	DLinkedList list;
	for (int i = 2; i < 16; i++)
		list.push_back(i);
	list.print();
	list.swapNodes(2,15);
	cout << "After Swaping: \n";
	list.print();
	return 0;
}