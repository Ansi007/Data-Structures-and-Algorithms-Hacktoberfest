#ifndef USER
#define USER
#include "Person.cpp"
#include <cstring>
#include <iostream>
#include <process.h>

using namespace std;

class User: public Person{
    string invoice; //this string will store a complete invoice
    int wallet;

public:
    static inline int count_of_Users=0;
    User(string Name, string id, string password, int wallet): Person(Name, id, password){
        this->wallet=wallet;
        count_of_Users++;
    }

    int get_wallet(){
        return wallet;
    }

    void edit_wallet(int wallet){
        this->wallet=this->wallet+wallet;
    }

    string get_pass(){
        return password;
    }

    string get_name(){
        return name;
    }

    string get_id(){
        return id;
    }

    void generate_invoice(string type_of_vehicle, string driver_name, string number_plate, int km_travelled, int fare){
        int tax=(5*fare)/100;
        invoice += "------------------------INVOICE------------------------\n";
        invoice += "Type of Ride: ";
        invoice += type_of_vehicle;
        invoice += "\n\nDriver Name: ";
        invoice += driver_name;
        invoice += "\n\nNumber Plate: ";
        invoice += number_plate;
        invoice += "\n\nkm Travelled: ";
        invoice += to_string(km_travelled);
        invoice += "\n\nFare: ";
        invoice += to_string(fare);
        invoice += "\n\nTax(5%)";
        invoice += to_string(tax);
        invoice += "\n\nTotal Amount paid: ";
        invoice += to_string(fare+tax);
        invoice += "\n\nThank You for Riding with us :)\n\n";
        invoice += "------------------------------------------------------------\n";
    }

    string get_invoice(){
        return invoice;
    }

    friend ostream& operator << (ostream& out, User& user){
        out << user.name << ',' << user.id << ',' << user.password << ',' << user.wallet << ',' << endl;
        return out;
    }

};

class User_Node{
public:
    User *user; //data of User node that is object of user
    User_Node *next;
    User_Node(User *user, User_Node *next=NULL){
        this->user=user;
        this->next=next;
    }
};

class List_of_User{
protected:
    User_Node *head;
    User_Node *tail;
public:
    List_of_User(){
        head=NULL;
        tail=NULL;
    }
    void Add_User(User *user) {
        if(tail!=NULL){
            tail->next=new User_Node(user);
            tail=tail->next;
        }
       else{
            head=tail=new User_Node(user);
       }
    }

    User* User_Validation(string identification, string pass) {
        for (User_Node *i=head; i!=NULL; i=i->next) {
            if (i->user->get_id() == identification && i->user->get_pass() == pass)
                return i->user;
        }
        return NULL;
    }

    bool ID_exist(string identification){
        for(User_Node *i=head;i!=NULL;i=i->next){
            if(i->user->get_id()==identification)
                return true;
        }
        return false;
    }

    void User_file_writing(ostream &out){
        for(User_Node *i=head;i!=NULL;i=i->next){
            out << *i->user;
        }
    }

    void print_user(){
        for(User_Node *i=head;i!=NULL;i=i->next){
            cout << *i->user; //*dereference operation (was printing address before this)
        }
    }
};

#endif