#include "linkedlist.cpp"
#include "reservationnode.cpp"
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <iomanip>
#ifndef MENU
#define MENU

using namespace std;

class Customer {

    LinkedList menu;
    int bill ;

    int countdigit(int n) {
            int count = 0;
            while (n != 0) {
                n = n / 10;
                count++;
            }
            return count;
        }
public:
    Customer () {
        int i = -1;
        int price ;
        string dish ;
        ifstream menu_file;
        menu_file.open("menu2.csv") ;
        string line , word;
        while (menu_file.good()) {
            getline(menu_file, line);
            stringstream s(line);
            while (getline(s, word, ',')) {
                if (i >= 1 and i % 2 == 0) {
                    price = atoi(word.c_str()) ;
                }
                
                else if (i >= 1 and i % 2 != 0) dish = word ;
                if (i >= 1 and i % 2 == 0) 
                    menu.addtotail(dish, price) ;
                
                i++ ; 
                
            }

        }
    }

    int get_bill() { return bill ;}

    

    void display_menu() {
        menu.print("MENU");    
    }

    void kitchen_order_tickets(LinkedList l) {
        string statement = "Total Bill " ;
        ofstream order_file ;
        order_file.open("order.csv", ios_base::app) ;
        int sum = 0;
        MenuNode *temp = l.Head;
        cout << endl ;
        cout << setw(90) << "Thankyou for ordering at Chinese Hub\n" ;
        cout << setw(80) << "Your invoice is\n\n" ;
        l.print("YOUR ORDER");
        order_file << "Order" << endl ;

        while (temp!=NULL) {
            order_file << temp->name << ',' << temp->data << endl ;
            sum += temp->data ;
            temp = temp->next ;
        }
        sum = bill ;
        int count = countdigit(bill) ;
        cout << setw(40) << '|' << setw(58) << '|' << endl ;
        cout <<  setw(41) << "| " << statement << setw(49- statement.size()) << "Rs." << bill << setw(8-count) << '|'<< endl ;
        cout << setw(99)  << "|_________________________________________________________|\n" ;

    }


    void payment(int bill){
        int amount ;
        cout << "\nEnter the amount you have to pay\n" ;
        cin >> amount ;
        if (amount == bill) cout << endl << setw(80) << "Thankyou for the payment!" ;
        else if (amount > bill) {
            int balance = amount - bill ;
            cout << setw(75) << "Your balance is Rs. " << balance << endl ;
            cout << setw(80) << " Thankyou for the payment!\n" ;
        }
        else {
            int remaining = bill - amount ;
            cout << "Pay Rs. " << remaining << " more\n";
            payment(remaining) ;
        }
    }

    void tip_management() {
        int status , amount ;
        bool tip = false ;

        while (!tip) {
            cout << "\n\nEnter 1 if you want to give some tip. Else enter 0\n" ;
            cin.sync() ;
            cin.clear() ;
            cin >> status ;
            if (status == 1) {
            cout << "Enter tip amount\n" ;
            cin.sync() ;
            cin.clear() ;
            cin >> amount ;
            cout << endl << setw(55) << "Rs. " << amount << " handed over to respective waitor\n" ;
            tip = true ;
        }
            if (status == 0||status==1) tip = true ;
            else  cout << "Enter valid number\n" ;
        }
        
        
    }

    void customer_feedback() {
        ofstream feedback_file ;
        feedback_file.open("feedback.csv", ios_base::app) ;
        string name , email , feedback;
        cout << endl ;
        cout << "Kindly give feedback\n" ;
        cout << "Name: " ;
        cin.clear() ;
        cin.sync() ;
        getline(cin , name) ;
        cout << "\nEmail: " ;
        getline(cin , email) ;
        cout << "\nHow was the food?(One line feedback) " ;
        getline(cin ,feedback) ;
        feedback_file << name <<',' << email <<',' << feedback << endl ;
        display_feedback(name , email , feedback) ;
        
    }

    void display_feedback(string name , string email ,string feedback) {
        string name_str = "Customer's Name" ;
        string email_str = "Email" ;
        string feedbackStr = "Feedback" ;
        cout << setw(98)  << "_________________________________________________________\n" ;
        cout << setw(40) << '|' << setw(58) << '|' << endl ;
        cout << setw(40) << '|' << setw(35) << " Customer Feedback Is " << setw(23) << '|' << endl ;
        cout << setw(99)  << "|_________________________________________________________|\n" ;
        cout << setw(40) << '|' << setw(6) << name_str << setw(20 - name_str.size()) << '|' << setw(10 + name.size()) << name <<  setw(28 - name.size()) << '|' << endl ;
        cout << setw(40) << '|' << setw(5) << email_str << setw(20 - email_str.size()) << '|' << setw(10 + email.size()) << email <<  setw(28 - email.size()) << '|' << endl ;
        cout << setw(40) << '|' << setw(5) << feedbackStr << setw(20 - feedbackStr.size()) << '|' << setw(3 + feedback.size()) << feedback <<  setw(35 - feedback.size()) << '|' << endl ;
        cout << setw(99)  << "|_________________________________________________________|\n" ;
    }

    LinkedList place_order() {
        cout << "\n" ;
        LinkedList order ;
        MenuNode *t;
        bool order_state = true , item_found;
        string dish;
        int status ;
        int i , price = 0 , temp;
        bool done = false ;
        while (order_state) {
            item_found = false ;
            done = false ;
            cout << "What do you want to order?\n" ;
            cin.clear() ;
            cin.sync() ;
            getline(cin, dish) ;
            t = menu.Head ;
            while (t != NULL) {
                if (dish == t->name) {
                    item_found = true;
                    order.addtotail(t->name, t->data) ;
                    price += t->data ;
                    break ;
                }
                t = t->next;
            }
            if (!item_found) cout << "Sorry we don't have this item\n" ;
            while (!done) {
                cout << "Enter 1 if you want to order further. Enter 2 if you are done with order.\n" ;
                cin.clear() ;
                cin.sync() ;
                cin >> status ;
                if (status == 2)order_state = false;
                if (status == 1 or status == 2) done = true ;
                else cout << "Please enter valid number\n" ;
            }
            
            
        }
        bill = price ;
        return order;
    }

    ReservationNode* table_reservation() {
        string name ;
        int persons ;
        bool valid_person = false ;
        cout << "Enter name under which you want to reserve the table: " ;
        cin.clear() ;
        cin.sync() ;
        getline(cin , name) ;
        while (!valid_person) {
        cout << "\nEnter no. of persons in digits (Max 30 people allowed per reservation): " ;
        cin.clear() ;
        cin.sync() ;
        cin >> persons ;
        if (persons > 0 and persons < 31) valid_person = true ; 
        else cout << "Enter valid no of persons\n" ;
        }
        cout << endl; 
        cout << setw(70) << "Table Reserved for " << persons << " persons\n" ;
        ReservationNode *temp ;
        temp = new ReservationNode(name , persons) ;
        return temp ;

    }
};

#endif