/*
Write a recursive function GCD(n,m) that returns the
greatest common divisor of two integers n and 
m according to the following definition:
*/

#include<iostream>
#include <string>

using namespace std;
int GCD(int n, int m){
	if(n>=m  and n%m == 0) return m;
	else if(m>n) return GCD(m,n);
	else return GCD(m,n%m);
}
int main(int args, char** argv){
	if(args > 1)
		cout << GCD(atoi(argv[1]),atoi(argv[2]));
	else
		cout << GCD(42,87);
	cout << "\nDone with this program.\n";
	return 0;
}