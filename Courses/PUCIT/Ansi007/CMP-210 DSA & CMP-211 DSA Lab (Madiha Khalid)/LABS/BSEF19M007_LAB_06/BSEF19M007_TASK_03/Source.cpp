#include<iostream>
using namespace std;

void printND(int dimensions) {
	/*
	This functoin takes dimensions as arguemenet and print the Row Major based formula of index conversion.
	:param: Dimensions
	:return: void
	*/

	cout << "=> ";
	for (int p = 1; p <= dimensions; p++) {
		cout << "i" << p;
		for (int q = p + 1; q <= dimensions; q++) {
			cout << "D" << q;
		}
		if(p != dimensions)
			cout << "+";
	}
}

int main() {
	unsigned int d;
	cout << "=> Give number of dimensions: "; cin >> d;
	cout << "=> Row-Major based " << d << "D-array formula: " << endl;
	printND(d);

	return 0;
}