#include <iostream>
#include <stack>
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
	LinkedList(){
		first = new Node(0);
		last = NULL;
	}
	void addNodeAtStart(int d){
		Node *newN = new Node (d);
		newN -> next = first -> next;
		first -> next = newN;
		if (last == NULL)	last = newN; 
		first -> data += 1;
	}
	void addNodeAtEnd(int d){
		if (last == NULL)	addNodeAtStart(d);
		else{
			last -> next = new Node (d);
			last = last -> next;
		}
		first -> data += 1;
	}
	void deleteNodeFromStart(){
		if (first->next!=NULL){
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
		first -> data -= 1;
	}
	void deleteNodeFromEnd(){
		if (last!=NULL){
			if (first -> next == last)		deleteNodeFromStart();						
			else{
				Node *t = first;
				for ( ; t->next != last; t = t -> next );//Move to second last node
				delete t->next;
				t->next = NULL;
				last = t;
			}
		}
		first -> data -= 1;
	}
	void splitData(){
		for ( Node* t = first->next; t->next != NULL; t  = t->next ){
			if(t->data > 50){
				int temp = t->data / 2;
				Node *sp1, *sp2;
				if(temp > t->data-temp){
					sp1 = new Node(temp);
					sp2 = new Node(t->data - temp);
				}
				else{
					sp1 = new Node(t->data - temp);
					sp2 = new Node(temp);
				}
				Node *tempNode = t -> next;
				t -> next = sp1;
				sp1 -> next = sp2;
				sp2 -> next = tempNode;
				t -> data = sp1 -> data;
				Node * del_node = t->next;
				t->next = del_node->next;
				delete del_node;
				first -> data += 1;
			}
		}
	}
	bool isPalindrome(){
        stack <int> values;
        for(Node* t= first->next; t != NULL; t = t->next)
                values.push(t->data); 	
        for(Node *itr = first->next;  itr != NULL;itr = itr->next){
             int i = values.top();
             values.pop();
            if(itr -> data != i)	return false;
        }
		return true;
	}
	void removedata(int data){ 
        Node* current = first; 
        Node* prev = NULL; 
        while (current != NULL) { 
            if (current -> data == data) { 
                if (prev == NULL) { 
                    first = current -> next; 
                } else { 
                    prev -> next = current -> next; 
                } 
                first -> data -= 1; 
                return; 
            } 
            prev = current; 
            current = current->next; 
        }
    }
	void removeNegatives(){
	    for ( Node *t = first -> next ; t != NULL ; t = t -> next )
	    	if(t->data < 0) removedata(t->data);
	}
	void printPairs(){
		int count = 0;
		for ( Node *t = first -> next ; t != NULL ; t = t -> next ){
			cout << t -> data << ' '; count++;
			if(count == 2)	{ cout << '\n' ; count = 0; }
		}
	}

	void insertArray(const int *arr, const int size){	
		for (int i = 0; i < size; ++i){
			Node *t;
			for ( t = first -> next ; t != NULL ; t = t -> next )
				if(arr[i] == t->data) break;
			if(t == NULL) addNodeAtEnd(arr[i]);
		}
	}
	void show(){
		cout << "Count: " << first -> data << '\n'; 
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
	// LinkedList list;
	// list.addNodeAtStart(23);
	// list.addNodeAtEnd(59);
	// list.addNodeAtEnd(37);
	// list.addNodeAtEnd(46);
	// list.addNodeAtEnd(64);
	// list.addNodeAtEnd(29);
	// list.show();
	// // list.printPairs();
	// // int arr[5] = {22,23,43,54,64};
	// // list.insertArray(arr,5);
	// // list.show();
	// list.splitData();
	// list.show();
	// list.addNodeAtEnd(73);
	// list.addNodeAtEnd(61);
	// list.show();
	// list.deleteNodeFromStart();
	// list.show();
	// list.deleteNodeFromEnd();
	// list.show();
	LinkedList checkPalin;
	checkPalin.addNodeAtStart(-22);
	checkPalin.addNodeAtEnd(42);
	checkPalin.addNodeAtEnd(34);
	checkPalin.addNodeAtEnd(42);
	checkPalin.addNodeAtEnd(-22);
	checkPalin.show();
	// if(checkPalin.isPalindrome())
	// 	cout << "Palindrome\n";
	// else
	// 	cout << "Not Palindrome\n";
	checkPalin.removeNegatives();
	// checkPalin.printPairs();
	checkPalin.show();

	return 0;
}
