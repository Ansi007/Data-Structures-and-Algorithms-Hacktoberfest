// to compare two lists (return 0, if both lists are same,
// +1 if first list has more elements, -1 if second list has more elements)
// [Elements need not to be same in same order]

#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	static int count;
	Node(int n=0){
		data = n;
		next = NULL;
		count++;
	}
};
int Node::count = 0;

class LinkedList{
	Node *first, *last;
public:
	LinkedList(){
		first = new Node(0);
		last = NULL;
	}
	Node* push_back(Node *node,int n){
		if( node == NULL ){
			last = new Node(n);
			return last;
		}
		else
			node -> next = push_back(node -> next, n);
		return node;
	}
	void push_back(const int n){
		first -> next = push_back(first->next,n);
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
	void print(Node * node){
		if(node == NULL) return;
		cout << node->data << ' ';
		print(node->next);
	}
	void print(){
		print(first->next);
		cout << '\n';
	}
	bool isExist(Node *node, int d){
		if(node == NULL ) return false;
		if( node->data == d) return true;
		return isExist(node->next,d);
	}
	bool isExist(int d){
		return isExist(first->next,d);
	}
	// int compare(Node *node1, const LinkedList &list){
	// 	if( node1 == NULL ) return 0;
	// 	if(!list.isExist(node1->data)) return 0;
	// 	else return compare(node1->next,list);
	// }
	// int compare(const LinkedList &list){
	// 	return compare(first->next,list);
	// }
};
int main(int argc, char const *argv[]){
	LinkedList list,list2;
	for (int i = 0; i < 10; ++i){
		list.addInOrder (i+2);
		list2.addInOrder (i+3);
	}
	list.print();
	list2.print();
	if(list.compare(list2))
		cout << "Not Same\n";
	else
		cout << "Same\n";
	return 0;
}