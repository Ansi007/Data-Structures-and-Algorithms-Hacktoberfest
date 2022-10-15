#ifndef ENTITY
#define ENTITY

#include<iostream>
#include<cstring>

using namespace std;

class Entity{
protected:
    string name;
    string id;
    string password;
public:
    Entity(string name, string id, string password)
    {
        this->name = name;
        this->id = id;
        this->password = password;
    }

    string getName() const{
        return name;
    }
    string getID() const{
        return id;
    }

    bool authLogin(string id, string password)
    {
        cout << "here: " << this->id << ' ' << this->password << endl;
        return (this->id == id && this->password == password);
    }
};

#endif