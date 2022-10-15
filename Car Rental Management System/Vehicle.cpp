#ifndef VEHICLE
#define VEHICLE
#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle{
    string color;
    string driver_name;
    int model_no;
    int seating_capacity;
    bool is_Booked;

public:
    static inline int count_of_Vehicles=0;
    string number_plate;
    string type_of_vehicle;
    Vehicle(string number_plate, string color, string driver_name, string type_of_vehicle, int model_no, int seating_capacity, bool is_Booked){
        this->number_plate=number_plate;
        this->color=color;
        this->driver_name=driver_name;
        this->type_of_vehicle=type_of_vehicle;
        this->model_no=model_no;
        this->seating_capacity=seating_capacity;
        this->is_Booked=is_Booked;
        count_of_Vehicles++;
    }
    /*Made parent class pointer child class object, so we need to make the functions virtual so that the parent
     forces to call the child class function first it will print all the data members of vehicle class since it
     will call the parent first and then go for child and print their data members. Used this function in script class*/

    virtual void writeInFile(ostream& out){
        out << type_of_vehicle << ',';
        out << number_plate << ',';
        out << color << ',';
        out << driver_name << ',';
        out << model_no << ',';
        out << seating_capacity << ',';
        out << is_Booked;
    }

    int get_No_of_Vehicles(){
        return count_of_Vehicles;
    }

    int get_is_booked(){
        return is_Booked;
    }

    string get_driver_name(){
        return driver_name;
    }

    void booked(){
        is_Booked=1;
    }

    void cancel_booking(){
        is_Booked=0;
    }

    friend ostream& operator << (ostream& out, Vehicle& vehicle){
        out  << setw(10) << vehicle.type_of_vehicle << "\t" << vehicle.number_plate << "\t\t" << vehicle.color << "\t\t" << vehicle.driver_name << "\t\t" << vehicle.model_no << "\t\t" << vehicle.seating_capacity << "\t\t" << vehicle.is_Booked << endl;
        return out;
    }
};


class Vehicle_Node{
public:
    Vehicle *vehicle;
    Vehicle_Node *next;
    Vehicle_Node(Vehicle *vehicle, Vehicle_Node *next=NULL){
        this->vehicle=vehicle;
        this->next=next;
    }
};

class List_of_Vehicles{
    Vehicle_Node *head;
    Vehicle_Node *tail;
public:
    List_of_Vehicles(){
        head=NULL;
        tail=NULL;
    }
    void Add_Vehicle(Vehicle *vehicle) {
        if(tail!=NULL){
            tail->next=new Vehicle_Node(vehicle);
            tail=tail->next;
        }
        else{
            head=tail=new Vehicle_Node(vehicle);
        }
    }


    bool Number_Plate_Validation(string numberplate){ //validates if this numberplate exits or not
        Vehicle_Node *i;
        for(i=head; i!=NULL; i=i->next){
            if(i->vehicle->number_plate==numberplate)
                return true; //number_plate already exits
        }
        return false;
    }


    void print_object(string num){ //will print the object with matched number plate
        Vehicle_Node *i;
        for(i=head; i!=NULL; i=i->next){
            if(i->vehicle->number_plate==num)
                cout << *i->vehicle;
        }
    }

    void show_Available_rides(string v1, string v2, string v3){ //incity outcity rides displayer
        //we will match aur vehicles and show data to user
        Vehicle_Node *i;
        for(i=head; i!=NULL; i=i->next){
            if(i->vehicle->type_of_vehicle==v1 || i->vehicle->type_of_vehicle==v2 || i->vehicle->type_of_vehicle==v3)
                cout << *i->vehicle << endl;
        }
    }

    void Delete_From_Head(){
        Vehicle_Node* temp=head;
        if(head==tail)
            head=tail=NULL;
        else{
            head=head->next;
            delete temp;
        }
    }


    void Delete_From_Tail(){
        Vehicle_Node *i;
        if(head==tail)
            head=tail=NULL;
        else{
            for(i=head; i->next!=tail; i=i->next);
            delete tail;
            tail=i;
            tail->next=NULL;
        }
    }

    void delete_vehicle(string NumberPlate){
       Vehicle_Node *i;
       if(head->vehicle->number_plate==NumberPlate){  //deleting first node
           Delete_From_Head();
           return;
       }

       else{
           for(i=head; i->next!=NULL && i->next->vehicle->number_plate!=NumberPlate; i=i->next);
           if(i->next==tail){
               Delete_From_Tail(); //deleting last node
               return;
           }
           else{
               Vehicle_Node *temp = i->next;
               i->next=i->next->next; //deleting center node
               delete temp;
               return;
           }
       }
    }

    void File_list_writing(ostream &out){ //file writing used in destructor
        for(Vehicle_Node *i=head;i!=NULL;i=i->next){
            i->vehicle->writeInFile(out);
        }
    }

    void print_Vehicle(){ // will print all vehicles
        for(Vehicle_Node *i=head;i!=NULL;i=i->next){
            cout << *i->vehicle; //*dereference operation (was printing address before this
        }
    }

    void print_nearby_rides(){ //will print only unbooked vehicles
        for(Vehicle_Node *i=head;i!=NULL;i=i->next){
            if(i->vehicle->get_is_booked()!=1)
                cout << *i->vehicle;
        }
    }

    void show_Type_of_vehicle_rides(string vehicle){ //will display only a particular type of vehicle e.g show specification of car
        //we will match aur type of vehicle and show data to user
        Vehicle_Node *i;
        for(i=head; i!=NULL; i=i->next){
            if(i->vehicle->type_of_vehicle==vehicle)
                cout << *i->vehicle << endl;
        }
    }

    string is_Booked(string num){ //if ride is booked it will assign that ride is_booked data member 1
        Vehicle_Node *i;
        for(i=head; i->vehicle->number_plate!=num; i=i->next);
        i->vehicle->booked();
        return i->vehicle->type_of_vehicle;
    }

    string get_driver(string num_plate){
        Vehicle_Node *i;
        for(i=head; i->vehicle->number_plate!=num_plate; i=i->next);
        return i->vehicle->get_driver_name();
    }

    void cancel_booking(string num){ //incase user havent paid his booking will be cancelled
        Vehicle_Node *i;
        for(i=head; i->vehicle->number_plate!=num; i=i->next);
        i->vehicle->cancel_booking();
    }
};

#endif
