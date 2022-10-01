#include<iostream>
#include<string>
#define Last ""	//end of string

using namespace std;

/*
countChar:
Counts the number of charachters in any string.
:param: Input string
:return: Total number of charachter
*/


int countChar(char* Str) {


	if (*Str == *Last)	//if end of string.
		return 0;

	return 1 + countChar((Str + 1));
}



int main() {

	string S;
	cout << "=> Give string: ";
	getline(cin, S);
	cout << "=> The number of characters in " << S << " are " << countChar(&S[0]);

	return 0;
}

