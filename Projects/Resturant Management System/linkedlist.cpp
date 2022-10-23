#include "menu_node.cpp"
#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <iomanip>

using namespace std;


class LinkedList {
public:
	MenuNode *Head;
	MenuNode *Tail;
	

	LinkedList () {
		Head = Tail = 0;
	}
	
	void addtotail(string dish , int price) {
		if (Tail != 0) {
			Tail->next = new MenuNode (dish , price) ;
			Tail = Tail->next ;
		}
		else Head = Tail = new MenuNode (dish , price) ;
	}
	
	// void print() {
	// 	MenuNode *temp = Head;
	// 	string menu = "MENU" ;
	// 	cout << setw(98)  << "_________________________________________________________\n" ;
	// 	cout <<  endl ;
	// 	cout << setw(65) <<menu << setw(31 - menu.size()) << "PRICE" << endl ;
	// 	cout << setw(98)  << "_________________________________________________________\n" ;
	// 	cout << endl ;
	// 	while (temp!= NULL) {
	// 		cout << setw(40) << '|' << setw(30) << temp->name << setw(20) << "Rs." << temp->data << setw(5) << '|' << endl ;
	// 		temp = temp->next ;
	// 	}
	// 	cout << setw(98)  << "_________________________________________________________\n" ;
	// }

	void print_servings () {
		MenuNode *temp = Head;
		cout << setw(98)  << "_________________________________________________________\n" ;
		cout << setw(40) << '|' << setw(58) << '|' << endl ;
		cout << setw(40) << '|' << setw(15) << "Dish " << setw(37) << "NO OF SERVINGS" << setw(6) << '|' << endl ;
		cout << setw(99)  << "|_________________________________________________________|\n" ;
		cout << setw(40) << '|' << setw(58) << '|' << endl ;
		while (temp!= NULL) {
			cout << setw(41) << "| " <<  setw(5 + temp->name.size()) << temp->name << setw(47 - temp->name.size()) << temp->data << setw(5) << '|' << endl ;
			temp = temp->next ;
		}
		cout << setw(99)  << "|_________________________________________________________|\n" ;	
	}

	void print(string word) {
		MenuNode *temp = Head;
		cout << setw(98)  << "_________________________________________________________\n" ;
		cout << setw(40) << '|' << setw(58) << '|' << endl ;
		cout << setw(40) << '|' << setw(5 + word.size()) << word << setw(47 - word.size()) << "PRICE" << setw(6) << '|' << endl ;
		cout << setw(99)  << "|_________________________________________________________|\n" ;
		cout << setw(40) << '|' << setw(58) << '|' << endl ;
		while (temp!= NULL) {
			cout << setw(41) << "| " <<  temp->name << setw(49- temp->name.size()) << "Rs." << temp->data << setw(5) << '|' << endl ;
			temp = temp->next ;
		}
		cout << setw(99)  << "|_________________________________________________________|\n" ;
	}


	void print_dishes() {
		MenuNode *temp = Head;
		cout << "Ordered dishes are \n" ;
		while (temp!= NULL) {
			cout << temp->name << endl ;
			temp = temp->next ;
		}	
	}

		 
};

#endif	
