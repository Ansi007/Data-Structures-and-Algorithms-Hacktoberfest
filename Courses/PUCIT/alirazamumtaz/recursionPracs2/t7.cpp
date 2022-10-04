/*
Give a recursive version of the following function:

void cubes(int n) {
	for (int i = 1; i <= n; i++)
		cout << i * i * i << ’’;
}

*/

#include<iostream>
#include <string>

using namespace std;
void cubes(int n, int i) {
	cout << i*i*i << ' ';
	if(n == i) return;
	return cubes(n,i+1);
}
void cubes(int n){
	return cubes(n,1);
}
int main(int args, char** argv){
	if(args > 1)
		cubes(atoi(argv[1]));
	else
		cubes(3);
	cout << "\nDone with this program.\n";
	return 0;
}