#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;

int integer_length(int number){
	int count=0;
	while(number!=0){ 
		number=number/10;
		count++;
	}
	return count;
}

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
	

int reverse_integer(int number,int length_to_be_reversed){
		int length=integer_length(number);
		int left_one=length%length_to_be_reversed; //we will ignore the amount of left and reverse remaining
		int i=0,j=0,reversed_number=0,multiplying_factor=left_one;
		while(number!=0){
			if(i>0){
				if(j<length_to_be_reversed){ //just pushing 3 numbers 
					push(number%10);
					number=number/10;
					j++;
				}
				
				if(j==length_to_be_reversed) //1st 3 pattern is complete go for next three
					j=0;
			
				for(int k=0;j==0 && k<length_to_be_reversed;k++,multiplying_factor++)
					reversed_number=pow(10,multiplying_factor)*pop()+reversed_number;//multiplying_factor telling how many 10s should be multiplied
			}
			
			else{
				int divide=pow(10,multiplying_factor);
				reversed_number=number%divide; //storing the number that arent to be reversed
				number=number/divide;
				i++;
			}
		}
		return reversed_number;
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
	int number= s.reverse_integer(12345678,3);
	cout << "Reversed number is: " << number << endl;
	return 0;
}
