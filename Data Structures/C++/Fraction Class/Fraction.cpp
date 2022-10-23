#include<iostream>
using namespace std;
#include"Fraction.h"

int Fraction:: gcd(int n1, int n2)
{
	int gcd = 0;
	
	if (n2 < n1)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	for (int i = 1; i <= n1; i++) 
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			gcd = i;
		}
	}
	return gcd;

}

Fraction::Fraction(const Fraction& a) //CC
{
	num = a.num;
	denom = a.denom;
}

Fraction::~Fraction() //Destructor
{

}

void Fraction::setDenom(int d) 
{
	denom = d;

}
void Fraction::setNum(int n)
{
	num = n;
}
int Fraction::getDenom() const
{
	return denom;

}
int Fraction::getNum() const
{
	return num;
}
Fraction& Fraction::reduce()
{
	int hcf= gcd(denom, num);
	denom = denom / hcf;
	num = num / hcf;
	return *this;
}

Fraction Fraction::operator+(const Fraction& a)
{
	Fraction temp;
	temp.denom = (denom * a.denom);
	temp.num = ((temp.denom / denom) * num) + ((temp.denom / a.denom) * a.num);
	return temp;
}
Fraction Fraction::operator-(const Fraction& a)
{
	Fraction temp;
	temp.denom = (denom * a.denom);
	temp.num = ((num) * (temp.denom / denom) )- ((a.num) * (temp.denom / a.denom));
	return temp;
	
}
Fraction Fraction::operator*(const Fraction& a)
{
	Fraction temp(*this);
	temp.num = num*a.num;
	temp.denom = denom* a.denom;
	return temp;

}
bool Fraction::operator==(const Fraction& a)

{
	if (a.num == num && a.denom == denom)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Fraction::operator<(const Fraction& a)
{
	if (double(num / denom) < double(a.num / a.denom))
	{
		return true;

	}
	else
		return false;
}
bool Fraction::operator!=(const Fraction& a)
{
	if (a.num != num || a.denom != denom)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Fraction Fraction::operator-()
{

	Fraction temp(*this);
	temp.num = -(num);
	return temp;

}
Fraction &Fraction::operator++()
{

	num++;
	denom++;
	return *this;

}
Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	num++;
	denom++;
	return temp;
}

Fraction & Fraction::operator+=(const Fraction& a)
{
	*this = *this + a;
	return  *this;
}
Fraction Fraction:: operator/(const Fraction& a)
{
	Fraction temp(*this);
	temp.num = this->num * a.denom;
	temp.denom= this->denom + a.num;
	return temp;
}
Fraction Fraction::operator^(int a)
{
	Fraction temp(*this);
	int temp2 = this->denom;
	int temp1 = this->num;

	for (int i = 1; i<a; i++)
	{
		temp.num *= temp1;
		temp.denom *= temp2;
	
	}
	return temp;
}
