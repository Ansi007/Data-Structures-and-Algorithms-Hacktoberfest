#include<iostream>
using namespace std;
#include"Queue.h"
#include"Queue.cpp"
int main()
{
	cout << "PUSHING 1,2,3,4,5 IN STACK"<<endl;
	Stack<double> S;
	S.push(1);
	S.push(2);
	S.push(3);			//PUSHING 1 2 3 4 5 IN STACK
	S.push(4);
	S.push(5);
	cout << "POPING FROM STACK:"<<endl;
	while (!S.isempty())
	{
		cout << S.pop()<<endl;			//COUT VALUES OF STACK AFTER POPING
	}
}