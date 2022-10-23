#include<iostream>
#include"Fraction.h"
using namespace std;

ostream& operator<<(ostream& o,const Fraction& a)
{
	cout << a.num<< "/" <<  a.denom;
	return o;
}
istream& operator>>(istream& i, Fraction& a)
{
	i >> a.num;
	cin.ignore();
	i >> a.denom;
	return i;
}

int main()
{
	Fraction f1(2, 8);
	Fraction f2(3, 16);
	cout << "f1 =" << f1 << " "<<endl << "f2 =" << f2 << endl;
	cout << f1 + f2;
	Fraction f3 = f1 + f2;
	f3.reduce();
	cout << "f1+f2 =" << f3 << endl;
	f3 = f1 - f2;
	f3.reduce();
	cout << "f1-f2 =" << f3 << endl;
	Fraction f4 = f2 / f1;
	f4.reduce();
	cout << "f1/f2 =" << f4 << endl;
	if (f1 == f2)
	{
		cout << "f1 and f2 are equal" << endl;
	}
	if (f1 != f2)
	{
		cout << "f1 and f2 are not equal" << endl;
	}
	if (f1 < f2)
	{
		cout << "f2 is greator" << endl;
	}
	Fraction f5;
	f5 = f1 * f2;
	f5.reduce();
	cout << "f1*f2 =" << f5 << endl;
	f5 = f1 ^ 2;
	cout << "f1^2 =" << f5 << endl;
	f5 = -f1;
	cout << "-f1 =" << f5 << endl;
	 f5 = ++f1;
	cout << "++f1 =" << f5 << endl;
	f5 = f1++;
	cout << "f1++ =" << f5 << endl;
	f1 += f2;
	f1.reduce();
	cout << "f1+=f2 :" << f1 << endl;


}