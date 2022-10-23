#ifndef SYSTEM
#define SYSTEM
#include <iostream>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <process.h>
#include <fstream>
#include "Admin.cpp"
#include "User.cpp"
#include "Vehicle.cpp"
#include "bike.cpp"
#include "Bus.cpp"
#include "Car.cpp"
#include "Coach.cpp"
#include "Rickshaw.cpp"

using namespace std;

class System {
    Admin *admin;
    List_of_Vehicles vehicles_list;
    List_of_User list;
    int no_of_vehicles;
    int numOfUsers;
    User *logged_in_user; //all the functions will be executed against the logged-in user
    //when the user will sign out pointer will turn into null

public:
    //This will remove commas if accidently entered to input
    void removeComma(string &s)
    {
        string temp;
        for(int i = 0; i<s.length(); i++)
            if(s[i] != ',')
                temp.push_back(s[i]);
        s = temp;
    }
    void Caps_to_Small(string &s){
        for(int i=0;i<s.size();i++)
            if(s[i]>=65 && s[i]<=90)
                s[i]=s[i]+32;
        removeComma(s);
    }

    System(){
        /* *******Admin User File opening****** */
        fstream Admin_User_data;
        Admin_User_data.open("Users.csv", ios::in);
        if(Admin_User_data.fail()) { //if file does not open for certain reasons
            cout << "\n\t\t\t\t\t\tUser or Admin File cannot be open. Terminating Program......" << endl;
            exit(1);
        }

        /* *******Admin Data Reading******* */
        string Name;
        string id;
        string password;
        getline(Admin_User_data, Name, ',');
        getline(Admin_User_data, id, ',');
        getline(Admin_User_data, password, ',');
        admin = new Admin(Name, id, password);
        // Data Reading from the file and passing to constructor done, admin Object Created Successfully

        /* *******User Data Reading******* */
        Admin_User_data >> numOfUsers;
        for (int i = 0; i < numOfUsers; i++) {
            Admin_User_data.ignore();
            getline(Admin_User_data, Name, ',');
            getline(Admin_User_data, id, ',');
            getline(Admin_User_data, password, ',');
            int wallet;
            Admin_User_data >> wallet;
            Admin_User_data.ignore();
            //Need to make a linked list of user
            User *user1 = new User(Name, id, password, wallet);
            list.Add_User(user1);
            // Data Reading from the file and passing to constructor done, user Object Created Successfully
        }
        Admin_User_data.close();


        /* **************Vehicle Data Reading************* */
        // List_of_Vehicles vehicles_list;
        fstream Vehicle_data;
        Vehicle_data.open("Vehicles.csv", ios::in);
        if (Vehicle_data.fail()) { //if file does not open for certain reasons
            cout << "\n\t\t\t\t\t\tVehicle data File cannot be open. Terminating Program......" << endl;
            exit(1);
        }

        string type_vehicle;
        string num_plate;
        string vehicle_color;
        string name_of_driver;
        string model;
        string seat_capacity;
        string booked;
        string rate;
        string count_of_each_vehicle;
        Vehicle_data >> no_of_vehicles;
        Vehicle *vehicle[30];
        Vehicle_data.ignore();
        for (int i = 0; i<no_of_vehicles; i++) {
            getline(Vehicle_data, type_vehicle, ',');
            Caps_to_Small(type_vehicle);
            getline(Vehicle_data, num_plate, ',');
            Caps_to_Small(num_plate);
            getline(Vehicle_data, vehicle_color, ',');
            Caps_to_Small(vehicle_color);
            getline(Vehicle_data, name_of_driver, ',');
            Caps_to_Small(name_of_driver);
            getline(Vehicle_data, model, ',');
            Caps_to_Small(model);
            getline(Vehicle_data, seat_capacity, ',');
            Caps_to_Small(seat_capacity);
            getline(Vehicle_data, booked, ',');
            Caps_to_Small(booked);
            getline(Vehicle_data, rate, ',');
            getline(Vehicle_data, count_of_each_vehicle, ',');
            Vehicle_data.ignore();
            if (type_vehicle == "bike")
                vehicle[i] = new Bike(num_plate, vehicle_color, name_of_driver, type_vehicle, stoi(model),
                                      stoi(seat_capacity), stoi(booked), stoi(rate));
            else if (type_vehicle == "car")
                vehicle[i] = new Car(num_plate, vehicle_color, name_of_driver, type_vehicle, stoi(model),
                                     stoi(seat_capacity), stoi(booked), stoi(rate));
            else if (type_vehicle == "rickshaw")
                vehicle[i] = new Rickshaw(num_plate, vehicle_color, name_of_driver, type_vehicle, stoi(model),
                                          stoi(seat_capacity), stoi(booked), stoi(rate));
            else if (type_vehicle == "bus")
                vehicle[i] = new Bus(num_plate, vehicle_color, name_of_driver, type_vehicle, stoi(model),
                                     stoi(seat_capacity), stoi(booked), stoi(rate));
            else if (type_vehicle == "coach")
                vehicle[i] = new Coach(num_plate, vehicle_color, name_of_driver, type_vehicle, stoi(model),
                                       stoi(seat_capacity), stoi(booked), stoi(rate));
            vehicles_list.Add_Vehicle(vehicle[i]);
        }

        //vehicles_list.print_Vehicle(); //Help to see the whole list of vehicles

        Vehicle_data.close();
        //Data Reading from the file and passing to constructor done, Vehicle Object Created Successfully

        /* ***********Actual Working System ********* */
        Print_Intro();
        Login_Menu();
        Print_Exit();
    }

    void Login_Menu() { //Only display menu

        int option = 0;
        while(option != 3){
            Print_Home();
            //This loop will go until user press 3
            cout << "                                  ____________________________________________________________\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                  Select a login Option                     |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[1]";
            cout << setw(30) << "Admin login                                    |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[2]";
            cout << setw(30) << left << "User login                                     |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[3]";
            cout << setw(30) << left << "Exit                                           |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |____________________________________________________________|";
            option = Login_Selection(); //call to menu selection
        }
    }

    int Login_Selection(){
        int option;
        cout <<"\n\n                                                      Select your Option: ";
        cin >> option;
        if(cin.fail() || option < 1 || option > 3) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            cin.ignore();
            return 0;
        }
        if(option == 1)
            Admin_Login();
        if(option == 2)
            User_Login_Signup();
        if(option == 3){
            cout << "Exiting...\n";
        }
        return option;
    }

    void Admin_Login(){
        string identification, password;
        do {
            Print_Admin();
            cin.ignore();
            cout << "\t\t\t\tAdmin Login\n";
            cout << "\t\tID: ";
            getline(cin, identification, '\n');
            Caps_to_Small(identification);
            cout << "\n\t\tPassword: ";
            getline(cin, password, '\n');
            Caps_to_Small(password);
            if (admin->Admin_Login(identification, password)) { //this will check if id is right or wrong
                Admin_Controls();
            }
            else {
                int num;
                cout << "                                  ____________________________________________________________\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Incorrect Username or ID!                     |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Access Denied :(                              |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Press any digit to Try Again!                 |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |                            OR                              |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Press 0 to return to Login Options            |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |____________________________________________________________|\n";
                cout << "\n\n\t\t\t\t\tChoose an option: ";
                cin >> num;
                if (!num)
                    Login_Menu();
            }
        } while (!admin->Admin_Login(identification, password));
    }

    void Admin_Controls() {
        int option = 0;
        while(option != 4) {
            Print_Admin();
            cout << "\n\n\t\t\t\t\t\tWelcome " << admin->Get_name() << " <'-'>\n\n";
            cout << "                                  ____________________________________________________________\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                  Select a function                         |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[1]";
            cout << setw(30) << "Add new driver                                 |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[2]";
            cout << setw(30) << left << "Remove existing driver                         |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[3]";
            cout << setw(30) << left << "Change per km rates                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[4]";
            cout << setw(30) << left << "Sign out                                       |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |____________________________________________________________|";
            option = Admin_Control_Selection();
        }
    }

    int Admin_Control_Selection(){ //will take option what admin wants to do
        int option;
        cout <<"\n\n                                                      Select your Option: ";
        cin >> option;
        if(cin.fail() || option < 1 || option > 4) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return 0;
        }
        if (option == 1)
            AddNewDriver();
        if(option == 2)
            Remove_Driver();
        if(option == 3)
            Change_rates_Details();
        if(option == 4)
            return Admin_sign_out();
        return 0;
    }

    bool Type_of_vehicle_validator(string vehicle){
        if(vehicle!="bike" && vehicle!="car" && vehicle!="rickshaw" && vehicle!="bus" && vehicle!="coach")
            return false;
        return true;
    }

    void AddNewDriver(){
        Vehicle *Add_vehicle;
        string vehicle;
        string num_plate;
        string colour;
        string driver;
        string modelNo;
        string seat_capacity;
        cin.ignore();
        do {
            Print_Admin();
            cout  << "\t\t\t\t ________________________________________________________________\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|                  Enter the following details:                  |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|                  Type of Vehicle can be                        |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|\t                 -Bike                                   |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|\t                 -Car                                    |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|\t                 -Rickshaw                               |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|\t                 -Bus                                    |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|\t                 -Coach                                  |\n";
            cout << "\t\t\t\t|                                                                |\n";
            cout << "\t\t\t\t|                                                                |\n\t\t\t\t|";
            cout << "________________________________________________________________|";

            cout << "\n\n\t\t\t\tType Of Vehicle: ";
            getline(cin, vehicle, '\n');
            Caps_to_Small(vehicle);
            if(!Type_of_vehicle_validator(vehicle)){
                cout << "\n\t\t\t\tError :(\n\t\t\t\tThis type of Vehicle is not in option.\n\n";
                system("pause");
                continue;
            }
            cout << "\n\n\t\t\t\tNumber Plate: ";
            getline(cin, num_plate, '\n');
            Caps_to_Small(num_plate);
            if (vehicles_list.Number_Plate_Validation(num_plate)) {
                cout << "\n\t\t\t\tError :(\n\t\t\t\tThe Vehicle with this number Plate already exits! You can't add another vehicle with same number plate.\n";
                system("pause");
            }
        }while(vehicles_list.Number_Plate_Validation(num_plate) || !Type_of_vehicle_validator(vehicle));
        //this loop will continue until we get right number plate and type of vehicle

        cout << "\n\n\t\t\t\tColor: " << colour;
        getline(cin, colour, '\n');
        Caps_to_Small(colour);
        cout << "\n\n\t\t\t\tDriver Name: " << driver;
        getline(cin, driver, '\n');
        Caps_to_Small(driver);
        cout << "\n\n\t\t\t\tModel Number: " << modelNo;
        getline(cin, modelNo, '\n');
        cout << "\n\n\t\t\t\tSeating Capacity: " << seat_capacity;
        getline(cin, seat_capacity, '\n');
        if (vehicle == "bike")
            Add_vehicle = new Bike(num_plate, colour, driver, vehicle, stoi(modelNo), stoi(seat_capacity), 0, Bike::getRate());
        else if (vehicle == "car")
            Add_vehicle = new Car(num_plate, colour, driver, vehicle, stoi(modelNo), stoi(seat_capacity), 0, Car::getRate());
        else if (vehicle == "rickshaw")
            Add_vehicle = new Rickshaw(num_plate, colour, driver, vehicle, stoi(modelNo), stoi(seat_capacity),0, Rickshaw::getRate());
        else if (vehicle == "bus")
            Add_vehicle = new Bus(num_plate, colour, driver, vehicle, stoi(modelNo), stoi(seat_capacity),0, Bus::getRate());
        else if (vehicle == "coach")
            Add_vehicle = new Coach(num_plate, colour, driver, vehicle, stoi(modelNo), stoi(seat_capacity), 0,Coach::getRate());
        vehicles_list.Add_Vehicle(Add_vehicle);
        no_of_vehicles++;
        cout << "\n\n\t\t\t\tYour vehicle is added successfully :)\n";
        system("pause");
      //  vehicles_list.print_Vehicle(); //Print all the vehicles
    }


    void Remove_Driver(){
        string driver,numberplate;
        cin.ignore();
        do{
            Print_Admin();
            cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
            cout << "Vehicle Type: \t";
            cout << "Number Plate: \t";
            cout << "Color: \t\t";
            cout << "Driver Name: \t";
            cout << "Model: \t";
            cout << "Seat Capacity: \t   ";
            cout << "is Booked: \t  ";
            cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
            vehicles_list.print_Vehicle();
            cout  << "\t\t\t\t _____________________________________________________________________\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  Do you want to Remove a Driver?                    |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  Enter Number Plate of his Vehicle                  |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  To Delete Number Plate must exit!                  |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                                                                     |\n\t\t\t\t|";
            cout << "_____________________________________________________________________|\n\n";
            cout << "\n\n\t\t\t\tNumber Plate: ";
            getline(cin,numberplate,'\n');
            Caps_to_Small(numberplate);
            if(vehicles_list.Number_Plate_Validation(numberplate)){
                vehicles_list.delete_vehicle(numberplate);
                no_of_vehicles--;
                cout << "\n\n\t\t\t\tYour vehicle is deleted successfully :)\n";
                system("pause");
                return;
            }
            else {
                cout << "\n\t\t\t\tError :(\n\t\t\t\tCan't delete, This Number Plate does not exist\n\n";
                system("pause");
            }

        }while(!vehicles_list.Number_Plate_Validation(numberplate));

    }

    void Change_rates_Details(){ //allows admin to change rates of all vehicle objects
        string type;
        int rate;
        do{
            Print_Admin();
            cout  << "\n\n\t\t\t\t _____________________________________________________________________\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  Do you want to Change Rates?                       |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  You have to Enter Type of vehicle                  |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                  Also mention, Rate Per Kilometres                  |\n";
            cout << "\t\t\t\t|                                                                     |\n";
            cout << "\t\t\t\t|                                                                     |\n\t\t\t\t|";
            cout << "_____________________________________________________________________|\n\n";
            cout << "\n\t\t\t\t\t\tType of Vehicle: ";
            cin.ignore();
            getline(cin,type,'\n');
            Caps_to_Small(type);
            if(!Type_of_vehicle_validator(type)){
                cout << "\n\t\t\t\t\t\tError :(\tThis type of Vehicle is not in option.\n\n";
                system("pause");
            }
        }while(!Type_of_vehicle_validator(type));
        cout << "\n\t\t\t\t\t\tRate Per Km: ";
        cin >> rate;
        if(cin.fail() || rate < 0) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return;
        }
        cin.ignore();
        change_rates(type,rate);
    }

    void change_rates(string type, int rate){
        /* static functions are directly accessible using their class name we need
        to change for all the objects and so made them static */
        cout << "\n\t\t\t\t\tCurrent Rate per km is: ";
        if(type=="bike") {
            cout << Bike::getRate() << "\n\n";
            Bike::Change_Rates(rate);
        }
        else if(type=="car") {
            cout << Car::getRate() << "\n\n";
            Car::Change_Rates(rate);
        }
        else if (type=="rickshaw") {
            cout << Rickshaw::getRate() << "\n\n";
            Rickshaw::Change_Rates(rate);
        }
        else if (type=="bus") {
            cout << Bus::getRate() << "\n\n";
            Bus::Change_Rates(rate);
        }
        else if (type=="coach") {
            cout << Coach::getRate() << "\n\n";
            Coach::Change_Rates(rate);
        }
        cout << "\n\n\t\t\t\tYour rates for " << type << " has been changed Successfully :)\n";
        system("pause");
    }

    int Admin_sign_out(){
        int option;
        Print_Admin();
        cout << "                                  ____________________________________________________________\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                  Do You want to Sign out?                  |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[1]";
        cout << setw(30) << "Yes                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[2]";
        cout << setw(30) << left << "No                                             |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |____________________________________________________________|\n\n";
        cout <<"\n\n\n                                                      Select your Option: ";
        cin >> option;
        if(cin.fail() || option < 1 || option > 2) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return 0;
        }
        if(option==1){
            cout << "\n\t\t\t\t\t\tSigning Out......\n\t\t\t\t\t\tYour changes has been saved successfully:)\n";
            system("pause");
            return 4;
        }
        return 0;
    }

    void User_Login_Signup(){
        Print_User();
        cout << "                                  ____________________________________________________________\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                  Want to login or Sign up?                 |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[1]";
        cout << setw(30) << "Login                                          |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[2]";
        cout << setw(30) << left << "Signup                                         |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |____________________________________________________________|\n\n";
        cout <<"\n\n\n                                                      Select your Option: ";
        Sign_Option_Controller();
    }

    void Sign_Option_Controller(){ //Will take options whether user would like to sign up or login
        int option;
        cin >> option;
        if(cin.fail() || option < 1 || option > 2) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            cin.ignore();
            return;
        }
        if(option==1)
            User_Login();
        if(option==2)
            User_Signup();
    }

    void User_Login(){
        string identification, pass, name;
        do {
            Print_User();
            cin.ignore();
            cout << "\t\t\t\tUser Login\n";
            cout << "\t\tID: ";
            getline(cin, identification, '\n');
            Caps_to_Small(identification);
            cout << "\n\t\tPassword: ";
            getline(cin, pass, '\n');
            Caps_to_Small(pass);
            logged_in_user=list.User_Validation(identification,pass);
            if(logged_in_user!=NULL) {
                User_Controls();
            }
            else {
                int num;

                cout << "                                  ____________________________________________________________\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Incorrect Username or ID!                     |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Couldn't Login:(                              |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Press 0 to return to Login Options            |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |                            OR                              |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |              Press 1 to return to Login Signup             |\n";
                cout << "                                 |                                                            |\n";
                cout << "                                 |____________________________________________________________|\n";
                cout << "\n\n\t\t\t\t\tChoose an option: ";
                cin >> num;
                if(cin.fail() || num < 0 || num > 2) { //fail flag will be set when we give input other than integer.
                    cin.clear(); //clears buffer
                    cin.ignore(); //ignore input
                    cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
                    system("pause");
                    return;
                }
                if (num==0)
                    Login_Menu();
                if(num==1)
                    User_Login_Signup();
            }
        }while (logged_in_user!=NULL);
    }

    void User_Signup(){
        //A New User wants to register
        string Username;
        string ID;
        string Pass;
        int amount;
        Print_User();
        cout << "                                  ____________________________________________________________\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              Welcome to Sign Up page!                      |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              You need to Enter:                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              Your Complete Name                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              Your Identification Number                    |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              Your Password                                 |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |              Amount to be Deposited                        |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |____________________________________________________________|\n\n\n";
        cout << "\n\n\t\t\t\tUser Name: ";
        cin >> Username;
        do{
            cout << "\n\n\t\t\t\tId: ";
            cin >> ID;
            if(list.ID_exist(ID)) {
                cout << "\n\n\t\t\t\tThis id exists already! Try another one\n\n";
            }
        }while(list.ID_exist(ID));
        cout << "\n\n\t\t\t\tPassword: ";
        cin >> Pass;
        cout << "\n\n\t\t\t\tAmount to be deposited: (max limit iss 10,000) ";
        cin >> amount;
        if(cin.fail() || amount < 1 || amount > 10000) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return;
        }
        User *user2 = new User(Username, ID, Pass, amount);

        //used a pointer so that we don't have multiple copies of the same object we just pass the user pointer in constructor
        list.Add_User(user2);
        logged_in_user=list.User_Validation(ID,Pass);
        numOfUsers++;
        //list.print_user(); //this will print the whole list of user
        //user Registration Done

    }

    void User_Controls(){
        int option;
        do{
            Print_User();
            cout << "\n\n\t\t\t\t\t\tWelcome " << logged_in_user->get_name() << " <'-'>\n\n";
            cout << "                                  ____________________________________________________________\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                  Select a function                         |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[1]";
            cout << setw(30) << "Book a Ride                                    |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[2]";
            cout << setw(30) << left << "Check nearby rides                             |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[3]";
            cout << setw(30) << left << "View Invoice                                   |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[4]";
            cout << setw(30) << left << "Wallet                                         |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        "  << setw(5) << left << "[5]";
            cout << setw(30) << left << "Sign out                                       |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |____________________________________________________________|\n\n";
            cout << "\n\t\t\t\t\t\tSelect Your Option ";
            option=User_Control_Selection();
        }while(option!=5);
    }

    int User_Control_Selection(){
        int option;
        cin >> option;
        if(cin.fail() || option < 1 || option > 5) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\n\t\t\t\t\t\tInvalid Input:(\n";
            return 0;
        }
        if(option == 1)
            Book_Ride();
        else if(option == 2)
            Nearby_rides();
        else if(option == 3)
            view_invoice();
        else if(option == 4)
            Wallet_show();
        else if(option == 5) {
            return User_sign_out();
        }
        return 0;
    }


    void Book_Ride(){
        Print_Book_Ride();
        cout << "\n\n\t\t\t\tHow much Kilometres you want to travel?: ";
        Incity_Outcity_Selector();
    }

    void Incity_Outcity_Selector(){
        //  Bike / Rickshaw / Car in city rides.Car / Coach / Bus for outstation rides
        int km;
        cin >> km;
        if(cin.fail() || km < 1 || km > 500) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return;
        }
        string type;
        if(km>50){
            cout << "\n\n\t\t\t\tYour Destination is more than 50 kms away so you can book OutStation Rides\n";
            cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
            cout << "Vehicle Type: \t";
            cout << "Number Plate: \t";
            cout << "Color: \t\t";
            cout << "Driver Name: \t";
            cout << "Model: \t";
            cout << "Seat Capacity: \t   ";
            cout << "is Booked: \t  ";
            cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
            vehicles_list.show_Available_rides("car","coach","bus"); // will display the data of only these categories
             type_of_vehicle(1);
        }
        else {
            cout << "\n\n\t\t\t\tYour Destination is less than 51 kms away so you can book City Rides\n";
            cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
            cout << "Vehicle Type: \t";
            cout << "Number Plate: \t";
            cout << "Color: \t\t";
            cout << "Driver Name: \t";
            cout << "Model: \t";
            cout << "Seat Capacity: \t   ";
            cout << "is Booked: \t  ";
            cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
            vehicles_list.show_Available_rides("bike", "rickshaw", "car");
            type = type_of_vehicle(2);
        }
        int bill=bill_Calculation(type,km);
        Booking_Rides_Options(km, bill);
    }

    string type_of_vehicle(int option){ // 1 to print outstation rides 2 to print city rides
        string type;
        bool validation;
        do{
            Print_Book_Ride();
            if(option==1){
                cout  << "\n\n\t\t\t\t ________________________________________________________________\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                  Select Type of Vehicle:                       |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                  Available Options are:                        |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Car                                    |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Bus                                    |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Coach                                  |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                                                                |\n\t\t\t\t|";
                cout << "________________________________________________________________|\n\n\n";
            }
            else if(option==2){
                cout  << "\t\t\t\t ________________________________________________________________\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                  Select Type of Vehicle:                       |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                  Available Options are:                        |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Bike                                   |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Rickshaw                               |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|\t                 -Car                                    |\n";
                cout << "\t\t\t\t|                                                                |\n";
                cout << "\t\t\t\t|                                                                |\n\t\t\t\t|";
                cout << "________________________________________________________________|";
            }

            cin.ignore();
            cout << "\n\t\t\t\t\t\tVehicle Type: ";
            getline(cin,type,'\n');
            Caps_to_Small(type);
            validation=Type_of_vehicle_validator(type);
            if(!validation)
                cout << "\n\t\t\t\t\t\tError :(\tThis type of Vehicle is not in option.\n\n";
            else {
                cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
                cout << "Vehicle Type: \t";
                cout << "Number Plate: \t";
                cout << "Color: \t\t";
                cout << "Driver Name: \t";
                cout << "Model: \t";
                cout << "Seat Capacity: \t   ";
                cout << "is Booked: \t  ";
                cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
                vehicles_list.show_Type_of_vehicle_rides(type);
            }

        }while(!validation);
        return type; //returns the selected vehicle
    }

    void Booking_Rides_Options(int distance, int bill){
        string n_plate;
        cout << "\n\t\t\t\tEnter the Number Plate of the vehicle you want to book: ";
        cin >> n_plate;
        if(vehicles_list.Number_Plate_Validation(n_plate)){

            cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
            cout << "Vehicle Type: \t";
            cout << "Number Plate: \t";
            cout << "Color: \t\t";
            cout << "Driver Name: \t";
            cout << "Model: \t";
            cout << "Seat Capacity: \t   ";
            cout << "is Booked: \t  ";
            cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
            vehicles_list.print_object(n_plate);
            cout << "                                  ____________________________________________________________\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |               Bill for this ride will be:                  |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |               " <<setw(5) << bill << "                                        |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |               Want to book this ride?                      |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[1]";
            cout << setw(30) << "Yes                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |        " << setw(5) << left << "[2]";
            cout << setw(30) << left << "No                                             |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |____________________________________________________________|\n\n";
            cout <<"\n\n\n                                                      Select your Option: ";
            Ride_is_Booked(n_plate,distance);
        }
        else{
            cout << "\n\t\t\t\t\t\tError :(\tThis type of Vehicle is not in option.\n\n";
            Book_Ride();
        }
    }

    void Nearby_rides(){
        Print_User();
        cout << "\n\t\t\t\t\t\tChecking nearby rides.....";
        cout << "\n\n\t\t\t\t\t\tNearby Rides are: \n";//will show the rides that are not booked yet

        cout << "\n\n----------------------------------------------------------------------------------------------------------------------\n";
        cout << "Vehicle Type: \t";
        cout << "Number Plate: \t";
        cout << "Color: \t\t";
        cout << "Driver Name: \t";
        cout << "Model: \t";
        cout << "Seat Capacity: \t   ";
        cout << "is Booked: \t  ";
        cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
        vehicles_list.print_nearby_rides();
        system("pause");
    }

    void view_invoice(){
        Print_User();
        string invoice=logged_in_user->get_invoice();
        if(invoice!="")
            cout << invoice;
        else
            cout << "\n\t\t\t\t\t\tError :(\n\t\t\t\t\t\tYou have not booked a ride yet.\n\t\t\t\t\t\tBook a ride first then you can see invoice.\n\n";
        system("pause");
    }

    void Wallet_show(){
        Print_User();
        cout << "\n\t\t\t\t\t\tYour balance is: " ;
        cout << logged_in_user->get_wallet() << '\n';
        system("pause");
    }

    void Ride_is_Booked(string num, int distance){ // num is number plate and distance is the required travelled distance
        int option,bill,wallet;
        string type_of_vehicle;
        cin >> option;
        if(cin.fail() || option < 1 || option > 2) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return;
        }
        type_of_vehicle=vehicles_list.is_Booked(num);
        bill=bill_Calculation(type_of_vehicle,distance);
        bool isEnd = false;
        if(option==1){
            do{
                if(logged_in_user->get_wallet()>=bill){
                    wallet=logged_in_user->get_wallet();
                    logged_in_user->edit_wallet(-bill);
                    cout << "                                  ____________________________________________________________\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |              Rs. "<< bill << "                                     |\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |              have deducted from your wallet                |\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |              Your Ride is booked successfully              |\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |              Enjoy your Ride :)                            |\n";
                    cout << "                                 |                                                            |\n";
                    cout << "                                 |____________________________________________________________|\n\n\n";
                    logged_in_user->generate_invoice(type_of_vehicle,vehicles_list.get_driver(num),num,distance,bill);//whenever a ride is booked the invoice is generated against it
                    isEnd = true; //not booked or booked
                }

                else {

                    cout << "\n\n\t\t\t\t\t\tInsufficient balance in your wallet.\n";
                    if (!deposit_money()) {
                        cout << "                                  ____________________________________________________________\n";
                        cout << "                                 |                                                            |\n";
                        cout << "                                 |                                                            |\n";
                        cout << "                                 |              Cancelling booking.......                     |\n";
                        cout << "                                 |                                                            |\n";
                        cout << "                                 |              Your ride has not been booked.                |\n";
                        cout << "                                 |                                                            |\n";
                        cout << "                                 |                                                            |\n";
                        cout << "                                 |____________________________________________________________|\n";
                        vehicles_list.cancel_booking(num);
                        isEnd = true;
                    }
                }
            }while(!isEnd);
        }
        else{
            cout << "\n\n\t\t\t\t\t\tYour ride has not been booked:(\n";
            vehicles_list.cancel_booking(num);
        }
    }

    int bill_Calculation(string type, int distance){
        int rate;
        if(type=="bike")
            rate=Bike::getRate();
        else if(type=="car")
            rate=Car::getRate();
        else if (type=="rickshaw")
            rate=Rickshaw::getRate();
        else if (type=="bus")
            rate=Bus::getRate();
        else if (type=="coach")
            rate=Coach::getRate();
        return rate*distance;
    }

    bool deposit_money(){
        Print_User();
        int option,amount,balance,wallet;
        string account,pin;
        cout << "                                  ____________________________________________________________\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |               Want to Deposit Money in wallet?             |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[1]";
        cout << setw(30) << "yes                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[2]";
        cout << setw(30) << left << "No                                             |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |____________________________________________________________|\n\n";
        cout <<"\n\n\n                                                      Select your Option: ";
        cin >> option;
        if(cin.fail() || option < 1 || option > 2) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return false;
        }
        if(option==1){
            cout << "                                  ____________________________________________________________\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |              Credit Card details                           |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |              You need to Enter:                            |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |              Your Account Number                           |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |              Your Account Pin                              |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |              Amount to be Deposited                        |\n";
            cout << "                                 |                                                            |\n";
            cout << "                                 |____________________________________________________________|\n\n\n";
            cout << "\n\n\t\t\t\t\t\tAccount number: ";
            cin >> account;
            cout << "\n\n\t\t\t\t\t\tEnter pin: ";
            cin >> pin;
            cout << "\n\n\t\t\t\t\t\tEnter amount you want to deposit";
            do{
                cout << "\n\n\t\t\t\t\t\tMaximum wallet deposit limit is 10,000\n";
                cout << "\nAmount: ";
                cin >> amount;
                wallet=logged_in_user->get_wallet();
                balance=amount+wallet;
            }while(balance>10000 || balance<0);
            logged_in_user->edit_wallet(amount+wallet);
            cout << "\n\n\t\t\t\t\t\tYour amount has been added to your wallet:\n\n\t\t\t\t\t\tYour current wallet balance is: ";
            cout << logged_in_user->get_wallet() << endl;
            return true;
        }
        return false;
    }

    int User_sign_out(){
        Print_User();
        int option;
        cout << "                                  ____________________________________________________________\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |               Do you want to sign out??                    |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[1]";
        cout << setw(30) << "yes                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |        " << setw(5) << left << "[2]";
        cout << setw(30) << left << "No                                             |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |                                                            |\n";
        cout << "                                 |____________________________________________________________|\n\n";
        cout <<"\n\n\n                                                      Select your Option: ";
        cin >> option;
        if(cin.fail() || option < 1 || option > 2) { //fail flag will be set when we give input other than integer.
            cin.clear(); //clears buffer
            cin.ignore(); //ignore input
            cout << "\n\n\t\t\t\t\t\tInvalid Input:(\n";
            system("pause");
            return 0;
        }
        if(option==1){
            cout << "\n\t\t\t\t\t\tSigning Out......\n\t\t\t\t\t\tYour changes has been saved successfully:)\n";
            logged_in_user = NULL;
            return 5; //5 will sign out
        }
    }

    ~System(){
        fstream Admin_User_writing;
        Admin_User_writing.open("Users.csv",ios::out);
        if(Admin_User_writing.fail()) { //if file does not open for certain reasons
           cout << "User or Admin File cannot be open. Terminating Program......" << endl;
           exit(1);
        }
        Admin_User_writing << *admin;
        Admin_User_writing << numOfUsers;
        Admin_User_writing << "\n";
        list.User_file_writing(Admin_User_writing); //file may writing kun ni ho ri???

        Admin_User_writing.close();

        fstream Vehicle_writing;
        Vehicle_writing.open("./Vehicles.csv",ios::out);
        if(Vehicle_writing.fail()) { //if file does not open for certain reasons
           cout << "Vehicle File cannot be open. Terminating Program......" << endl;
           exit(1);
        }
        Vehicle_writing << no_of_vehicles << "\n";
        vehicles_list.File_list_writing(Vehicle_writing);
        Vehicle_writing.close();
     }

    void Print_Intro()
    {
        string loading = "";
        int i, percent;
        for(i=0; i<8; i++)
        {
            system("cls");
            for(int j = 0; j<i; j++)
                cout << "\n";
            cout << "\t\t                     ___           ___           ___                       \n";
            cout << "\t\t         ______ __  /  /___       /  /  ___ ____/  /__ ___ _____ ____      \n";
            cout << "\t\t        /  ___/  /_/  /  _ \\     /  /__/   /   /  ____/  / __  / _   /    \n";
            cout << "\t\t       /  /  /  / _  /  ___/    /  _  / - / - /   \\  /  / / / / /_/ /     \n";
            cout << "\t\t      /__/  /__/\\___/\\____/     \\____/___/___/__/\\_\\/__/_/ /_/\\___,/  \n";
            cout << "\t\t                                          __                 /____/        \n";
            cout << "\t\t		         _______  _______/ /____  ____ ___                          \n";
            cout << "\t\t		        / ___/ / / / ___/ __/ _ \\/ __ `__ \\                       \n";
            cout << "\t\t		       (__  / /_/ (__  / /_/  __/ / / / / /                         \n";
            cout << "\t\t		      /____/\\__, /____/\\__/\\___/_/ /_/ /_/                       \n";
            cout << "\t\t		           /____/                                                   \n";


            Sleep(1);
        }
        cout << "\n\n";

        cout << "\t\t\t\t\t\t    LOADING FILES         \n";
        for(i=0, percent = 0; i<35; i++, percent += 3)
        {
            loading.push_back('#');
            if(percent > 100)
                percent = 100;
            cout << "\r\t\t\t\t(" << percent << "%)   [" << setw(-35) << loading << "]";
            Sleep(80);
        }
        cout << '\n';
        Sleep(3000);
    }

    void Print_Home()
    {
        system("cls");

        cout << "\n\n";
        cout << "\t\t\t\t     H          H      OOO     MM        MM   EEEEEEEEEEE    \n";
        cout << "\t\t\t\t     H          H     O   O    M M      M M   E              \n";
        cout << "\t\t\t\t     H          H    O     O   M  M    M  M   E              \n";
        cout << "\t\t\t\t     H          H   O       O  M   M  M   M   E              \n";
        cout << "\t\t\t\t     HHHHHHHHHHHH   O       O  M    MM    M   EEEEEEEEEEE    \n";
        cout << "\t\t\t\t     H          H   O       O  M          M   E              \n";
        cout << "\t\t\t\t     H          H    O     O   M          M   E              \n";
        cout << "\t\t\t\t     H          H     O   O    M          M   E              \n";
        cout << "\t\t\t\t     H          H      OOO     M          M   EEEEEEEEEEE    \n";
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
    }

    void Print_Admin()
    {
        system("cls");
        cout << "                                     _______                     _______                             ______           \n";
        cout << "        /\\       |\\       |\\    /|      |     |\\      |         |       |      /\\        |\\      |  |        |        \n";
        cout << "       /  \\      |  \\     | \\  / |      |     | \\     |         |       |     /  \\       | \\     |  |        |        \n";
        cout << "      /    \\     |    \\   |  \\/  |      |     |  \\    |         |       |    /    \\      |  \\    |  |        |        \n";
        cout << "     /______\\    |    |   |      |      |     |   \\   |         |_______|   /______\\     |   \\   |  |------  |        \n";
        cout << "    /        \\   |    /   |      |      |     |    \\  |         |          /        \\    |    \\  |  |        |        \n";
        cout << "   /          \\  |  /     |      |      |     |     \\ |         |         /          \\   |     \\ |  |        |        \n";
        cout << "  /            \\ |/       |      |   ___|___  |      \\|         |        /            \\  |      \\|  |______  |_______ \n";
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
    }

    void Print_User()
    {
        system("cls");
        cout << "\t                _______    ______   _____          _______                             ______           \n";
        cout << "\t   |        |  |          |        |     |        |       |      /\\        |\\      |  |        |        \n";
        cout << "\t   |        |  |          |        |     |        |       |     /  \\       | \\     |  |        |        \n";
        cout << "\t   |        |  |          |        |     |        |       |    /    \\      |  \\    |  |        |        \n";
        cout << "\t   |        |  |_______   |------  |_____|        |_______|   /______\\     |   \\   |  |------  |        \n";
        cout << "\t   |        |          |  |        |\\             |          /        \\    |    \\  |  |        |        \n";
        cout << "\t   |        |          |  |        |  \\           |         /          \\   |     \\ |  |        |        \n";
        cout << "\t   |________|  ________|  |______  |    \\         |        /            \\  |      \\|  |______  |_______ \n";
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
    }

    void Print_Book_Ride()
    {
        system("cls");

        cout << "    BBB         OOO        OOO     K     K          NN        N     OOO     W           W    \n";
        cout << "    B   B      O   O      O   O    K    K           N N       N    O   O    W           W    \n";
        cout << "    B    B    O     O    O     O   K   K            N  N      N   O     O   W           W    \n";
        cout << "    B   B    O       O  O       O  K  K             N   N     N  O       O  W     W     W    \n";
        cout << "    BBBB     O       O  O       O  KKK              N    N    N  O       O  W    W W    W    \n";
        cout << "    B   B    O       O  O       O  K  K             N     N   N  O       O  W   W   W   W    \n";
        cout << "    B    B    O     O    O     O   K   K            N      N  N   O     O   W  W     W  W    \n";
        cout << "    B   B      O   O      O   O    K    K           N       N N    O   O    W W       W W    \n";
        cout << "    BBB         OOO        OOO     K     K          N        NN     OOO     WW         WW    \n";
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";

    }

    void Print_Exit()
    {
        system("cls");

        cout << "\n\n\n\n";
        cout << "\t\tEEEEEEEE   X        X  IIIIIIIIIIII  TTTTTTTTTTTTTT  IIIIIIIIIIII  NN        N      GGGGGGG      \n";
        cout << "\t\tE           X      X        I              T              I        N N       N     G             \n";
        cout << "\t\tE            X    X         I              T              I        N  N      N    G              \n";
        cout << "\t\tE             X  X          I              T              I        N   N     N   G               \n";
        cout << "\t\tEEEEEEEE       XX           I              T              I        N    N    N   G               \n";
        cout << "\t\tE             X  X          I              T              I        N     N   N    G    GGGGGG    \n";
        cout << "\t\tE            X    X         I              T              I        N      N  N     G       G     \n";
        cout << "\t\tE           X      X        I              T              I        N       N N      G     G      \n";
        cout << "\t\tEEEEEEEE   X        X  IIIIIIIIIIII        T         IIIIIIIIIIII  N        NN       GGGGG       \n";

        cout << "\n\n\n\t\t\t\t\t\t  SAVING FILES         \n";


        string loading = "";
        int i, percent;
        for(i=0, percent = 0; i<35; i++, percent += 3)
        {
            loading.push_back('#');
            if(percent > 100)
                percent = 100;
            cout << "\r\t\t\t\t[" << setw(-35) << loading << "] (" << percent << "%)";
            Sleep(80);
        }
        Sleep(2000);
    }
};

#endif





