#include<iostream>
using namespace std;
struct Fraction{
	int nomi ;
	int denomi;
};

Fraction addFraction(const Fraction& f1, const Fraction& f2)
{
	Fraction f3;
	if(f1.denomi==f2.denomi)
	{
		f3.nomi = f1.nomi + f2.nomi;
		f3.denomi = f1.denomi;
	}
	else
	{
		f3.denomi = (f1.denomi)* (f2.denomi);
		f3.nomi = ((f3.denomi/f1.denomi)*f1.nomi)+((f3.denomi/f2.denomi)*f2.nomi);
		cout<<"sss";
	}
	return f3;
}

int main()
{
	Fraction f1={1,2};
	Fraction f2={1,3};
	Fraction f3 = addFraction(f1,f3);
	
	cout<<f3.nomi<<"/"<<f3.denomi<<endl;
	
	return 0;
}