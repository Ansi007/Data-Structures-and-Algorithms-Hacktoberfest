#include<iostream>
#include<stdarg.h>
#include "TwoD_Matrix.h"
#include "TwoD_Matrix.cpp"


using namespace std;


int main() {

	int r, c, x;
	cout << "=> Give no of rows and cols in the matrix: ";
	cin >> r >> c;

	TwoD_Matrix<int> m(r,c);
	
	for (int i = 0; i < r; i++) {
		cout << "=> Give row: ";
		for (int j = 0; j < c; j++) {
			cin >> x;
			m.setElement(i, j, x);
		}
	}

	cout << "\n=> Given Matrix is: " << endl;
	m.printMatrix(m);

	
	cout << "\n=> Transpose of the Matrix is: " << endl;
	m.transpose(); 
	
	cout << "\n=> Matrix after addition of first with the second is: " << endl;
	m + m;
	cout << endl;

	cout << "=> Give no of rows/cols to clear: "; cin >> x;
	m.clear(x);
	m.printMatrix();
	cout << endl;

	int r1, r2, c1, c2;
	cout << "=> Give start of rows and end of rows (E.g. for row 1 give 0, and for row 2 give 1): "; cin >> r1 >> r2;
	cout << "=> Give start of cols and end of cols (E.g. for col 1 give 0, and for col 2 give 1): "; cin >> c1 >> c2;
	cout << "\n=> Sub-Matrix: " << endl;
	m.printSubMatrix(r1,r2,c1,c2);

	return 0;
}