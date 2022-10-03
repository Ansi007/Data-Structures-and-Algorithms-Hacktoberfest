/*
Write a recursive method that for a positive integer
returns a string with commas in the appropriate 
places, for example, putCommas(1234567) returns the
string "1,234,567."

1234567		1,234,567
1234567%10 = 7
123456%10 = 6
12345%10 = 5
.....
...
*/

#include<iostream>
#include <string>

using namespace std;

string putCommas(long long n, int factorSize){
	static string str = "";
	// base case
	if(n <= 0)	return string(str.rbegin(),str.rend()); // return string in reverse order
	
	str += 48+(n%10); // adding int as char

	if(factorSize == 3){
		str += ',';
		factorSize=0;
	}
	
	return	putCommas(n/10,factorSize+1);
}
string putCommas(long long n){
	return putCommas(n, 1);
}

int main(int args, char** argv){
	cout << putCommas(1234567);
	cout << "\nDone with this program.\n";
	return 0;
}