#pragma once
//Task 02
class Complex {
private:
	double x, y;
public:
	Complex();
	Complex(double);
	Complex(double, double);
	Complex(const Complex&);
	Complex add(Complex);	//add this with arguemented complex number
	Complex subtract(Complex);	//subtract this with arguemented complex number
	Complex multiply(Complex);	//multiply this with arguemented complex number
	Complex divide(Complex);	//divide arguemented complex number with this
	Complex conjagate(Complex);	
	void print();
	double getReal();
	double getImag();
	void setReal(double);
	void setImage(double);

	//Task 03
	friend Complex operator + (Complex C1, Complex C2);	
	friend Complex operator - (Complex C1, Complex C2);
};
