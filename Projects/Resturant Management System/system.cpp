#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "circularqueue.cpp"
#include "menu.cpp"
#include "linkedlistreservation.cpp"
#include "employee.cpp"
#include "manager.cpp"

class System
{
    Queue<LinkedList> q1;
    Customer order;
    RLinkedList reserve;
    Employee e;
    Manager m;
    LinkedList invoice ;

public:

    System() 
    {
        int i = 0 ;
        string line , word , name;
        int people ;
        ifstream file ;
        file.open("reservation.csv") ;
        if (file) 
        {
            while (file.good()) 
            {
                getline(file, line); 
                stringstream s(line);
                while (getline(s, word, ',')) 
                {
                    if (i % 2 == 0) name = word ;
                    else people = atoi(word.c_str()) ;
                    i++ ;
                    if (i % 2 == 0) reserve.addtotail(name , people) ;
                }
            }
        }
            
        
    }

    void write_reservation() {
        ofstream reservation_file ;
        reservation_file.open("reservation.csv") ;
        ReservationNode *temp = reserve.Head ;
        while (temp != NULL) {
            reservation_file << temp->name <<',' << temp->noofpeople ;
            temp = temp->next ;
        }
    }

    void queue_order()
    {
        order.display_menu();
        invoice = order.place_order();
        q1.enqueue(invoice);
        m.inventory_management(invoice) ;
        m.refill_inventory() ;
    }


    void get_inventory()
    {
        m.check_inventory();
    }

    void get_order()
    {
        LinkedList deq;
        if (!q1.isempty()) {
            deq = q1.dequeue();
            cout << setw(60) << "Enjoy your order!\n";
            order.kitchen_order_tickets(deq);
            int bill ;
            bill = order.get_bill();
            order.payment(bill);
            order.tip_management() ;
            Sleep(1000) ;
            system("cls") ;
            order.customer_feedback() ;
        }
        else cout << "No order placed\n" ;
       
    }

    void do_reservations()
    {
        ofstream reservation_file ;
        reservation_file.open("reservation.csv", ios_base:: app) ;
        ReservationNode *res;
        res = order.table_reservation();
        reserve.addtotail(res->name, res->noofpeople);
        reservation_file << res->name << ',' << res->noofpeople << endl ;
    }

    void print_all_reservations()
    {
        reserve.print();
    }

    void get_reservation()
    {
        string name;
        bool reservation_found = false;
        cout << "Under what name have you reserved the table? ";
        cin.clear();
        cin.sync();
        getline(cin, name);
        ReservationNode *temp = reserve.Head;
        while (temp != NULL)
        {
            if (name == temp->name)
            {
                reserve.delete_reservation(name);
                reservation_found = true;
                break;
            }
            temp = temp->next;
        }
        if (!reservation_found)
            cout << "Sorry no reservation found with this name\n";
        else 
        {
            write_reservation() ;
            Sleep(1000) ;
            system("cls") ;
            queue_order();
        }

            
        
    }

    void employee_scheduling()
    {
        bool res;
        ifstream attendance;
        vector<char> status;
        cout << "Enter P if employee is present. Enter any character if employee is on leave\n";
        attendance.open("employee_attendance.csv");
        string line, word;
        cin.clear();
        cin.sync();
        getline(attendance, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            res = e.attendance_per_employee(word);
            if (res)
                status.push_back('P');
            else
                status.push_back('A');
        }
        attendance.close();
        ofstream attendance_status;
        attendance_status.open("employee_attendance.csv", ios::app);
        for (int i = 0; i < status.size(); i++)
            attendance_status << status[i] << ',';
        attendance_status << endl;
    }

    void employee_salary()
    {
        cout << "Check your monthly salary\n" ;
        string employee_name;
        cout << "Enter your name: ";
        cin.sync();
        cin.clear();
        getline(cin, employee_name);
        e.employee_payment(employee_name);
    }
};



int main()
{
    
    System s;
    cout << setw(77) << "WELCOME TO CHINESE HUB\n" ;
    int choice;
    do {
        cout << setw(98)  << "_________________________________________________________\n" ;
        cout << setw(40) << '|' << setw(58) << '|' << endl ;
        cout << setw(40) << '|' << setw(40) << "Enter 1 if you're a Customer" << setw(18) << '|' <<  endl ;
        cout << setw(40) << '|' << setw(41) << "Enter 2 if you're an Employee"<<  setw(17) << '|' << endl ;
        cout << setw(40) << '|' << setw(37) << "Enter 3 if you're Manager" << setw(21) << '|' << endl ; 
        cout << setw(40) << '|' << setw(40) << "Enter -1 if you want to Exit" << setw(18) << '|' << endl ;
        cout << setw(99)  << "|_________________________________________________________|\n" ;
    
            cin >>choice;
        if (choice == 1)
        {
            int custchoice;
            do
            {

                 cout << setw(98)  << "_________________________________________________________\n" ;
                cout << setw(40) << '|' << setw(58) << '|' << endl ;
                cout << setw(40) << '|' << setw(48) << "Enter 1 if you want to reserve a table" << setw(10) << '|' << setw(40) << endl ;
                cout << setw(40) << '|' << setw(52) <<"Enter 2 if you have already booked a table" << setw(6) << '|' << setw(40) << endl ;
                cout << setw(40) << '|' << setw(40) <<"Enter 3 if you want to dine in" << setw(18) << '|' << setw(40) << endl ;
                cout << setw(40) << '|' << setw(47) <<"Enter 4 if you want to get your order" << setw(11) << '|' << setw(40) << endl ;
                cout << setw(40) << '|' << setw(38) << "Enter -1 if you want to Exit" << setw(20) << '|' << setw(40) << endl;
                cout << setw(99)  << "|_________________________________________________________|\n" ;       
                cin >> custchoice;
                if (custchoice == 1)
                {
                    s.do_reservations();
                }
                else if (custchoice == 2)
                {
                    s.get_reservation();
                }
                else if (custchoice == 3)
                {
                    s.queue_order();
                }
                else if (custchoice == 4)
                {
                    s.get_order();
                }
                else if (custchoice == -1)
                {
                    cout << "You exited the Customer Portal\n";
                    Sleep(2000) ;
                    system("cls") ;
                }
                else
                {
                    cout << "Please Enter a valid choice";
                } 
                Sleep(2000) ;
                system("cls") ;
            } while (custchoice != -1) ;
            
        }
        else if (choice == 2)
        {
            int empchoice ;
            do {
                cout << setw(98)  << "_________________________________________________________\n" ;
                cout << setw(40) << '|' << setw(58) << '|' << endl ;
                cout << setw(40) << '|' << setw(40) << "Enter 1 to check salary" << setw(18) << '|' <<  endl ;
                cout << setw(40) << '|' << setw(45) << "Enter -1 if you want to exit" << setw(13) << '|' << endl ;
                cout << setw(99)  << "|_________________________________________________________|\n" ;
                cin >> empchoice ;
                if (empchoice == 1) {
                    s.employee_salary(); 
                    Sleep(2000) ;
                    system("cls") ;

                }
                else if (empchoice == -1) {
                    cout << "You exited the employee portal\n" ;
                    Sleep(2000) ;
                    system("cls") ;
                }
                else cout << "Enter valid number\n" ;
                
            } while (empchoice != -1) ;
           
        }
        
        else if (choice == 3)
        {
            int mngrchoice;
            do {
                cout << setw(98)  << "_________________________________________________________\n" ;
                cout << setw(40) << '|' << setw(58) << '|' << endl ;
                cout << setw(40) << '|' << setw(40) << "  Enter 1 if you want to take attendance of employees" << setw(5) << '|' <<  endl ;
                cout << setw(40) << '|' << setw(40) << "Enter 2 if you want to check inventory" << setw(18) << '|' <<  endl;
                cout << setw(40) << '|' << setw(30) << "Enter -1 if you want to exit" << setw(28) << '|' << endl ;
                cout << setw(99)  << "|_________________________________________________________|\n" ;

                cin >> mngrchoice;
                if (mngrchoice == 1)
                {
                    s.employee_scheduling();
                    Sleep(2000) ;
                    system("cls") ;
                }
                else if (mngrchoice == 2)
                {
                    s.get_inventory();
                    // Sleep(6000) ;
                    // system("cls") ;
                }
                else if (mngrchoice == -1) 
                {
                    cout << "You exited manager portal\n" ;
                    Sleep(1000) ;
                    system("cls") ;
                    
                }
                else
                {
                    cout << "Please Enter a valid choice";
                }
                
            } while ( mngrchoice != -1) ;
        }
        
        else if (choice == -1)
        {
            continue;
        }
        else
        {
            cout << "Please Enter a valid choice";
        }
        
    } while (choice != -1) ;
     cout << "You exited the Main Portal";
}
