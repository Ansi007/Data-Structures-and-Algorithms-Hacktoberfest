/*
 Write a recursive method to print a Syracuse sequence
 that begins with a number n0 and each element ni of 
 the sequence is ni-1 /2 if ni-1 is even and 3ni-1 + 1 otherwise.
 The sequence ends with 1.

For instance, starting with n = 12, one gets the sequence 12, 6, 3, 10, 5, 16, 8, 4, 2, 1. 
*/

#include<iostream>
#include <string>

using namespace std;

void printSyracuseSequence(int n){
	cout << n << ' ';
	if(n == 1)	return;
	if(n%2==0)	printSyracuseSequence(n/2); 
	else		printSyracuseSequence(3*n + 1);

}

int main(int args, char** argv){
	printSyracuseSequence(12);
	cout << "\nDone with this program.\n";
	return 0;
}