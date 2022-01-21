#include<iostream>
#include<string>
#define last ""	//end of the string

using namespace std;


/*
Replace function finds a particualr charachter from a string and replace it with another specified charachter.
:param: Input string, charchter to replace, charchter to be replaced with.
:return: void
*/

void replace(char* str, char from, char to) {

	if (*str == *last)	//if end of the string.
		return;
 
	else if (*str == from)	//if found
		*str = to;

	replace((str + 1), from, to);
}


int main() {

	string s;
	char from, to;

	cout << "=> Give input string: "; getline(cin, s);
	cout << "=> Give charachter you want to replace: "; cin >> from;
	cout << "=> Give charachter you want to replace with: "; cin >> to;

	replace(&s[0], from,to);
	
	cout << "=> String after replacement: " << s << endl;

	return 0;
}



