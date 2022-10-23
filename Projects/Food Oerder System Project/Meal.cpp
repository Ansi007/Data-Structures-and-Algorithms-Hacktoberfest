#ifndef MEAL
#define MEAL

#include<iostream>
#include<cstring>

using namespace std;

class Meal{
    string resID;
    string mealName;
    string description;
    string typeOfMeal;
    int price;
public:
    Meal(string resID, string typeOfMeal, string mealName, string description, int price)
    {
        this->resID = resID;
        this->typeOfMeal = typeOfMeal;
        this->mealName = mealName;
        this->description = description;
        this->price = price;
    }

    string getMealName() const{
        return mealName;
    }

    string getTypeOfMeal() const{
        return typeOfMeal;
    }

    int getPrice() const{
        return price;
    }

    ostream& stdOut(ostream& out, bool isFile = false)
    {
        string seperator;
        if(isFile)
            seperator = ",";
        else
            seperator = "\t";

        out << resID << seperator;
        out << typeOfMeal << seperator;
        out << mealName << seperator;
        out << description << seperator;
        out << price << seperator;
        out << '\n';

        return out;
    }

    void setMealName(string mealName) {
        this->mealName = mealName;
    }

    void setDescription(string description) {
        this->description = description;
    }

    void setTypeOfMeal(string typeOfMeal) {
        this->typeOfMeal = typeOfMeal;
    }

    void setPrice(int price) {
        this->price = price;
    }

    void displayList()
    {
        cout << "\t\t\t\t\t\tMeal Name --> " << mealName;
        cout << "\t\tPrice --> " << price << " Rs\n";
        cout << "\t\t\t\t\t\t---------";
        cout << "\n\t\t\t\t\t\tDescription --> " << description << "\n";
        cout << "\t\t\t\t\t\t<------------------------------------->\n\n";
    }
};

#endif