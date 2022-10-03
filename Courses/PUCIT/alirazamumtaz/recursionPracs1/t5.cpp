/*
Given a string, compute recursively a new
string where all the adjacent chars are
now separated by a "*".
*/

#include<iostream>

using namespace std;

char * putAstrik(char * str, int size, int p){
	const static int newSize = 2*size-1;
	static char * newStr = new char[newSize];
	if(size == 0) return newStr;
	newStr[p] = newStr[p];
	newStr[p+1] = '*';
	return putAstrik(str,size-1,p+1);
}
char * putAstrik(char * str, int size){
	return putAstrik(str,size,0);
}

int main(int args, char** argv){
	cout << putAstrik((char*)argv[2],atoi(argv[1]));
	return 0;
}
/*
hello		no
h 		0   h
*/