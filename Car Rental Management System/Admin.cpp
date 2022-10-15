#ifndef ADMIN
#define ADMIN
#include <cstring>
#include <iostream>
#include "Person.cpp"

using namespace std;

class Admin: public Person{

public:
    Admin(string Name, string id, string password) : Person(Name, id, password){}

    bool Admin_Login(string identification, string pass){
        if(identification!=id || pass!=password) //password verification
            return false;
        return true;
    }

    friend ostream& operator << (ostream& out, Admin& admin){
        out << admin.name << ',' << admin.id << ',' << admin.password << ',' << endl;
        return out;
    }
};
#endif