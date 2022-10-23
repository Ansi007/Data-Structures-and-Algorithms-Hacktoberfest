#ifndef USER
#define USER

#include<iostream>
#include<cstring>
#include "List.cpp"
#include "Meal.cpp"
#include "Entity.cpp"

using namespace std;

class User : public Entity{
    string address;
    int wallet;
    List<Meal>* cart;
public:
    User(string name, string id, string password, string address, int wallet) : Entity(name, id, password)
    {
        this->address = address;
        this->wallet = wallet;
        cart = new List<Meal>;
    }

    int getWallet() const{
        return wallet;
    }

    string getAddress() const{
        return address;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    void addToWallet(int amount)
    {
        wallet = wallet + amount;
    }

    void addToCart(Meal* meal)
    {
        cart->addNode(meal);
    }

    void showCart()
    {
        if(cart->isEmpty())
            cout << "\n\n\t\t\t\t\t\t\t<-----------------Cart is Empty----------------->\n\n";
        else
            cart->viewCart();
    }

    void emptyCart()
    {
        delete cart;
        cart = new List<Meal>;
    }

    int calculatePriceOfCart()
    {
        return cart->calcPrice();
    }

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
        out << address << seperator;
        out << wallet << seperator;
        out << endl;

        return out;
    }
};

#endif