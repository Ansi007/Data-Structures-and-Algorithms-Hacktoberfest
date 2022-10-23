#ifndef FOODSYSTEM
#define FOODSYSTEM

#include<iostream>
#include<fstream>
#include <windows.h>
#include "HashMap.cpp"
#include "User.cpp"
#include "Meal.cpp"
#include "Restaurant.cpp"

using namespace std;

class FOMS{
    List<User> users;
    List<Restaurant> restaurants;
    HashMap<Meal> meals;
    int usersCount;
    int restaurantsCount;
    Restaurant* loggedInRestaurant;
    User* loggedInUser;

    int optionsScreen(string *s, int count)
    {
        int index, option;
        for(index = 0; index < count; index++) {
            cout << "\tOption " << index + 1 << " |-> " << s[index] << endl;
        }
        cout << "\n\t\tEnter your Choice: ";
        cin >> option;
        return option;
    }

    bool confirmationScreen(string s)
    {
        bool option;
        cout << "\t" << s << endl;
        cout << "\t0. NO";
        cout << "\t1. YES";
        cout << "\n\t\tEnter your Choice: ";
        cin >> option;
        return option;
    }

    void mainMenu()
    {
        int option = 0;

        do {
            string s[] = {"Restaurant Panel", "Users Panel", "Exit"};
            int count = 3;

            option = optionsScreen(s, count);

            switch (option) {
                case 1:
                    RestaurantPanel();
                    break;
                case 2:
                    //UsersPanel();
                    break;
                case 3:
                    return;
                default:
                    throw invalid_argument("From Main Menu");
            }
        }while(option != 3);
    }

    void RestaurantPanel()
    {
        int option = 0;

        string s1[] = {"Login as Existing Restaurant", "Register a New Restaurant", "Go Back"};
        int count = 3;
        option = optionsScreen(s1, count);

        switch (option)
        {
            case 1:
                loggedInRestaurant = restaurantLogin();
                break;
            case 2:
                loggedInRestaurant = restaurantSignUp();
                break;
            case 3:
                return;
            default:
                throw invalid_argument("From Restaurant Panel");
        }

        if(loggedInRestaurant == NULL)
                return;
        cout << "\n\n\tLogged IN\n";
        cout << "\n\n\t Welcome " << loggedInRestaurant->getName() << "!";

        string s2[] = {"Check List of Available Meals", "Add a New Meal", "Delete a Existing Meal", "Update a meal", "Main Menu"};
        count = 5;

        do {
            option = optionsScreen(s1, count);
            switch(option)
            {
                case 1:
                    break;
                cese 2:
                case 3:
                case 4:

                default:
                    throw invalid_argument("From Restaurant Panel");
            }
        }while(option != 5);


    }

    Restaurant* restaurantLogin()
    {
        string id, password;
        Restaurant* res = NULL;
        bool loggedIn = true;

        do {
            cin.ignore();
            cout << "\t\tRestaurant Login\n\n";
            cout << "Enter Restaurant ID: ";
            getline(cin, id, '\n');
            cout << "Enter Password: ";
            getline(cin, password, '\n');
            res = restaurants.authenticateLogin(id, password);
            cout << "\t" << id << "\t" << password << endl;
            if (res == NULL) {
                loggedIn = confirmationScreen("\tIncorrect ID or Password\nDo you want to Login Again?");
            } else
                return res;
        }while(loggedIn);
        return NULL;
    }

    Restaurant* restaurantSignUp()
    {
        string name, id, password1, password2;
        Restaurant* newRes = NULL;
        bool flag = true;
        do {
            cin.ignore();
            cout << "\t\tRestaurant Signup\n\n";
            cout << "Enter Restaurant Name: ";
            getline(cin, name, '\n');
            cout << "Enter Restaurant ID: ";
            getline(cin, id, '\n');
            cout << "Enter Password: ";
            getline(cin, password1, '\n');
            cout << "Confirmation! Enter Password Again: ";
            getline(cin, password2, '\n');
            if (password1 != password2) {
                cout << "Password Does not Match. Try Again!\n";
            }
            else if(restaurants.isExists(id)) {
                flag = confirmationScreen("\tRestaurant with this ID Already exists\nDo you want to try Signing up Again");
            }
            else {
                newRes = new Restaurant(name, id, password1);
                restaurants.addNode(newRes);
                return newRes;
            }
        }while(flag);
        return NULL;
    }

public:
    FOMS()
    {
        fstream file;
        string name, id, password,wallet, typeOfMeal, description, price;
        int i, num, endLine;

        loggedInRestaurant = NULL;
        loggedInUser = NULL;

        User* newUser;
        Restaurant* newRestaurant;
        Meal* newMeal;

        file.open("Users.csv", ios::in);
        if(file.fail())
            throw invalid_argument("\nOOPS!! Users.csv File does not Exist");
        file >> usersCount;
        for(i=0; i<usersCount; i++)
        {
            file.ignore();
            getline(file, id, ',');
            getline(file, name, ',');
            getline(file, password, ',');
            getline(file, wallet, ',');
            newUser = new User(name, id, password, stoi(wallet));
            users.addNode(newUser);
        }
        //users.stdOut(cout);
        file.close();

        file.open("Restaurants.csv", ios::in);
        if(file.fail())
            throw invalid_argument("\nOOPS!! Restaurants.csv File does not Exist");
        file >> restaurantsCount;
        for(i=0; i<restaurantsCount; i++)
        {
            file.ignore();
            getline(file, id, ',');
            getline(file, name, ',');
            getline(file, password, ',');
            newRestaurant = new Restaurant(name, id, password);
            restaurants.addNode(newRestaurant);
        }
        //restaurants.stdOut(cout);
        file.close();

        file.open("Meals.csv", ios::in);
        if(file.fail())
            throw invalid_argument("OOPS!! Meals.csv File does not Exist\n");

        file >> num;
        for(i=0; i<num; i++)
        {
            file.ignore();
            getline(file, id, ',');
            getline(file, typeOfMeal, ',');
            getline(file, name, ',');
            getline(file, description, ',');
            getline(file, price, ',');
            newMeal = new Meal(id, typeOfMeal, name, description, stoi(price));
            meals.addMeal(id, newMeal);
        }
        //meals.stdOut(cout, false);
        file.close();
    }

    void start()
    {
        mainMenu();
    }
};

#endif
