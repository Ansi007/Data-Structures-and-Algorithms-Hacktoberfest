#include<iostream>
#include "./Stack.cpp"

using namespace std;

int main()
{
	int number, temp;
	bool isPallidrome = true;
	Stack<int> stack(10);

	cout << "Enter any number: ";
	cin >> number;

	temp = number;
	while(temp != 0)
	{
		stack.push(temp % 10);
		temp = temp / 10;
	}
	
	temp = number;
	while( temp != 0 )
		if( temp % 10 != stack.pop() )
		{
			isPallidrome = false;
			break;
		}
		else 
			temp = temp / 10;

	if( isPallidrome )
		cout << number << " is a Pallindrome\n";
	else	
		cout << number << " is not a Pallindrome\n";

	return 0;
}