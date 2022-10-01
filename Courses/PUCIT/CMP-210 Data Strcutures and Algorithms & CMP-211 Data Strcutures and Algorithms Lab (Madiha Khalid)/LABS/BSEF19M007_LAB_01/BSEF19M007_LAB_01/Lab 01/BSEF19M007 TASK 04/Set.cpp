#include "Set.h"

void Set::Create() {

    /*
    Values are added in the set when Create is called,
    It is made sure that the set follows the standard mathematics rules
    */

    int x;
    cout << "=> How many values you want to put in the set? "; cin >> size;
    set = new int[size];
    cout << "=> Give " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> x;  set[i] = x;
    }
    Sort();
    RemoveReppition();
}

void Set::Insert(int x) {
    /*
    The provided arguemented element is inserted into the current set
    */
    set[size++] = x;
    Sort();
    RemoveReppition();
}

void Set::Remove(int x) {

    /*
    The provided arguemented value is taken out from the set if exists
    */

    int replace = 0, foundInt = 0;
    bool found = false;
    bool Last_found = false;

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

void Set::Print() {

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

void Set::Sort() {

    /*
    Sort the Set in Ascending Order
    */
    int max;

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


bool Set::IsMember(int x) {

    /*
    Provided arguemented value is looked in the current set
    */

    for (int i = 0; i < size; i++) {
        if (set[i] == x)
            return true;

    }
    return false;
}

Set Set::Union(Set S2) {

    /*
    This set and arguemented set is combined/united
    */

    Set Resultant;
    int j = 0;
    Resultant.size = size + S2.size;
    Resultant.set = new int[Resultant.size];

    for (int i = 0; i < Resultant.size; i++)
        Resultant.set[i] = 0;

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

Set Set::Intersection(Set S2) {

    /*
   This set and arguemented set is intersected and common values are found
   */

    Set Resultant;
    int J = 0;
    int Size_check = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < S2.size; j++) {
            if (set[i] == S2.set[j])
                Size_check++;


        }
    }

    Resultant.size = Size_check;
    Resultant.set = new int[Resultant.size];

    for (int i = 0; i < Resultant.size; i++)
        Resultant.set[i] = 0;

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

bool Set::IsSubset(Set S2) {

    /*
    Provided arguemented Set is looked in the current this set
    */

    bool check = true;
    Set Resultant = Intersection(S2);

    if (Resultant.size != S2.size) check = false;
    
    else  {
        for (int i = 0; i < Resultant.size; i++) {

            if (Resultant.set[i] != S2.set[i]) {
                check = false;
                break;
            }

        }
    }

    return check;
}

void Set::RemoveReppition() {

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
