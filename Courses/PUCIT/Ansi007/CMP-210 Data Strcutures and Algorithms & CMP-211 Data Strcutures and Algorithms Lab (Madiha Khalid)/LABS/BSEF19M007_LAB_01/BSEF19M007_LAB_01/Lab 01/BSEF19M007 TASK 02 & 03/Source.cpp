#include<iostream>
#include "Complex.h"

using namespace std;


int main() {
	//Task 02
	double real, imag;
	cout << "=> Give Real Part of Complex Number: ";	cin >> real;
	cout << "=> Give Imaginary Part of Complex Number: ";	cin >> imag;
	Complex C1(real,imag);
	cout << endl;

	cout << "=> Give Real Part of Complex Number: ";	cin >> real;
	cout << "=> Give Imaginary Part of Complex Number: ";	cin >> imag;
	Complex C2(real, imag),Resultant = C1;
	cout << endl;

	Resultant = C1.add(C2);
	cout << "=> Addition: ";
	Resultant.print();

	Resultant = C1.subtract(C2);
	cout << "=> Subtraction: ";
	Resultant.print();

	Resultant = C1.multiply(C2);
	cout << "=> Multiplication: ";
	Resultant.print();
	
	Resultant = C1.divide(C2);
	cout << "=> Division: ";
	Resultant.print();
	
	Resultant = C1.conjagate(C1);
	cout << "=> Conjugate of first Complex Number:  ";
	Resultant.print();
	
	Resultant.setReal(C1.getReal()); Resultant.setImage(C1.getImag());
	cout << "=> By Getter and Setter Methods: ";
	Resultant.print();

	//Task 03
	cout << endl;
	cout << "=> By Operator Overloading: " << endl;
	Resultant = C1 + C2;
	cout << "=> Addition: ";
	Resultant.print();

	Resultant = C1 - C2;
	cout << "=> Subtraction: ";
	Resultant.print();
	return 0;
}