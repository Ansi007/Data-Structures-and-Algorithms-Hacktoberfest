#ifndef PERSON
#define PERSON
#include <cstring>
#include <iostream>

using namespace std;
class Person{
protected:
    string name;
    string id;
    string password;
public:
    Person(){}
    Person(string name, string id, string password){
        this->name=name;
        this->id=id;
        this->password=password;
    }

    string Get_name(){
        return name;
    }
};
#endif
