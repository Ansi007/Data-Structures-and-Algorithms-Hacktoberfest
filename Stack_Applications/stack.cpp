#include <iostream>
#include <cstdlib>

using namespace std;

template <class Type1>
class Stack{
	Type1 *stack_array;
	int capacity;
	int Top;
public:
	Stack(int default_size=5)	{	
		stack_array = new Type1[default_size];	
		capacity=default_size;
		Top=0;
	}
	
	bool isFull(){
		if(Top==capacity)	
			return true;
		else 
			return false;
	}
	
	bool isEmpty(){	
		if(Top==0)	
			return true;
		else 
			return false;
	}
	
	void push(int element) {
		if (!isFull())
			stack_array[Top++]	= element;
		else
			cout << "Stack is Full";
	}
	Type1 pop() {
		if (!isEmpty())
			return stack_array[--Top];
		else 
			cout << "Stack is empty";
	}
	Type1 seeTop(){
		if (!isEmpty())
			return stack_array[Top-1];
	}
	
	friend ostream & operator<<(ostream& out, const Stack& x){
		for(int i=0;i<x.Top;i++)
			out << x.stack_array[i] << ' ';
		return out;
	}
	
	~Stack(){		
		delete []stack_array;		
	}
};

int main(){
	Stack<int> s;
	s.push(23);
	s.push(24);
	s.push(25);
	s.push(26);
	s.push(27);
	cout << "Pushed Elements are: \n";
	cout << s;
	if(s.isFull())
		cout << "\nStack is full "<< endl;
	else 
		cout << "Stack is not full: "<< endl;
	s.pop();
	s.pop();
	s.pop(); 
	cout << "\nElements left: \n";
	cout << s;
	cout << "\nTop Element is:\n";
	cout << s.seeTop() <<endl;
	s.pop();
	s.pop(); 
	if(s.isEmpty())
		cout << "Stack is Empty "<< endl;
	else 
	cout << "Stack is not Empty: "<< endl;
	s.pop();
	return 0;
}
