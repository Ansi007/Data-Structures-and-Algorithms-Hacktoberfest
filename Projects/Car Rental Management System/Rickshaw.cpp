#ifndef RICKSHAW
#define RICKSHAW
#include "Vehicle.cpp"
#include <cstring>
#include <iostream>

using namespace std;

class Rickshaw: public Vehicle{
    static inline int rate_per_km;
    static inline int count_of_Rickshaw;
public:
    Rickshaw(string number_plate, string color, string driver_name, string type_of_vehicle, int model_no, int seating_capacity, bool is_Booked, int rate_per_km):Vehicle(number_plate, color, driver_name, type_of_vehicle, model_no, seating_capacity, is_Booked){
        count_of_Rickshaw++;
        this->rate_per_km=rate_per_km;
    }

    void writeInFile(ostream& out){ // function overriding
        Vehicle::writeInFile(out);
        out << ',' << rate_per_km;
        out << ',' << count_of_Rickshaw;
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