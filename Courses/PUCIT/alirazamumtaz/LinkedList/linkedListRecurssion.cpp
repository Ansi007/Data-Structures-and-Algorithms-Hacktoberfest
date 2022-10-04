#include <iostream>

using namespace std;

class Node{
	public:
		Node *next;
		int data;
		Node (int d){
			data = d;
			next = NULL;
		}
};
class LinkedList{
	Node *first, *last;
public:
	LinkedList(){
		first = new Node(0);
		last = NULL;
	}
	Node* addInOrder(int d, Node *t){
		if ( t == NULL || t->data > d){
			if (t == NULL){
				last = new Node(d);
				return last;
			}
			Node *newNode  = new Node(d);
			newNode -> next = t;
			return newNode;
		}
		else
			t -> next = addInOrder(d, t->next);
		return t;
	}
	void addInOrder(int d){
		first -> next = addInOrder(d, first->next);
	}
	Node* deleteNode(int d, Node* t){
		if (t == NULL)   	return NULL;
		if (t -> data == d){
			Node *toDelete = t -> next;
			delete t;
			return toDelete;
		}
		else{
			t -> next = deleteNode( d, t -> next);
			if (t -> next == NULL)	last = t;
		}
		return t;
	}
	void deleteNode(int d){
		if (first -> next == NULL)	return;
		first -> next = deleteNode(d, first -> next) ;
	}
	void printRecReverse(Node *t){
		if (t ==  NULL)		return;
			printRecReverse( t -> next);
		cout << t -> data << ' ';
	}
	void printRecReverse(){
		printRecReverse(first->next);
		cout << '\n' ;
	}
	void printRec(Node *t){
		if (t ==  NULL)		return;
		cout << t -> data << ' ';
		printRec( t -> next);
	}	
	//wrapper function
	void printRec(){
		printRec(first->next);
		cout << '\n' ;
	}
};
int main(){
	LinkedList list;
	list.addInOrder(23);
	list.addInOrder(12);
	list.addInOrder(34);
	list.addInOrder(22);
	list.addInOrder(42);
	list.addInOrder(28);
	list.printRec();
	list.printRecReverse();	
	list.deleteNode(28);
	list.printRec();
	list.deleteNode(23);
	list.printRec();
	list.deleteNode(12);
	list.printRec();
	list.deleteNode(42);
	list.printRec();
	list.deleteNode(28);
	list.printRec();
	list.deleteNode(22);
	list.printRec();
	list.deleteNode(34);
	list.printRec();
	list.addInOrder(23);
	list.addInOrder(12);
	list.addInOrder(34);
	list.addInOrder(22);
	list.addInOrder(42);
	list.addInOrder(28);
	list.printRec();
	
	return 0;
}