#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int findlength(char a[]);
void Reverse(char *x);
void swap(char &a, char &b);

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
	
	int precedence(char a){
		if(a=='#')
			return 0;
		else if(a=='+' || a=='-')
			return 1;
		else if(a=='*' || a=='/')  
			return 2;
		else if(a=='^')
			return 3;
	}
	
	char* Prefix_Conversion(char *a){
		Reverse(a);
		char *arr=Postfix_Conversion(a);
		Reverse(arr);
		return arr;
	}
	
	char* Postfix_Conversion(char a[]){
		char *array=new char[findlength(a)+1];
		int i=0,size=0;
		push('#');
		while(a[i]!='\0'){
			if(a[i]>='0' && a[i]<='9')
				array[size++]=a[i];
			
			else if(a[i]=='(')
				push(a[i]);
			
			else if(a[i]==')'){ 
				while(seeTop()!='(')
					array[size++]=pop();
				pop();
			}
			
			if(a[i]=='^' || a[i]=='*' || a[i]=='/' || a[i]=='+' || a[i]=='-'){
				if(precedence(a[i])>seeTop() || seeTop()=='(')
					push(a[i]);
				
				else{
					while(precedence(seeTop())>=precedence(a[i]) && seeTop()!='(')
						array[size++]=pop();

					push(a[i]);
				}
			}
			i++;
		}
		
		while(seeTop()!='#')
			array[size++]=pop();
		
		array[size]='\0';
		return array;
	}
	
	int evaluation(char *a){
		int i=0,operand1,operand2,result;
		while(a[i]!='\0'){
			if(a[i]>='0' && a[i]<='9')
				push(a[i]-48);
			
			else if(a[i]=='^' || a[i]=='*' || a[i]=='/' || a[i]=='+' || a[i]=='-'){
				operand1=pop();
				operand2=pop();
				if(a[i]=='^')
					result=pow(operand1,operand2);
				else if(a[i]=='*')
					result=operand1*operand2;
				else if(a[i]=='/')
					result=operand1/operand2;
				else if(a[i]=='+')
					result=operand1+operand2;
				else if(a[i]=='-')
					result=operand1-operand2;
				push(result);
			}
			i++;
		}
		pop();
		return result;
	}
	
	~Stack(){		
		delete []stack_array;		
	}
};

int main(){
	Stack<char> s;
	char Expression[]={"3^(2+1)*5"};
	cout << "Expression: " << Expression << endl;
	char *arr=s.Postfix_Conversion(Expression);
	cout << "PostFix Conversion: " << arr << endl;
	cout << "Result: " << s.evaluation(arr) << endl;
	char *pre=s.Prefix_Conversion(Expression);
	cout << "PreFix Conversion: " << pre;
	delete []arr;
	delete []pre;
	return 0;
}

int findlength(char a[]){
	int i=0;
	while(a[i]!='\0')
		i++;
	return i;
}

void swap(char &a, char &b){
	char temp=a;
	a=b;
	b=temp;
}

void Reverse(char *x){ 
	int k=findlength(x)-1;
	for(int i=0;i<(findlength(x))/2;i++){
		if(x[i]=='(')
			x[i]=')';
		else if(x[i]==')')
			x[i]='(';
		if(x[k]=='(')
			x[k]=')';
		else if(x[k]==')')
			x[k]='(';
		swap(x[i],x[k--]); //swaping first and last second last and second and so on
	}
}

