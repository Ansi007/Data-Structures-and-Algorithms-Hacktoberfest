#pragma once
#include<iostream>
using namespace std;
class Fraction
{
private:
	int num;
	int denom;
	int gcd(int num1, int num2);
	public:
		Fraction() :num(0), denom(1)
		{

		}
		Fraction(int n, int d) :num(n)
		{
			if (d > 0)
			{
				denom = d;
			}
		}
		Fraction(const Fraction&);
		~Fraction();
		void setDenom(int);
		void setNum(int);
		int getDenom() const;
		int getNum() const;
		Fraction &reduce();
		Fraction operator+(const Fraction&);
		Fraction operator-(const Fraction&);
		Fraction operator*(const Fraction&);
		Fraction operator/(const Fraction&);
		Fraction & operator+=(const Fraction&);
		Fraction operator^(int);
		Fraction operator-();
		Fraction &operator++();
		Fraction operator++(int);
		bool operator==(const Fraction&);
		bool operator<(const Fraction&);
		bool operator!=(const Fraction&);

		// Friend Function For Input and Output
		friend ostream& operator<<(ostream&,const Fraction&);
		friend  istream& operator>>(istream&, Fraction&);

};