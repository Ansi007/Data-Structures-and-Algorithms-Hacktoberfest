#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#ifndef MANAGER
#define MANAGER
#include "linkedlist.cpp"
using namespace std;

class Manager {
LinkedList servings ;
public:
    Manager() {
        int i = 0 ;
        ifstream inventory_file;
        inventory_file.open("inventory.csv") ;
        string line , word, name;
        int noofservings ;
        while (inventory_file.good()) {
            getline(inventory_file, line); 
            stringstream s(line);
            while (getline(s, word, ',')) {
                if (i % 2 == 0) name = word ;
                else noofservings = atoi(word.c_str()) ;
                i++ ;
                if (i % 2 == 0) servings.addtotail(name , noofservings) ;
            }
        }
    }


    void inventory_management(LinkedList order) {
        MenuNode *temp = order.Head ;
        MenuNode *serve ;
        while (temp != NULL) {
            serve = servings.Head ;
            while (serve!= NULL) {
                if (temp->name == serve->name)                  
                    serve->data = serve->data - 1 ;
                serve = serve->next ;
            }
            temp = temp ->next ;
        }
        write_in_file() ;
    }

    void write_in_file() {
        ofstream updated_file ;
        updated_file.open("inventory.csv") ;
        MenuNode *serve = servings.Head ;
        while (serve!=NULL) {
            updated_file << serve->name << ',' << serve->data << endl ;
            serve = serve->next ;
        }
    }

    void refill_inventory() {
        MenuNode *serve = servings.Head ;
        while (serve!= NULL) {
            if (serve->data == 0) {
                serve->data = 15 ;
            }
            serve = serve->next ;
        }
        write_in_file() ;
    }

    void check_inventory() {
        servings.print_servings() ;
        
    }
};

#endif