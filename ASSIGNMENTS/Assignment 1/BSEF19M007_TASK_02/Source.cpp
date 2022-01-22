#include<iostream>
#include<string>
#include "MyStack.h"
#include "MyStack.cpp"

using namespace std;

bool isUpper(char C) {
	/*
	This function takes a charachter as an arguement and checks if it's an upper case or not.
	:param: charachter C
	:return: True if UpperCase else returns false
	*/
	return (C >= 'A' && C <= 'Z');
}

bool isLower(char C) {
	/*
	This function takes a charachter as an arguement and checks if it's a lower case or not.
	:param: charachter C
	:return: True if LowerCase else returns false
	*/
	return (C >= 'a' && C <= 'z');
}
bool isNumber(char C) {
	/*
	This function takes a charachter as an arguement and checks if it's a number or not.
	:param: charachter C
	:return: True if a number else returns false
	*/
	return (C >= '1' && C <= '9');
}

string input() {

	/*
	This function takes a string input, handles the requirement and returns it.
	:return: String
	*/

	string input_string;
	getline(cin,input_string);
	int j = 0;
	for (int i = 0; i < input_string.length(); i++) {
		if (isUpper(input_string[i]))	{
			input_string[j++] = input_string[i] + 32;
		}

		else if (isLower(input_string[i]) || isNumber(input_string[i])) {
			input_string[j++] = input_string[i];
		}
	}

	input_string[j] = '$';
	return input_string;
}

bool isPalindrome(string input_string) {

	/*
	This function takes a string as an arguement and checks if it's a Palindrome or not.
	:param: String
	:return: True if Palindrome else returns false
	*/

	MyStack<char>S;
	bool check = true;

	for (int i = 0; input_string[i] != '$'; i++) {
		S.Push(input_string[i]);
	}
	
	for (int i = 0; !S.isEmpty(); i++) {
		if (input_string[i] != S.Pop()) {
			check = false;
			break;
		}
	}

	return check;
}

int main() {

	string input_string = input();
	if (isPalindrome(input_string))
		cout << "=> Given string is a Palindrome!!" << endl;
	else 
		cout << "=> Given string is NOT! a Palindrome!!" << endl;

	return 0;
}
