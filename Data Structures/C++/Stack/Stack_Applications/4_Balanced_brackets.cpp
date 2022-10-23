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
	}
	Type1 pop() {
		if (!isEmpty())
			return stack_array[--Top];
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
	
	bool check_brackets(char a[]){
		int j=0;
		while(a[j]!='\0'){
			if(a[j]=='{' || a[j]=='(' || a[j]=='['){
				push(a[j]);
			}
			
			else if(a[j]=='}' || a[j]==')' || a[j]==']'){
				if(a[j]==')'){
					if(pop()!='(')
						return false;
				}
				
				else if(a[j]=='}'){
					if(pop()!='{')
						return false;
				}
				
				else if(a[j]==']'){
					if(pop()!='[')
						return false;
				}
			}
			j++;
		}
		return true;
	}
	
	~Stack(){		
		delete []stack_array;		
	}
};

int main(){
	Stack<char> s;
	if(s.check_brackets("[()]{}{[()()]()}"))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" <<  endl;
	return 0;
}
