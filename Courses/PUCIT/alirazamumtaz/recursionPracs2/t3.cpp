/*
Write a recursive method that uses only addition,
subtraction, and comparison to multiply two 
numbers.

3 * 5 = 15
3 + 3 + 3 + 3 + 3 = 15

*/

#include<iostream>
#include <string>

using namespace std;

int myMul(int j, int k){
	if(j>k)  return myMul(k,j);
	if(k==0) return 0;
	else	 return j+ myMul(j,k-1);
}


int main(int args, char** argv){
	cout << myMul(3,5) << '\n';
	cout << myMul(4,3) << '\n';
	cout << myMul(9,5) << '\n';
	cout << "\nDone with this program.\n";
	return 0;
}