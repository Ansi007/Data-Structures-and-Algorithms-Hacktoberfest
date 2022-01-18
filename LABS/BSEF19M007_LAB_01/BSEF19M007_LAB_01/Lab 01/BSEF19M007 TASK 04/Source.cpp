#include<iostream>
#include "Set.h"


using namespace std;


int main() {
	Set s1, s2, Resultant;
	int x;

	s1.Create();
	cout << "=> Set after Creation: ";
	s1.Print();

	cout << "=> Give a value you want to insert in the set: ";  cin >> x;
	s1.Insert(x);
	cout << "=> Set after Insertion: ";
	s1.Print();

	cout << "=> Give a value you want to remove from the set: ";  cin >> x;
	s1.Remove(x);
	cout << "=> Set after Removal: ";
	s1.Print();


	cout << "=> Give a value you want to check if it is the member of the set: ";  cin >> x;

	if (s1.IsMember(x) == true) {
		cout << "=>  " << x << " Found. " << endl;
	}

	else cout << "=>  " << x << " Not Found. " << endl;


	s2.Create();
	cout << "=> Set after Creation: ";
	s2.Print();

	Resultant = s1.Union(s2);
	cout << "=> Resultant Set after Union of first two sets: ";
	Resultant.Print();

	Resultant = s1.Intersection(s2);
	cout << "=> Resultant Set after Intersection of first two sets: ";
	Resultant.Print();

	if (s1.IsSubset(s2) == true) {
		cout << "=> S2 is a Subset of S1" << endl;
	}

	else cout << "=> S2 is not a Subset of S1" << endl;


	return 0;
}