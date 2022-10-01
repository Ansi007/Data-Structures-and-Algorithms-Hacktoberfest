#include<iostream>
#include<string>

using namespace std;

/*
using templates in seperate files causes linknig errors that's header and source is combined.
*/


/*
Class Set based on  Standard Mathematics Set. 
*/

template<class T>
class Set {
private:
    T* set;
    int size;
public:
	void Create();
	void Insert();
	void Remove();
	bool IsMember();
	Set Union(Set);
	Set Intersection(Set);
	bool IsSubset(Set);
	void RemoveReppition();
	void Print();
	void Sort();
};


template<class T>
void Set<T>::Create() {

    /*
    Values are added in the set when Create is called,
    It is made sure that the set follows the standard mathematics rules
    */

    T x;
    cout << "=> How many values you want to put in the set? "; cin >> size;
    set = new T[size];
    cout << "=> Give " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> x;  set[i] = x;
    }
    Sort();
    RemoveReppition();
}
template<class T>
void Set<T>::Insert() {

    /*
    The provided arguemented element is inserted into the current set
    */
   

    T x;
    cout << "=> Give a value you want to insert in the set: ";  cin >> x;
    set[size++] = x;
    Sort();
    RemoveReppition();
}
template<class T>
void Set<T>::Remove() {

    /*
    The provided arguemented value is taken out from the set if exists
    replace keep record of the next value, foundInt count the number, boolean found keep an eye if value is found or not
    */

    T x;
    cout << "=> Give a value you want to remove from the set: ";  cin >> x;

    T replace;
    bool Last_found = false;
    int foundInt = 0;
    bool found = false;

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            if (set[i] == x) {
                found = true;
                foundInt++;
                if (i == size - 1) {
                    Last_found = true;
                    break;
                }
                else {
                    for (int j = i; j < size - 1; j++) {

                        replace = set[j + 1];
                        set[j] = replace;
                    }

                }

            }
        }
        if (Last_found == true) break;
    }
    if (found == true)  size -= foundInt;
}
template<class T>
void Set<T>::Print() {

    /*
    Print the Set in Set format
    */

    cout << "{ ";
    for (int i = 0; i < size; i++) {

        cout << set[i] << " ";
        if (i == size - 1)
            break;
        cout << ", ";

    }
    cout << "}";
    cout << endl;
}
template<class T>
void Set<T>::Sort() {

    /*
    Sort the Set in Ascending Order
    */

    T max;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (set[i] < set[j]) {
                max = set[i];
                set[i] = set[j];
                set[j] = max;
            }
        }

    }
}

template<class T>
bool Set<T>::IsMember() {

    /*
    Provided arguemented value is looked in the current set
    */

    T x;
    cout << "=> Give a value you want to check if it is the member of the set: ";  cin >> x;
    for (int i = 0; i < size; i++) {
        if (set[i] == x)
            return true;

    }
    return false;
}
template<class T>
Set<T> Set<T>::Union(Set<T> S2) {

    /*
    This set and arguemented set is combined/united
    */

    Set<T> Resultant;
    int j = 0;
    Resultant.size = size + S2.size;
    Resultant.set = new T[Resultant.size];

   
    for (int i = 0; i < size; i++) {
        Resultant.set[j++] = set[i];
    }

    for (int i = 0; i < S2.size; i++) {
        Resultant.set[j++] = S2.set[i];
    }
    Resultant.Sort();
    Resultant.RemoveReppition();
    return Resultant;
}
template<class T>
Set<T> Set<T>::Intersection(Set S2) {

    /*
   This set and arguemented set is intersected and common values are found
   */

    Set<T> Resultant;
    int J = 0;
    int Size_check = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < S2.size; j++) {
            if (set[i] == S2.set[j])
                Size_check++;


        }
    }

    Resultant.size = Size_check;
    Resultant.set = new T[Resultant.size];

  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < S2.size; j++) {
            if (set[i] == S2.set[j])
                Resultant.set[J++] = S2.set[j];


        }
    }
    Resultant.Sort();
    Resultant.RemoveReppition();
    return Resultant;
}
template<class T>
bool Set<T>::IsSubset(Set S2) {

    /*
    Provided arguemented Set is looked in the current this set
    */

    bool check = true;
    Set<T> Resultant = Intersection(S2);

    if (Resultant.size != S2.size) check = false;

    else {
        for (int i = 0; i < Resultant.size; i++) {

            if (Resultant.set[i] != S2.set[i]) {
                check = false;
                break;
            }

        }
    }

    return check;
}
template<class T>
void Set<T>::RemoveReppition() {

    int replace = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (set[i] == set[j]) {
                for (int k = j; k < size - 1; k++) {
                    replace = set[k + 1];
                    set[k] = replace;
                }
                size--;
                --j;
            }
        }
    }
}





int main() {
	Set<char> s1, s2, Resultant;
    
    
	s1.Create();
	cout << "=> Set after Creation: ";
	s1.Print();


	s1.Insert();
	cout << "=> Set after Insertion: ";
	s1.Print();

	
	s1.Remove();
	cout << "=> Set after Removal: ";
	s1.Print();


	if (s1.IsMember() == true) {
		cout << "=>" << " Found. " << endl;
	}

	else cout << "=>  " << " Not Found. " << endl;


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
