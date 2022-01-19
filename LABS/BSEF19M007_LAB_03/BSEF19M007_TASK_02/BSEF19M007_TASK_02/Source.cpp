#include<iostream>
#include"MyStack.h"
#include"MyStack.cpp"
#include<string>

using namespace std;

string validInput() {

	/*
	The function will take a valid string input
	:return: Input string
	*/

	string s = "";
	char check = ' ';
	cout << "=> Give input string: ";
	while (1) {

		cin.get(check);

		if (check == '\n')
			break;

		switch (check) {
		case '{':
		case '[':
		case '(':
		case ')':
		case ']':
		case '}':
			s += check;
		}

	}

	return s;
}


bool isValid(string s) {

	/*
	The function will tell if the string is valid or not
	:param s: The string recieved
	:return: True if Valid else false
	*/

	MyStack<char> S;
	char check = ' ';	 //To help in comparison
	bool validity = true;	// By default, the validity is set to true



	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			S.Push(s[i]);

		else {
			check = S.Pop();
			if (s[i] == ')' && check != '(' || s[i] == ']' && check != '[' || s[i] == '}' && check != '{') {
				validity = false;
				break;
			}

		}
	}

	if (S.isEmpty() && validity == true)
		return true;

	else return false;
}

int main() {

	string s = validInput();

	if (isValid(s) == true)
		cout << "=> Valid" << endl;

	else cout << "=> Invalid" << endl;

	return 0;
}