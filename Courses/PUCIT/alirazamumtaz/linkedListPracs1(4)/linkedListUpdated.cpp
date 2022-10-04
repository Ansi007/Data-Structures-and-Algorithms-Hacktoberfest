#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next;//TO point to next node, null otherwise
		//Constructor
		Node (int d, Node *n=NULL){
			data = d;
			next = n;
		}
};

class LinkedList{
	Node *first, *last;
public:
	LinkedList(){	first = new Node(0);	last = NULL;	}
	void addNodeAtStart(int d){
		Node *newN = new Node (d);
		newN -> next = first -> next;
		first -> next = newN;
		if (last == NULL)	last = newN; 
	}
	void addNodeAtEnd(int d){
		if (last == NULL)	addNodeAtStart(d);
		else{
			last -> next = new Node (d);
			last = last -> next;
		}
	}
	bool isEqual(LinkedList *list){
		for( Node *t = first->next; t != NULL; t = t->next){
			for(Node* lt = list->first->next; lt != NULL; lt = lt->next)
				if ( t->data != lt->data) return false;
		}
		return true;
	}
	void insert_at(int data, int index){
		for(Node* t = first; t->next != NULL; t = t->next, index-- ){
			if (index == 0){
				Node* newNode = new Node (data);
				newNode -> next = t -> next;
				t-> next = newNode;
				return;
			}
		}
	}
	void modify(int data, int newData){
		for( Node* t = first; t->next != NULL; t = t->next ){
			if(t->data == data){
				t->data = newData;
				return;
			}
		}
	}
	
	void show(){
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(int argc, char const *argv[]){
	LinkedList list;
	list.addNodeAtStart(22);
	list.addNodeAtStart(34);
	list.addNodeAtStart(45);
	list.addNodeAtStart(73);
	list.addNodeAtStart(21);
	list.show();
	list.insert_at(-1,3);
	list.show();
	list.modify(34,77);
	list.show();
	LinkedList list2;
	list2.addNodeAtStart(77);
	list2.addNodeAtStart(22);
	list2.addNodeAtStart(45);
	list2.addNodeAtStart(21);
	list2.addNodeAtStart(73);
	list2.addNodeAtStart(-1);
	list2.show();
	if(list.isEqual(&list2))
		cout << "isEqual \n";
	else
		cout << "Not equal \n";

	return 0;
}