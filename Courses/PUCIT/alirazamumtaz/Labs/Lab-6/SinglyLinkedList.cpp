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
// -----------------------------------------------------------------
	bool printKthPositiveNode(int k, Node *t){
		if(t->next == NULL)	return false;
		if(k == 1){
			cout << t->data << '\n';
			return true;
		}
		if(t->data > 0)	return printKthPositiveNode(k-1,t->next);
		else			return printKthPositiveNode(k,t->next);
	}
	bool printKthPositiveNode(int k){
		return printKthPositiveNode(k,first->next);
	}
// ------------------------------------------------------------------
	bool isSumEqual(int n, Node *t, int sum) {
		if ( sum == n)	return true;
		if (t == NULL)  return false;
		bool ans = isSumEqual(n, t->next, sum);
		ans += isSumEqual(n, t->next, sum + t->data);
		return ans;
	}
	bool isSumEqual(int n) {
		bool ans = isSumEqual(n, first->next, 0);
		return ans;
	}
// ----------------------------------------------------------------

};
int main(int argc, char const *argv[]){
	LinkedList list,list2;
	list.addNodeAtEnd(23);
	list.addNodeAtEnd(-59);
	list.addNodeAtEnd(-37);
	list.addNodeAtEnd(46);
	list.addNodeAtEnd(64);
	list.addNodeAtEnd(-38);
	list.print();
	if(list.isSumEqual(22+46))
		cout << "FOUND" << '\n';
	else
		cout << "Not FOUND" << '\n';

	return 0;
}