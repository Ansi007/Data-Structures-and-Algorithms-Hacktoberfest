#include "Complex.h"
#include <iostream>
using namespace std;

//Task 02

Complex::Complex() {
	x = 0;
	y = 0;
}

Complex::Complex(double r){
	x = r;
	y = 0;
}

Complex::Complex(double r, double i){
	x = r;
	y = i;
}

Complex::Complex(const Complex& c){
	x = c.x;
	y = c.y;
}

Complex Complex::add(Complex c) {
	return Complex(x + c.x, y + c.y);
}

Complex Complex::subtract(Complex c) {
	return Complex(x - c.x, y - c.y);
}

Complex Complex::multiply(Complex c) {
	return Complex((x * c.x) - (y * c.y),(x * c.y) + (y*c.x));
}

Complex Complex::divide(Complex c) {
	int Den;	//Denominator
	Complex C1(x, y), C2(c.x, c.y);
	C1 = C1.multiply(C2.conjagate(C2));	//For Numerator
	C2 = C2.multiply(C2.conjagate(C2));
	Den = C2.getReal();
	
	return Complex((C1.x / Den),(C1.y / Den));
}

Complex Complex::conjagate(Complex c) {
	return Complex(c.x, -(c.y));
}

void Complex::print() {
	if (y >= 0)
		cout << x << " + " << y << "i" << endl;
	else 
		cout << x << " - " << -(y) << "i" << endl;
}

double Complex::getReal() {
	return x;
}

double Complex::getImag() {
	return y;
}

void Complex::setReal(double r) {
	x = r;
}

void Complex::setImage(double i) {
	y = i;
}

Complex operator + (Complex C1, Complex C2) {
	return Complex(C1.x + C2.x , C1.y + C2.y);
}

Complex operator - (Complex C1, Complex C2) {
	return Complex(C1.x - C2.x, C1.y - C2.y);
}
