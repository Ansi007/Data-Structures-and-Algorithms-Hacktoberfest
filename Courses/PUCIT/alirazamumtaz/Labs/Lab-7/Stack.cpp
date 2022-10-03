#include <iostream>
using namespace std;

template <class T>
class Stack{ 
	T *x;
	int p, size;
public:
	Stack(int s=10){	size = s; x = new T[size];	p = 0;	}
	bool isFull(){	return p == size;						}
	bool isEmpty(){	return p == 0;						}
	void push(T d){
		if (isFull())	throw (size);
		x[p++]	= d;
	}
	T pop(){
		if (isEmpty())	throw(0);
		return x[--p];
	}
	T seeTop(){
		if (isEmpty())	throw(0);	
		return x[p-1];
	}
	~Stack(){	delete []x;	}
};
/*int main(){
	Stack <int> stack;
	try{
		stack.pop();
	}catch(int i){
		cout << "Stack is empty\n";
	}
	stack.push(23);
	stack.push(33);
	stack.push(43);
	cout << stack.pop() << '\n';
	cout << stack.pop() << '\n';
	stack.push(53);
	cout << stack.pop() << '\n';
	cout << stack.pop() << '\n';
	return 0;
}*/
