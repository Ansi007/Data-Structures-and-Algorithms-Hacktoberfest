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
	char check = ' ';	//To help in valid input
	cout << "=> Give input string: ";
	while (1) {

		cin.get(check);

		if (check == '\n')
			break;

		switch (check) {
		case '(':
		case ')':
			s += check;
		}

	}

	return s;
}

int parenthesisRequired(string s) {

	/*
	The function count the number of parenthis required to make the string valid
	:param: String to be checked
	:return: Count of parenthisis required
	*/

	MyStack<char>* S = new MyStack<char>(10);
	char check = ' ';	//To help in comparison
	int count = 0;		//By defualt the count is zero
	// Count == No of parenthesis required

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') {
			S->Push(s[i]);
			count++;
		}

		else {
			check = S->Pop();
			if (check == '(') {
				count--;
			}

			else count++;
		}
	}
	delete S;
	return count;
}

int main() {

	string s = validInput();
	cout << "=> Parenthesis string: " << s << endl;
	cout << "=> Number of parenthesis needed: " << parenthesisRequired(s) << endl;

	return 0;
}