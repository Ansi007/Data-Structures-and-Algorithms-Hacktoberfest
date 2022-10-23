#ifndef RESTAURANT
#define RESTAURANT

#include<iostream>
#include<cstring>
#include "Meal.cpp"
#include "Entity.cpp"

using namespace std;

class Restaurant : public Entity{
public:
    Restaurant(string name, string id, string password) : Entity(name, id, password)
    {}

    ostream& stdOut(ostream& out, bool isFile = false)
    {
        string seperator;
        if(isFile)
            seperator = ",";
        else
            seperator = "\t";

        out << id << seperator;
        out << name << seperator;
        out << password << seperator;
        out << endl;

        return out;
    }
};

#endif