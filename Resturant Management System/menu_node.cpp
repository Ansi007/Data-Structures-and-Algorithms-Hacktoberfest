#ifndef MENU_NODE
#define MENU_NODE
#include <iostream>
#include<string>

using namespace std;

class MenuNode {
public:
    int data ;
    string name;
    MenuNode *next;


    MenuNode (string n , int data , MenuNode *N=NULL) {
        name = n ;
        this->data = data;
        next = N;
    }

};

#endif