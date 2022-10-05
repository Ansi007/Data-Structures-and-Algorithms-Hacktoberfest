

//BSEF19M003
//LAIBA KAMAL


#include<iostream>
#include<string>
using namespace std;

string ciphers(string key, string msg);//encryption function forward declaration
string deciphers(string key, string ciphered_msg);//decryption function forward declaration

int main()
{
	int choice = 0; char c = 'y';
	string key = "", msg = "", ciphered_msg = "";
	while (c == 'y')
	{
		cout << "MENU:\nEnter 1 for encryption.\nEnter 2 for decryption.\nYour choice: ";
		cin >> choice;
		if (choice == 1)//cipher
		{
			cout << "Enter the secret message: ";
			cin.ignore();
			getline(cin, msg);
			cout << "Enter the cipher key: ";
			getline(cin, key);
			cout << "\nThe cipher message is:  " << ciphers(key, msg);
		}
		else if (choice == 2)//decipher
		{
			cout << "Enter the cipher message: ";
			cin.ignore();
			getline(cin, ciphered_msg);
			cout << "Enter the cipher key: ";
			getline(cin, key);
			cout << "\nThe original/decipher message is:  " << deciphers(key, ciphered_msg);
		}
		else
			cout << "Invalid choice.\n";
		cout << "\n\nEnter y if you wanna run again and n to exit the program.\nYour Choice: ";
		cin >> c;
	}
	return 0;
}

//BSEF19M003
//LAIBA KAMAL

string ciphers(string key, string msg)
{
	string ciphered_msg = "";
	char c = '\0';

	if (key.length() < msg.length())//if key is shorter than msg
		for (int i = 0; key.length() < msg.length(); i++)// then make the length of key equal to that of msg 
			key += key[i];// by appending the key in repetitive fashion

	for (int i = 0; i < key.length(); i++)//to convert loweracse to uppercase
	{
		if ((key[i] >= 'a') && (key[i] <= 'z'))//if key contains lowercase letters
			key[i] -= 32;//then convert lowercase to uppercase
		else
			continue;
	}

	for (int i = 0; i < msg.length(); i++)//parse through the whole message
	{
		if ((msg[i] >= 'a') && (msg[i] <= 'z'))//if msg contains lowercase letters
		{
			msg[i] -= 32;//convert loweracse to uppercase

			//(key[i] + msg[i])  --> this formula finds the corresponding alphabet of cipher msg out of the table
			// (%26) deals with boundary case:  ((key[i] + msg[i]) > 25)  and generates a number b/w 0-25 accordingly so that we get an alphabet b/w A-Z by further processing.
			// (+'A') adds to the number generated b/w 0-25 and generates the org. ASCII of corresponding alphabet.
			// (+ 32) adds to the generated uppercase alphabet and converts it to lowercase as we got org. letter in lowercase.
			c = ((key[i] + msg[i]) % 26) + 'A' + 32;
			//string ciphered msg is appended in each iteration
			ciphered_msg += c;
		}
		else if ((msg[i] >= 'A') && (msg[i] <= 'Z'))//if msg is already uppercase
		{
			//(key[i] + msg[i])  --> this formula finds the corresponding alphabet of cipher msg out of the table
			// (%26) deals with boundary case:  ((key[i] + msg[i]) > 25)  and generates a number b/w 0-25 accordingly so that we get an alphabet b/w A-Z by further processing.
			// (+'A') adds to the number generated b/w 0-25 and generates the org. ASCII of corresponding alphabet.
			c = ((key[i] + msg[i]) % 26) + 'A';
			//string ciphered msg is appended in each iteration
			ciphered_msg += c;
		}
		else
			ciphered_msg += msg[i];//if there is a space or some character other than alphabets, then simply copy them in cipher msg
	}
	return ciphered_msg;
}

//BSEF19M003
//LAIBA KAMAL

string deciphers(string key, string ciphered_msg)
{
	string deciphered_msg = "";
	char c = '\0';

	if (key.length() < ciphered_msg.length())//if key is shorter than cipher msg
		for (int i = 0; key.length() < ciphered_msg.length(); i++)// then make the length of key equal to that of cipher msg 
			key += key[i];// by appending the key in repetitive fashion

	for (int i = 0; i < key.length(); i++)//to convert loweracse to uppercase
	{
		if ((key[i] >= 'a') && (key[i] <= 'z'))//if key contains lowercase letters
			key[i] -= 32;//then convert lowercase to uppercase
		else
			continue;
	}

	for (int i = 0; i < ciphered_msg.length(); i++)//parse through the whole cipher message
	{
		if ((ciphered_msg[i] >= 'a') && (ciphered_msg[i] <= 'z'))//if cipher msg contains lowercase letters
		{
			ciphered_msg[i] -= 32;//convert loweracse to uppercase

			// ciphered_msg[i] - key[i]  --> this formula finds the corresponding alphabet of org msg out of the table
			// (+26) deals with boundary case:  ((ciphered_msg[i] - key[i]) < 0)
			// (%26) generates a number b/w 0-25 accordingly so that we get an alphabet b/w A-Z by further processing.
			// (+'A') adds to the number generated b/w 0-25 and generates the org. ASCII of corresponding alphabet.
			// (+ 32) adds to the generated uppercase alphabet and converts it to lowercase as we got org. letter in lowercase.
			c = (ciphered_msg[i] - key[i] + 26) % 26 + 'A' + 32;

			//string deciphered msg is appended in each iteration
			deciphered_msg += c;
		}
		else if ((ciphered_msg[i] >= 'A') && (ciphered_msg[i] <= 'Z'))
		{
			// ciphered_msg[i] - key[i]  --> this formula finds the corresponding alphabet of org msg out of the table
			// (+26) deals with boundary case:  ((ciphered_msg[i] - key[i]) < 0)
			// (%26) generates a number b/w 0-25 accordingly so that we get an alphabet b/w A-Z by further processing.
			// (+'A') adds to the number generated b/w 0-25 and generates the org. ASCII of corresponding alphabet.
			c = (ciphered_msg[i] - key[i] + 26) % 26 + 'A';

			//string deciphered msg is appended in each iteration
			deciphered_msg += c;
		}
		else
			deciphered_msg += ciphered_msg[i];//if there is a space or some character other than alphabets, then simply copy them in decipher msg
	}
	return deciphered_msg;
}

//BSEF19M003
//LAIBA KAMAL