//BSEF19M003
//LAIBA KAMAL


#include<iostream>
#include<string>
#include "MyStack.cpp"
using namespace std;


inline bool isPalindrome(string p, MyStack<char> s)
{
	string pushed, popped;
	for (int i = 0; i < p.length(); i++)//parse through whole string
	{
		if ((p[i] >= 'a') && (p[i] <= 'z'))//and if there is a lowercase alphabet
			p[i] -= 32;//convert it to uppercase
		else
			continue;
	}
	for (int i = 0; i < p.length(); i++)//parse through whole string
	{
		if (((p[i] >= 'A') && (p[i] <= 'Z')) || ((p[i] >= '0') && (p[i] <= '9')))//and if there is an alphabet(A-Z) or a digit (0-9)
		{
			s.push(p[i]);//push it on the stack
			pushed += p[i];//and append it to the string "pushed"
		}
		else
			continue;
	}
	for (int i = 0; (!s.isEmpty()); i++)//to pop from the stack
	{
		popped += s.pop();//append popped value to the string "popped"
	}
	if (pushed == popped)//if the string "pushed" and "popped" are equal
		return true;//then given string is palindrome
	else if (pushed != popped)//if the string "pushed" and "popped" are NOT equal
		return false;//then given string is NOT palindrome
}

//BSEF19M003
//LAIBA KAMAL