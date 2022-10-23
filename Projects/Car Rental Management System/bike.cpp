#ifndef BIKE
#define BIKE
#include <iostream>
#include <cstring>
#include "Vehicle.cpp"

using namespace std;

class Bike: public Vehicle{
    /*Static data members was creating a problem when used in multiple files i.e Multiple child classes with same name
     error says multiple definitions of static variable inline saves us from this problem and restricts reappearance */
    static inline int rate_per_km = 0;
    static inline int count_of_bikes = 0;
public:
    Bike(string number_plate, string color, string driver_name, string type_of_vehicle, int model_no, int seating_capacity, bool is_Booked, int rate_per_km):Vehicle(number_plate, color, driver_name, type_of_vehicle, model_no, seating_capacity, is_Booked){
        count_of_bikes++;
        this->rate_per_km=rate_per_km;
    }
    void writeInFile(ostream& out){ // function overriding
        Vehicle::writeInFile(out);
        out << ',' << rate_per_km;
        out << ',' << count_of_bikes;
        out << ',' << endl;
    }
    static int getRate(){
        return rate_per_km;
    }
    static void Change_Rates(int rate){
        rate_per_km=rate;
    }
};

#endif