#ifndef EMPLOYEE
#define EMPLOYEE
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "linkedlist.cpp"
using namespace std;

class Employee {

LinkedList l ;

public:

    Employee () {
        int i = 0 ;
        ifstream salary;
        salary.open("employee_salary.csv") ;
        string line , word, name;
        int pay ;
        while (salary.good()) {
            getline(salary, line); 
            stringstream s(line);
            while (getline(s, word, ',')) {
                if (i % 2 == 0) name = word ;
                else pay = atoi(word.c_str()) ;
                i++ ;
                if (i % 2 == 0) l.addtotail(name , pay) ;
            }
        }
    }

    bool attendance_per_employee(string employee_name) {
        char status ;
        cout << employee_name << ' ' ;
        cin >> status ;
        if (status == 'P') return true ;
        return false ;
    }


    void employee_payment(string name) {
        MenuNode *temp = l.Head ;
        bool employee_found = false ; 
        while (temp != NULL) {
            if (name == temp->name) {
                cout << setw(58) << "Monthly salary of " << name << " is Rs." << temp->data << endl ;
                employee_found = true ;
                break ;
            }
            temp = temp->next ;
        }
        if (!employee_found) cout << name << " is not employee at this resturant!\n" ;
    }

    



};

#endif