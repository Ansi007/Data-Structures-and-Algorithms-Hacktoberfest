#include<iostream>
#include<string>
#include "MyStack.h"
#include "MyStack.cpp"

using namespace std;

bool isOperator(char C) {
	return (C == '+' || C == '-' || C == '*' || C == '/' || C == '%');
}

bool isClosingParenthesis(char C) {
	return (C == ')' || C == ']' || C == '}');
}

bool isOpeningParenthesis(char C) {
	return (C == '(' || C == '[' || C == '{');
}

bool isBalanced(string input_string) {

	/*
	The function will tell if the string is valid or not
	:param input_string: The string recieved
	:return: True if Valid else false
	*/

	MyStack<char> S;
	char check = ' ';	 // To help in comparison
	bool validity = true;	// By default, the validity is set to true


	for (int i = 0; i < input_string.length(); i++) {

		if (isOpeningParenthesis(input_string[i])) {
			if (isOperator(input_string[i + 2])) {
				validity = false;
				break;
			}
		}


		else if (isClosingParenthesis(input_string[i])) {
			if (isOperator(input_string[i - 2])) {
				validity = false;
				break;
			}
		}

		if (isOpeningParenthesis(input_string[i]))
			S.Push(input_string[i]);

		else if (isClosingParenthesis(input_string[i])) {
			check = S.Pop();
			if (input_string[i] == ')' && check != '(' || input_string[i] == ']' && check != '[' || input_string[i] == '}' && check != '{') {
				validity = false;
				break;
			}
		}
	}
	

	if (S.isEmpty() && validity == true)
		return true;

	else return false;
}

string infixToPosfix(string input_string) {

	/*
	The function will convert an infix expression to postfix
	:param input_string: The string recieved
	:return: Converted Postfix Expression
	*/

	string output_string = "";
	MyStack<char> S;
	int length = input_string.length();
	input_string += "$";

	//	changing all brackets to (), to reduce code complexitiy

	for (int i = 0; i < length; i++) {

		if (input_string[i] == '{' || input_string[i] == '[')
			input_string[i] = '(';

		if (input_string[i] == '}' || input_string[i] == ']')
			input_string[i] = ')';
	}

	for (int i = 0; i < length; i++) {

		if (isalpha(input_string[i])) {
			output_string += input_string[i];
			output_string += ' ';
		}

		else if (isdigit(input_string[i])) {

			if (input_string[i - 1] == '-')
				output_string += '-';

			output_string += input_string[i++];

			while (input_string[i] != ' ') {
				if (input_string[i] == '$')
					break;

				output_string += input_string[i++];
			}

			output_string += ' ';
		}

		else if (input_string[i] == '+' || input_string[i] == '-') {
			if (S.Peek() != '+' && S.Peek() != '-' && S.Peek() != '*' && S.Peek() != '/') {
				S.Push(input_string[i]);
			}

			else {
				output_string += S.Pop();
				output_string += ' ';
				i--;
				continue;
			}
		}

		else if (input_string[i] == '*' || input_string[i] == '/') {
			if (S.Peek() != '*' && S.Peek() != '/') {
				S.Push(input_string[i]);
			}

			else {
				output_string += S.Pop();
				output_string += ' ';
				i--;
				continue;
			}
		}

		else if (input_string[i] == '(') {
			S.Push(input_string[i]);
		}
	
		else if (input_string[i] == ')') {
			while (S.Peek()!= '(') {
				output_string += S.Pop();
				output_string += ' ';

			}
			S.Pop();
		}
	}

	while (!S.isEmpty()) {
		output_string += S.Pop();
		output_string += ' ';
	}

	return output_string;

}

string Evaluation(string input_string,bool key) {

	/*
	The function will Evaluate either a prefix or postfix expression
	:param input_string: The string recieved
	:return: Evaluated string
	*/

	int length = input_string.length();		
	int number1, number2 = 0;	//For evaluation

	string output_string = "";	
	string helping_string = "";	//For Push and Pop
	string sub1 = "", sub2 = "";	//For evaluation

	MyStack<string> S;
	bool isNumber = false;

	
	cout << "=> Enter 0 if the provided expression have alphabets in it E.G. like this --> a b c + - " << endl;
	cout << "=> Enter 1 if the provided expression is a numerical expression E.G. like this -->  40 1 3 + - " << endl;
	cin >> isNumber;

	if (key == 1) {

		for (int i = 0; i < length; i++) {

			if (isalpha(input_string[i])) {
				helping_string = input_string[i];
				S.Push(helping_string);
			}

			else if (isdigit(input_string[i])) {
				helping_string = input_string[i++];

				while (input_string[i] != ' ') {
					helping_string += input_string[i++];
				}

				S.Push(helping_string);
			}

			else if (isOperator(input_string[i])) {
				sub2 = S.Pop();
				sub1 = S.Pop();

				if (isNumber == false) {
					output_string = '(';	output_string += sub1;	output_string += input_string[i];
					output_string += sub2;	output_string += ')';
					S.Push(output_string);
				}

				else {
					number1 = stoi(sub1);
					number2 = stoi(sub2);

					switch (input_string[i]) {
					case '+':
						S.Push(to_string(number1 + number2));
						break;
					case '-':
						S.Push(to_string(number1 - number2));
						break;
					case '*':
						S.Push(to_string(number1 * number2));
						break;
					case '/':
						S.Push(to_string(number1 / number2));
						break;
					case '%':
						S.Push(to_string(number1 % number2));
						break;
					default:
						break;
					}
				}
			}
		}
	}

	else {
		int ending_index = 0;

		for (int i = input_string.length() - 1; i >= 0; i--) {

			if (isalpha(input_string[i])) {
				helping_string = input_string[i];
				S.Push(helping_string);
			}

			else if (isdigit(input_string[i])) {
				ending_index = i;

				while (input_string[i] != ' ')
					i--;

				i++;
				helping_string = "";

				for (int k = i; k <= ending_index; k++)
					helping_string += input_string[k];

				S.Push(helping_string);
			}

			else if (isOperator(input_string[i])) {
				sub1 = S.Pop();
				sub2 = S.Pop();

				if (isNumber == false) {
					output_string = '(';	output_string += sub1;	output_string += input_string[i];
					output_string += sub2;	output_string += ')';
					S.Push(output_string);
				}

				else {
					number1 = stoi(sub1);
					number2 = stoi(sub2);

					switch (input_string[i]) {
					case '+':
						S.Push(to_string(number1 + number2));
						break;
					case '-':
						S.Push(to_string(number1 - number2));
						break;
					case '*':
						S.Push(to_string(number1 * number2));
						break;
					case '/':
						S.Push(to_string(number1 / number2));
						break;
					case '%':
						S.Push(to_string(number1 % number2));
						break;
					default:
						break;
					}
				}
			}
		}

	}

	output_string = S.Pop();
	return output_string;
}


int main() { 
	
	string input_string = "";
	string output_string = "";
	bool key;
	
	cout << "=> Give a SPACE SEPERATED infix expression E.G. ( A + B ): ";
	getline(cin, input_string);

	if (isBalanced(input_string)) {
		output_string = infixToPosfix(input_string);
		cout << "=> Infix: " << input_string << endl;
		cout << "=> Postfix: " << output_string << endl;
	}

	else cout << "=> It was not balanced, no conversion possible!" << endl;
	
	cout << "=> Tell if you want to do POSTFIX or PREFIX evaluation, Enter 1 for POSTFIX and 0 for PREFIX: ";
	cin >> key;
	cout << endl;

	cin.ignore();
	cout << "=> Give THE SPACE SEPERATED EXPRESSION: ";
	getline(cin, input_string);
	cout << endl;

	output_string = Evaluation(input_string, key);
	cout << "=> After evaluation: " << output_string << endl;
	
	return 0; 
}
