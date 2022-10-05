
//BSEF19M003
//LAIBA KAMAL


#include<iostream>
#include"PALINDROMANIA.cpp"
using namespace std;


int main()
{
	string palindrome;
	MyStack<char> ms;
	bool result = false;
	cout << "Enter a string to check whether it is a palindrome or not:\n";
	getline(cin, palindrome);//inputs the string
	result = isPalindrome(palindrome, ms);//returns the bool valur into the result//to check whether the entered string is palindrome or not 
	if (result == 1)//if string is palindrome
		cout << "\nThe entered string is a PALINDROME\n";
	else if (result == 0)//if string is NOT palindrome
		cout << "\nThe entered string is NOT a PALINDROME\n";

	return 0;
}


//BSEF19M003
//LAIBA KAMAL