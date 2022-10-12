#include "reservationnode.cpp"
#ifndef LINKEDLISTRESERVATION
#define LINKEDLISTRESERVATION
#include <iostream>

using namespace std;


class RLinkedList {
public:
	ReservationNode *Head;
	ReservationNode *Tail;
	

	RLinkedList () {
		Head = Tail = 0;
	}
	
	void addtotail(string name , int people) {
		if (Tail != 0) {
			Tail->next = new ReservationNode (name, people) ;
			Tail = Tail->next ;
		}
		else Head = Tail = new ReservationNode (name, people) ;
	}

	void delete_reservation(string n) {
		ReservationNode *temp = Head ;
		ReservationNode *prev;
		while (temp != NULL) {
			if (Head->name == n) Head = Head->next ;
			else if (temp->name == n) {
				prev->next = temp->next ;
				break;
			}
			prev = temp ;
			temp = temp->next ;
		}

	}
	
	void print() {
		ReservationNode *temp = Head;
		string name_str = "Name: " ;
		string people = "No of people: " ;
		cout << setw(98)  << "_________________________________________________________\n" ;
        cout << setw(40) << '|' << setw(58) << '|' << endl ;
		cout << setw(40) << '|' << setw(40) << "All the reservations are " << setw(18) << '|' << endl;
		cout << setw(99)  << "|_________________________________________________________|\n" ;
		while (temp!= NULL) {
			cout << setw(40) << '|' << setw(2 + name_str.size()) << name_str << setw(19 - name_str.size()) << '|' << setw(10 + temp->name.size()) << temp->name << setw(27 - temp->name.size()) << '|' <<  endl ;
			cout << setw(40) << '|' << setw(2 + people.size()) << people  << setw(19 - people.size()) << '|' << setw(11) << temp->noofpeople << setw(26) << '|' << endl ;
			cout << setw(99)  << "|_________________________________________________________|\n" ;
			temp = temp->next ;
		}	
	}
		 
};

#endif	
