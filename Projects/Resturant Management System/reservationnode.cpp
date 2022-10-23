#ifndef RESERVATIONNODE
#define RESERVATIONNODE
#include <iostream>
#include<string>

using namespace std;

class ReservationNode {
public:
    int noofpeople ;
    string name;
    ReservationNode *next;
    ReservationNode () {} ;
    ReservationNode (string n, int noofpeople , ReservationNode *N=NULL) {
        name = n ;
        this->noofpeople = noofpeople ;
        next = N;
    }

};

#endif