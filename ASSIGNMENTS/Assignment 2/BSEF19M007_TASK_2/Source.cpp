#include<iostream>
#include<string>
using namespace std;


string Cipher(string text, string keyword) {

	/*
	* Cipher:
	* This function takes a normal message and encipher it with the key.
	* :param: text and keyword
	* :return: Ciphered text
	*/

	int j = 0, add = 0;
	for (int i = 0; i < text.length(); i++) {

		if (isalpha(text[i])) {	//convert only alphabets
			add = text[i] - 'A';	//calculate how many letters ahead is the character
			text[i] = (keyword[j] + add) % 91;	//Adding the difference in keyword's charachter, mod is takken to make sure it stays an alphabet
			if (text[i] < 'A')	//if after mod, it is reduced we make it an alphabet again
				text[i] += 'A';
		}

		j++;	//iterating variable
		if (j == keyword.length())	
			j = 0;
	}

	return text;
}

string Decipher(string text, string keyword) {
	

	/*
	* Decipher:
	* This function takes a secret encoded message and decipher it with the key.
	* :param: text and keyword
	* :return: deciphered text
	*/


	int j = 0, add = 0;	
	for (int i = 0; i < text.length(); i++) {

		if (isalpha(text[i])) {	//convert only alphabets
			add = 'Z' - keyword[j] + 1;	//Calculating how many letters are left to reach 'Z'
			add = add + text[i];	//Addiing it with the difference between the character and 'A'
			text[i] = (add) % 91;
			if (text[i] < 'A') {
				text[i] += 'A';
			}
			
		}
		j++;
		if (j == keyword.length())
			j = 0;
	}
	return text;
}

int main() {

	string text,keyword,output;

	cout << "=> Enter the secret message: ";
	getline(cin, text);
	
	cout << "=> Enter the cipher key: ";
	getline(cin, keyword);

	output = Cipher(text, keyword);
	cout << "=> Output: " << output << endl << endl;

	cout << "------------------------------------" << endl << endl;

	cout << "=> Enter the cipher message: ";
	getline(cin, text);

	cout << "=> Enter the cipher key: ";
	getline(cin, keyword);

	output = Decipher(text, keyword);
	cout << "=> Output: " << output << endl;

	return 0;
}
