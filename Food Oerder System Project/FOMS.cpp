#ifndef FOODSYSTEM
#define FOODSYSTEM

#include<iostream>
#include<cstring>
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
    Restaurant* loggedInRestaurant;
    User* loggedInUser;
    int usersCount;
    int restaurantsCount;
    int mealsCount;

    void toIDCase(string &s)
    {
        int i;
        for(i=0; i<s.length(); i++)
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        removeComma(s);
    }

    void toNameCase(string &s)
    {
        int i;
        if(s[0] >= 'a' && s[0] <= 'z' )
            s[0] -= 32;
        for(i=1; i<s.length(); i++)
            if(s[i-1] == ' ' && s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        removeComma(s);
    }

    void removeComma(string &s)
    {
        s.erase(remove(s.begin(), s.end(), ','), s.end());
    }

    int optionsScreen(string *s, int count, string header = "")
    {
        int index, option, i;
        string invalid = "";
        do {
            system("cls");
            cout << header + invalid;
            cout << "\n\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n";
            for (index = 0; index < count; index++) {
                cout << "\t\t\t\t\t\t\t\tEnter   < " << index + 1 << " >   |-->   " << s[index] << endl << endl;
            }
            cout << "\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\t\t\t\t\t\t\t\tEnter your Choice --> __\b\b ";
            cin >> option;
            if(cin.fail() || option <= 0 || option > count) {
                cin.clear();
                cin.ignore();
                invalid =  getInvalidString();
                option = -1;
            }
        }while(option <= 0 || option > count);
        cin.ignore();
        return option;
    }

    bool confirmationScreen(string s, string header = "")
    {
        int option;
        int i;
        string invalid = "";
        if(header == "")
            header = getConfirmHeader();
        do {
            system("cls");
            cout << header + invalid;
            cout << "\n\n\n\n\t\t\t\t\t\t";
            for(i = 0; i<80; i++)
                cout << "#";
            cout << "\n\n\n\n\t\t\t\t\t\t";
            cout << s << "\n\n";
            cout << "\t\t\t\t\t\t\t\t Enter < 0 >  |-->   NO" << "\n\n";
            cout << "\t\t\t\t\t\t\t\t Enter < 1 >  |-->   YES" << "\n\n";
            cout << "\n\t\t\t\t\t\t";
            for(i = 0; i<80; i++)
                cout << "#";
            cout << "\n\n\n\n\t\t\t\t\t\t\t\tEnter your Choice --> _\b";
            cin >> option;
            if(cin.fail() || !(option == 0 || option == 1) ){
                cin.clear();
                cin.ignore();
                invalid = getInvalidString();
                option = -1;
            }
        }while(!(option == 0 || option == 1));
        cin.ignore();
        return option;
    }

    void mainMenu()
    {
        int option = 0;
        string header;
        do {
            string s[] = {"Restaurant Panel", "Users Panel", "Exit"};
            int count = 3;
            header = getMainMenuHeader();
            option = optionsScreen(s, count, header);

            switch (option) {
                case 1:
                    RestaurantPanel();
                    break;
                case 2:
                    UsersPanel();
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
        string header = getRestaurantHeader();
        option = optionsScreen(s1, count, header);
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

        header += "\n\n\n";
        header += "\t\t\t\t\t\t\t\t|----->    Welcome " + loggedInRestaurant->getName() + "    <-----|\n";

        string s2[] = {"Check List of Available Meals", "Add a New Meal", "Delete a Existing Meal", "Update a meal", "Logout"};
        count = 5;

        do {
            option = optionsScreen(s2, count, header);
            switch(option)
            {
                case 1:
                    meals.printMealsList(loggedInRestaurant->getID(), loggedInRestaurant->getName(), header);
                    system("pause");
                    break;
                case 2:
                    addNewMeal(header);
                    break;
                case 3:
                    deleteMeal(header);
                    break;
                case 4:
                    updateMeal(header);
                    break;
                case 5:
                    loggedInRestaurant = NULL;
                    return;
                default:
                    throw invalid_argument("From Restaurant Panel");
            }
        }while(option != 5);
    }

    Restaurant* restaurantLogin()
    {
        string id, password;
        Restaurant* res = NULL;
        int i;
        bool loggedIn = true;
        string header = getRestaurantHeader();
        string confirmHeader = getConfirmHeader();

        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------------\n";
            cout << "\t\t\t\t\t\t\t\t\t|  Restaurant Login  |\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------------\n\n";
            cout << "\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter Restaurant ID: ";
            getline(cin, id, '\n');
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Password: ";
            getline(cin, password, '\n');
            res = restaurants.authenticateLogin(id, password);
            if (res == NULL) {
                loggedIn = confirmationScreen("\tIncorrect ID or Password! Do you want to Login Again?");
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
        int i;
        string header = getRestaurantHeader();
        string confirmHeader = getConfirmHeader();

        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t-----------------------\n";
            cout << "\t\t\t\t\t\t\t\t\t|  Restaurant SignUp  |\n";
            cout << "\t\t\t\t\t\t\t\t\t-----------------------\n\n";
            cout << "\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter Restaurant Name: ";
            getline(cin, name, '\n');
            toNameCase(name);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Restaurant ID: ";
            getline(cin, id, '\n');
            toIDCase(id);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Password: ";
            getline(cin, password1, '\n');
            removeComma(password1);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Confirmation! Enter Password Again: ";
            getline(cin, password2, '\n');
            removeComma(password2);
            if (password1 != password2) {
                cout << "\n\t\t\t\t\t\t\t\t";
                cout << "OOPS! Password Does not Match.\n\n";
                for(i=3; i>=1; i--) {
                    cout << "\r\t\t\t\t\t\t\t\tTry Again in " << i << " seconds.";
                    Sleep(1000);
                }
            }
            else if(restaurants.isExists(id)) {
                flag = confirmationScreen("Restaurant with this ID Already exists. Do you want to try Signing up Again?");
            }
            else {
                newRes = new Restaurant(name, id, password1);
                restaurants.addNode(newRes);
                restaurantsCount++;
                return newRes;
            }
        }while(flag);
        return NULL;
    }

    void addNewMeal(string header)
    {
        string type, name, description, price;
        string id = loggedInRestaurant->getID();
        int i;
        system("cls");
        cout << header;
        cout << "\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t|---->   ADD NEW MEAL   <----|";
        cout << "\n\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\n\t\t\t\t\t\t\t\t";
        cout << "Enter the type of Meal (e.g Pizza, Burger): ";
        getline(cin, type, '\n');
        toIDCase(type);
        cout << "\n\t\t\t\t\t\t\t\t";
        cout << "Enter the Name of Meal: ";
        getline(cin, name, '\n');
        toNameCase(name);
        cout << "\n\t\t\t\t\t\t\t\t";
        cout << "Enter the brief Description of the meal: ";
        getline(cin, description, '\n');
        removeComma(description);
        cout << "\n\t\t\t\t\t\t\t\t";
        cout << "Enter the price of the meal: ";
        getline(cin, price, '\n');
        Meal *newMeal = new Meal(id, type, name, description, stoi(price));
        meals.addMeal(id, newMeal);
        mealsCount++;
        cout << "\n\n\t\t\t\t\t\t\t\t";
        cout << "<-----------------Meal Added Successfully------------------->\n\n";
        for(i = 3; i >= 1; i--)
        {
            cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
            Sleep(1000);
        }
    }

    void deleteMeal(string header)
    {
        string name;
        string id = loggedInRestaurant->getID();
        int i;
        system("cls");
        cout << header;
        cout << "\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t|---->   DELETE A MEAL   <----|";
        cout << "\n\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\t\t\t\t\t\t\t\t";
        meals.printMealsList(loggedInRestaurant->getID(), loggedInRestaurant->getName(), header, false);
        cout << "\n\n\t\t\t\t\t\t\t\t";
        cout << "Enter the name of the meal you want to delete: ";
        getline(cin, name, '\n');
        toNameCase(name);
        if(meals.deleteMeal(id, name)) {
            mealsCount--;
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<-----------------Meal Deleted Successfully------------------->\n\n";
            for(i = 3; i >= 1; i--)
            {
                cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
            }
        }
        else
            system("pause");
    }

    void updateMeal(string header)
    {
        string name;
        int i;
        string id = loggedInRestaurant->getID();
        system("cls");
        cout << header;
        cout << "\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t|---->   UPDATE A MEAL   <----|";
        cout << "\n\n\n\t\t\t\t";
        for( i = 0; i < 50; i++)
            cout << "<>";
        cout << "\n\t\t\t\t\t\t\t\t";
        meals.printMealsList(loggedInRestaurant->getID(), loggedInRestaurant->getName(), header, false);
        cout << "\n\n\t\t\t\t\t\t\t\t";
        cout << "Enter the name of the Meal you want to update: ";
        getline(cin, name, '\n');
        toNameCase(name);
        Meal *meal = NULL;
        meal = meals.getMealbyName(id, name);
        if(meal == NULL) {
            system("pause");
            return;
        }
        string tempHeader = header;
        string updated;
        bool flag = true;
        do {
            header = tempHeader + "\n\n\t\t\t\t\t\t\t\t|----->    Selected Meal: " + name + "    <-----|\n" + "\n\n\t\t\t\t\t\t\t\tWhat do you want to Update?\n\n";
            string s[] = {"Type", "Name", "Description", "Price", "Go Back"};
            int option = optionsScreen(s, 5, header);
            switch (option) {
                case 1:
                    cout << "\n\n\t\t\t\t\t\t\t\t";
                    cout << "Enter the new type of the meal: ";
                    getline(cin, updated, '\n');
                    toIDCase(updated);
                    meal->setTypeOfMeal(updated);
                    break;
                case 2:
                    cout << "\n\n\t\t\t\t\t\t\t\t";
                    cout << "Enter the new Name of the meal: ";
                    getline(cin, updated, '\n');
                    toNameCase(updated);
                    meal->setMealName(updated);
                    break;
                case 3:
                    cout << "\n\n\t\t\t\t\t\t\t\t";
                    cout << "Enter the new Description of the meal: ";
                    getline(cin, updated, '\n');
                    removeComma(updated);
                    meal->setDescription(updated);
                    break;
                case 4:
                    cout << "\nEnter the new Price of the meal: ";
                    getline(cin, updated, '\n');
                    meal->setPrice(stoi(updated));
                    break;
                case 5:
                    return;
                default:
                    throw invalid_argument("From update meal");
            }
            flag = confirmationScreen("Do You want to update anything else in this meal?", tempHeader);
        }while(flag);
    }

    void UsersPanel()
    {
        int option = 0;
        string s1[] = {"Login as Existing User", "Register as a New User", "Go Back"};
        int count = 3;
        string header = getUserHeader();
        option = optionsScreen(s1, count, header);
        switch (option)
        {
            case 1:
                loggedInUser = UserLogin();
                break;
            case 2:
                loggedInUser = UserSignUp();
                break;
            case 3:
                return;
            default:
                throw invalid_argument("From Users Panel");
        }

        if(loggedInUser == NULL)
            return;
        
        header += "\n\n\n";
        header += "\t\t\t\t\t\t\t\t|----->    Welcome " + loggedInUser->getName() + "    <-----|\n";

        string s2[] = {"Order Food", "View Cart", "Manage Wallet", "Change Address", "Logout"};
        count = 5;

        do {
            option = optionsScreen(s2, count, header);
            switch(option)
            {
                case 1:
                    orderFood(header);
                    break;
                case 2:
                    viewCart(header);
                    break;
                case 3:
                    manageWallet(header);
                    break;
                case 4:
                    changeAddress(header);
                    break;
                case 5:
                    loggedInUser = NULL;
                    return;
                default:
                    throw invalid_argument("From Users Panel");
            }
        }while(option != 5);
    }

    User* UserLogin()
    {
        string id, password;
        int i;
        User* user = NULL;
        bool loggedIn = true;
        string header = getUserHeader();

        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------------\n";
            cout << "\t\t\t\t\t\t\t\t\t|     USER LOGIN     |\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------------\n\n";
            cout << "\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter User ID: ";
            getline(cin, id, '\n');
            toIDCase(id);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Password: ";
            getline(cin, password, '\n');
            removeComma(password);
            user = users.authenticateLogin(id, password);
            if (user == NULL) {
                loggedIn = confirmationScreen("Incorrect ID or Password. Do you want to Login Again?");
            } else
                return user;
        }while(loggedIn);
        return NULL;
    }

    User* UserSignUp()
    {
        string name, id, password1, password2, address;
        User* newUser = NULL;
        bool flag = true;
        int i;
        string header = getUserHeader();
        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------\n";
            cout << "\t\t\t\t\t\t\t\t\t|  USER SignUp  |\n";
            cout << "\t\t\t\t\t\t\t\t\t----------------\n\n";
            cout << "\n\t\t\t\t";
            for( i = 0; i < 50; i++)
                cout << "<>";
            cout << "\n\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter Your Name: ";
            getline(cin, name, '\n');
            toNameCase(name);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Your Address: ";
            getline(cin, address, '\n');
            removeComma(address);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter your ID: ";
            getline(cin, id, '\n');
            toIDCase(id);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Enter Password: ";
            getline(cin, password1, '\n');
            removeComma(password1);
            cout << "\n\t\t\t\t\t\t\t\t";
            cout << "Confirmation! Enter Password Again: ";
            getline(cin, password2, '\n');
            removeComma(password2);
            if (password1 != password2) {
                cout << "\n\t\t\t\t\t\t\t\t";
                cout << "OOPS! Password Does not Match.\n\n";
                for(i=3; i>=1; i--) {
                    cout << "\r\t\t\t\t\t\t\t\tTry Again in " << i << " seconds.";
                    Sleep(1000);
                }
            }
            else if(users.isExists(id)) {
                flag = confirmationScreen("User with this ID Already exists. Do you want to try Signing up Again?");
            }
            else {
                newUser = new User(name, id, password1, address, 0);
                users.addNode(newUser);
                usersCount++;
                return newUser;
            }
        }while(flag);
        return NULL;
    }

    void orderFood(string header)
    {
        int option = 3;
        string s[] = {"Search Meals by Restaurant", "Search Meals by Name", "Go Back"};
        header = getOrderHeader();
        option = optionsScreen(s, 3, header + "\n\n\t\t\t\t\t\t\t\tHow do you want to search for your favourite Meals?");
        switch(option)
        {
            case 1:
                orderByResturant(header);
                break;
            case 2:
                orderBySearch(header);
                break;
            case 3:
                return;
            default:
                throw invalid_argument("From Order Food");
        }
    }

    void orderByResturant(string header)
    {
        string name;
        Meal* meal = NULL;
        int i;
        do{
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t\t\t\t\t|---->   Available Restaurants   <----|\n";
            restaurants.showNames();
            cout << "\n\n\t\t\t\t\t\t\t\tEnter the Restaurant Name --> ";
            getline(cin, name, '\n');
            toNameCase(name);
            loggedInRestaurant = restaurants.getRestaurantbyName(name);
            if(loggedInRestaurant != NULL)
            {
                break;
            }
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<----------------- Restaurant Does not Exist ------------------->\n\n";
            for(i = 3; i >= 1; i--)
            {
                cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
            }
        }while(loggedInRestaurant == NULL);

        do{
            meals.printMealsList(loggedInRestaurant->getID(), loggedInRestaurant->getName(), header);
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter the Meal Name: ";
            getline(cin, name, '\n');
            toNameCase(name);
            meal = meals.getMealbyName(loggedInRestaurant->getID(), name);
            if(meal != NULL)  
                break;
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<----------------- Meal Does not Exist ------------------->\n\n";
            for(i = 3; i >= 1; i--)
            {
                cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
            }
        }while(meal == NULL);
        loggedInRestaurant = NULL;
        addToCart(meal, header);
    }

    void orderBySearch(string header)
    {
        string type, name;
        Meal *meal = NULL;
        int i;

        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t\t\t\t\t|---->   Search for your Favourite Meals.   <----|\n";
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter your keywords (e.g pizza, burger) --> ";
            getline(cin, type, '\n');
            toIDCase(type);
            cout << "\n";
            meals.showMealsBySearch(type);
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "Enter the Meal Name: ";
            getline(cin, name, '\n');
            toNameCase(name);
            meal = meals.getMealbyName(name);
            toNameCase(name);
            if(meal != NULL)
                break;
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "<----------------- Meal Does not Exist ------------------->\n\n";
            for(i = 3; i >= 1; i--)
            {
                cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
            }
        }while(meal == NULL);
        addToCart(meal, header);
    }

    void addToCart(Meal* meal, string header)
    {
        system("cls");
        int i;
        cout << header;
        cout << "\n\n\t\t\t\t\t\t\t\t|---->   Selected Meal   <----|\n\n\n";
        meal->displayList();
        cout << "\n\n\t\t\t\t\t\t\t\t\t";
        cout << "-->   Processing...";
        Sleep(3000);
        string confirmMeal = "\tAre You sure you want to add ";
        confirmMeal += meal->getMealName();
        confirmMeal += " to your cart.";
        bool isConfirmed = confirmationScreen(confirmMeal);
        system("cls");
        cout << header;
        cout << "\n\n\t\t\t\t\t\t\t\t|---->   Selected Meal   <----|\n\n\n";
        meal->displayList();
        cout << "\n\n\t\t\t\t\t\t";
        if(isConfirmed){
            loggedInUser->addToCart(meal);
            cout << "<-----------------Meal Successfully Added to cart------------------->\n\n";
        }
        else{
            cout << "<-----------------Cancelled Adding to Cart------------------->\n\n";
        }
        for(i = 3; i >= 1; i--)
        {
                cout << "\r\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
        }
    }

    void viewCart(string header)
    {
        system("cls");
        int i;
        header = getCartHeader();
        cout << header;
        string tempCart = header;
        cout << "\n\n\t\t\t\t\t\t\t\t|---->   VIEW CART   <----|\n\n\n";
        tempCart += "\n\n\t\t\t\t\t\t\t\t|---->   VIEW CART   <----|\n\n\n";
        loggedInUser->showCart();
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t Grand Total --> " << loggedInUser->calculatePriceOfCart() << " Rs.\n\n\n";
        system("pause");
        string s[] = {"Checkout", "Empty Cart", "Go Back"};
        int option = optionsScreen(s, 3, tempCart);
        switch(option)
        {
            case 1:
                checkoutMeal(header);
                break;
            case 2:
                loggedInUser->emptyCart();
                cout << "\n\n\t\t\t\t\t\t\t<-----------------Cart Emptied Successfully------------------->\n\n";
                for(i = 3; i >= 1; i--)
                {
                    cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                    Sleep(1000);
                }
                return;
            case 3:
                return;
            default:
                throw invalid_argument("From view cart");
        }
    }

    void checkoutMeal(string header)
    {
        int price = loggedInUser->calculatePriceOfCart();
        int i;
        system("cls");
        header = getCartHeader();
        cout << header;
        header += "\n\n\t\t\t\t\t\t\t\t|---->   CHECKOUT   <----|\n";
        header += "\n\n\t\t\t\t\t\t\t\t";
        string confirm = "Are You sure you want to checkout all the Meals from your Cart?";
        confirm += "An amount of Rs. ";
        confirm += to_string(price);
        confirm += " will be deducted from your wallet.";
        confirm += "\n\n\t\t\t\t\t\t\tDelivery Address: ";
        confirm += loggedInUser->getAddress() + "\n";
        bool isConfirmed = confirmationScreen(confirm);

        system("cls");
        cout << header;
        if(isConfirmed)
        {
            int wallet = loggedInUser->getWallet();
            if(price < wallet)
            {
                loggedInUser->addToWallet(-price);
                cout << "\n\n\t\t\t\t\t\t\t\t";
                cout << "--> Order Placed Successfully!!\n";
                cout << "\n\n\t\t\t\t\t\t\t\t";
                cout << "--> Your Meals are on their way. Please be patient. ";
                cout << "\n\n\t\t\t\t\t\t\t\t";
                cout << "--> Deducted " << price << " Rs from your wallet. New Balance is " << loggedInUser->getWallet() << ".\n";
                cout << "\n\n\t\t\t\t\t\t\t\t";
                cout << "<---------------------Thanks For Ordering!!!---------------------->\n\n";
                loggedInUser->emptyCart();
            }
            else{
                cout << "\n\n\t\t\t\t\t\t";
                cout << "You don't have enough balance in your wallet. Please Deposit funds and try ordering Again!!\n\n";
            }
        }
        else {
            cout << "<-----------------Checkout Cancelled Successfully------------------->\n\n";
        }
        system("pause");
    }

    void manageWallet(string header)
    {
        system("cls");
        header = getWalletHeader();
        header +=  "\n\n\t\t\t\t\t\t\t\t|---->   MANAGE WALLET   <----|\n";
        header += "\n\n\t\t\t\t\t\t\t\t";
        header += "-->  Current Balance: " + to_string(loggedInUser->getWallet()) + "\n\n";
        cout << header;
        string s[] = {"Deposit Amount", "Go Back"};
        int option = optionsScreen(s, 2, header);
        switch(option)
        {
            case 1:
                depositInWallet(header);
                break;
            case 2:
                return;
            default:
                throw invalid_argument("From Manage Wallet\n");
        }
    }

    void changeAddress(string header)
    {
        system("cls");
        int i;
        header += "\n\n\t\t\t\t\t\t\t\t|---->   Change Address   <----|";
        string confirm = "--> Current Address: ";
        confirm += loggedInUser->getAddress() + '\n';
        confirm += "\n\t\t\t\t\t\t-->   Are you sure you want to change this address?\n";
        bool isConfirmed = confirmationScreen(confirm, header);
        if(isConfirmed)
        {
            string address;
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "-->   Enter the New Address: ";
            getline(cin, address, '\n');
            removeComma(address);
            loggedInUser->setAddress(address);
            cout << "\n\n\t\t\t\t\t\t\t";
            cout << "<-----------------Address Changed Successfully------------------->\n\n";
        }
        else    
            cout << "\n\n\t\t\t\t\t\t\t<-----------------Cancelled Request------------------->\n\n";
        for(i = 3; i >= 1; i--)
        {
            cout << "\r\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
            Sleep(1000);
        }
    }

    void depositInWallet(string header)
    {
        string accountNo, pin;
        int i;
        int amount;
        do {
            system("cls");
            cout << header;
            cout << "\n\n\t\t\t\t\t\t\t\t|---->   DEPOSIT AMOUNT   <----|\n";
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "-->   Enter 12 digit Credit Card Number: ";
            getline(cin, accountNo, '\n');
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "-->   Enter 4 digit pin: ";
            getline(cin, pin, '\n');
            if(accountNo.length() == 12 && pin.length() == 4 )
                break;
            if(accountNo.length() != 12)
                cout << "\n\n\t\t\t\t\t\t\t\tInvalid Credit card number!! Length must be 12\n";
            if(pin.length() != 4)
                cout << "\n\t\t\t\t\t\t\t\tInvalid pin!! Length must be 4\n\n\n";
            for(i = 3; i >= 1; i--)
            {
                cout << "\r\t\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
                Sleep(1000);
            }
        }while(accountNo.length() != 12 || pin.length() != 4);

        do{
            cout << "\n\n\t\t\t\t\t\t\t\t";
            cout << "-->   Enter the amount you want to deposit (Max Amount = 50,000): ";
            cin >> amount;
        }while(amount <= 0 || amount > 50000);
        cin.ignore();
        loggedInUser->addToWallet(amount);
        cout << "\n\n\t\t\t\t\t\t\t";
        cout << "<--------------" << amount << " Rs added to your wallet auccessfully. Your new balance is " << loggedInUser->getWallet() << ".------------>\n\n\n";
        for(i = 3; i >= 1; i--)
        {
            cout << "\r\t\t\t\t\t\t\tReturning to previous screen in " << i << " seconds.";
            Sleep(1000);
        }
    }

    string getInvalidString()
    {
        return "\n\n\t\t\t\t\t\t<----------------------INVALID INPUT!!!---------------------->\n";
    }

    string getMainMenuHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t    |M||M|      |M||M|           |A|           |I||I||I||I||I|  |N||N|        |N|      |M||M|      |M||M|  |E||E||E||E|  |N||N|        |N|  |U|         |U|\n";
        str += "\t    |M| |M|    |M| |M|         |A| |A|               |I|        |N| |N|       |N|      |M| |M|    |M| |M|  |E|           |N| |N|       |N|  |U|         |U|\n";
        str += "\t    |M|  |M|  |M|  |M|        |A|   |A|              |I|        |N|  |N|      |N|      |M|  |M|  |M|  |M|  |E|           |N|  |N|      |N|  |U|         |U|\n";
        str += "\t    |M|   |M||M|   |M|       |A|     |A|             |I|        |N|   |N|     |N|      |M|   |M||M|   |M|  |E|           |N|   |N|     |N|  |U|         |U|\n";
        str += "\t    |M|    |M|     |M|      |A|       |A|            |I|        |N|    |N|    |N|      |M|    |M|     |M|  |E||E||E|     |N|    |N|    |N|  |U|         |U|\n";
        str += "\t    |M|            |M|     |A||A||A||A||A|           |I|        |N|     |N|   |N|      |M|            |M|  |E|           |N|     |N|   |N|  |U|         |U|\n";
        str += "\t    |M|            |M|    |A|           |A|          |I|        |N|      |N|  |N|      |M|            |M|  |E|           |N|      |N|  |N|  |U|         |U|\n";
        str += "\t    |M|            |M|   |A|             |A|         |I|        |N|       |N| |N|      |M|            |M|  |E|           |N|       |N| |N|  |U|         |U|\n";
        str += "\t    |M|            |M|  |A|               |A|  |I||I||I||I||I|  |N|        |N||N|      |M|            |M|  |E||E||E||E|  |N|        |N||N|  |U||U||U||U||U|\n";
        str += "\n";
        str += "\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return str;
    }

    string getRestaurantHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t\t   |S||S||S||S|  |E||E||E||E|  |L|           |L|               |N||N|        |N|  |O||O||O||O||O|  |W|             |W|  \n";
        str += "\t\t\t   |S|           |E|           |L|           |L|               |N| |N|       |N|  |O|         |O|  |W|             |W|  \n";
        str += "\t\t\t   |S|           |E|           |L|           |L|               |N|  |N|      |N|  |O|         |O|  |W|             |W|  \n";
        str += "\t\t\t   |S|           |E|           |L|           |L|               |N|   |N|     |N|  |O|         |O|  |W|             |W|  \n";
        str += "\t\t\t   |S||S||S||S|  |E||E||E|     |L|           |L|               |N|    |N|    |N|  |O|   |O|   |O|  |W|     |W|     |W|  \n";
        str += "\t\t\t            |S|  |E|           |L|           |L|               |N|     |N|   |N|  |O|         |O|  |W|   |W| |W|   |W|  \n";
        str += "\t\t\t            |S|  |E|           |L|           |L|               |N|      |N|  |N|  |O|         |O|  |W|  |W|   |W|  |W|  \n";
        str += "\t\t\t            |S|  |E|           |L|           |L|               |N|       |N| |N|  |O|         |O|  |W| |W|     |W| |W|  \n";
        str += "\t\t\t   |S||S||S||S|  |E||E||E||E|  |L||L||L||L|  |L||L||L||L|      |N|        |N||N|  |O||O||O||O||O|  |W||W|       |W||W|  \n";
        str += "\n";
        str += "\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n";
        return str;
    }

    string getUserHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t\t|H|         |H|  |U|         |U|  |N||N|        |N|      |G||G||G|       |R||R||R|    |Y|            |Y|     |?||?||?|     \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N| |N|       |N|    |G|       |G|   |R|       |R|    |Y|        |Y|      |?|     |?|    \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N|  |N|      |N|  |G|         |G|  |R|        |R|      |Y|    |Y|       |?|       |?|   \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N|   |N|     |N|  |G|              |R|      |R|          |Y||Y|          |?|     |?|    \n";
        str += "\t\t\t|H||H||H||H||H|  |U|         |U|  |N|    |N|    |N|  |G|              |R|    |R|              |Y|                  |?|     \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N|     |N|   |N|  |G|   |G||G||G|  |R|  |R|                |Y|                 |?|      \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N|      |N|  |N|  |G|   |G|   |G|  |R|    |R|              |Y|                |?|       \n";
        str += "\t\t\t|H|         |H|  |U|         |U|  |N|       |N| |N|    |G|       |G|  |R|      |R|            |Y|                          \n";
        str += "\t\t\t|H|         |H|  |U||U||U||U||U|  |N|        |N||N|      |G||G||G|    |R|        |R|          |Y|                |?|       \n";
        str += "\n";
        str += "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n";

        return str;
    }


    string getOrderHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t  |O||O||O||O||O|     |R||R||R|    |D||D||D||D||D|  |E||E||E||E|     |R||R||R|        |N||N|        |N|  |O||O||O||O||O|  |W|             |W| \n";
        str += "\t\t  |O|         |O|   |R|       |R|     |D|      |D|  |E|            |R|       |R|      |N| |N|       |N|  |O|         |O|  |W|             |W| \n";
        str += "\t\t  |O|         |O|  |R|        |R|     |D|      |D|  |E|           |R|        |R|      |N|  |N|      |N|  |O|         |O|  |W|             |W| \n";
        str += "\t\t  |O|         |O|  |R|      |R|       |D|      |D|  |E|           |R|      |R|        |N|   |N|     |N|  |O|         |O|  |W|             |W| \n";
        str += "\t\t  |O|   |O|   |O|  |R|    |R|         |D|      |D|  |E||E||E|     |R|    |R|          |N|    |N|    |N|  |O|   |O|   |O|  |W|     |W|     |W| \n";
        str += "\t\t  |O|         |O|  |R|  |R|           |D|      |D|  |E|           |R|  |R|            |N|     |N|   |N|  |O|         |O|  |W|   |W| |W|   |W| \n";
        str += "\t\t  |O|         |O|  |R|    |R|         |D|      |D|  |E|           |R|    |R|          |N|      |N|  |N|  |O|         |O|  |W|  |W|   |W|  |W| \n";
        str += "\t\t  |O|         |O|  |R|      |R|       |D|      |D|  |E|           |R|      |R|        |N|       |N| |N|  |O|         |O|  |W| |W|     |W| |W| \n";
        str += "\t\t  |O||O||O||O||O|  |R|        |R|  |D||D||D||D||D|  |E||E||E||E|  |R|        |R|      |N|        |N||N|  |O||O||O||O||O|  |W||W|       |W||W| \n";
        str += "\n";
        str += "\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
        return str;
    }

    string getCartHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t\t\t\t\t   |C||C||C||C|           |A|              |R||R||R|    |T||T||T||T||T| \n";
        str += "\t\t\t\t\t\t   |C|                  |A| |A|          |R|       |R|        |T|       \n";
        str += "\t\t\t\t\t\t   |C|                 |A|   |A|        |R|        |R|        |T|       \n";
        str += "\t\t\t\t\t\t   |C|                |A|     |A|       |R|      |R|          |T|       \n";
        str += "\t\t\t\t\t\t   |C|               |A|       |A|      |R|    |R|            |T|       \n";
        str += "\t\t\t\t\t\t   |C|              |A||A||A||A||A|     |R|  |R|              |T|       \n";
        str += "\t\t\t\t\t\t   |C|             |A|           |A|    |R|    |R|            |T|       \n";
        str += "\t\t\t\t\t\t   |C|            |A|             |A|   |R|      |R|          |T|       \n";
        str += "\t\t\t\t\t\t   |C||C||C||C|  |A|               |A|  |R|        |R|        |T|       \n";
        str += "\n";
        str += "\t\t\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
        return str;
    }

    string getWalletHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t\t\t     |W|             |W|           |A|           |L|           |L|             |E||E||E||E|  |T||T||T||T||T| \n";
        str += "\t\t\t\t     |W|             |W|         |A| |A|         |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W|             |W|        |A|   |A|        |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W|             |W|       |A|     |A|       |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W|     |W|     |W|      |A|       |A|      |L|           |L|             |E||E||E|           |T|       \n";
        str += "\t\t\t\t     |W|   |W| |W|   |W|     |A||A||A||A||A|     |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W|  |W|   |W|  |W|    |A|           |A|    |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W| |W|     |W| |W|   |A|             |A|   |L|           |L|             |E|                 |T|       \n";
        str += "\t\t\t\t     |W||W|       |W||W|  |A|               |A|  |L||L||L||L|  |L||L||L||L|    |E||E||E||E|        |T|       \n";
        str += "\n";
        str += "\t\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
        return str;
    }

    string getConfirmHeader()
    {
        string str = "";
        str += "\n\n\n";

        str += "\t\t   |C||C||C||C|  |O||O||O||O||O|  |N||N|        |N|  |F||F||F||F|  |I||I||I||I||I|     |R||R||R|    |M||M|      |M||M|     |?||?||?|   \n";
        str += "\t\t   |C|           |O|         |O|  |N| |N|       |N|  |F|                 |I|         |R|       |R|  |M| |M|    |M| |M|    |?|     |?|  \n";
        str += "\t\t   |C|           |O|         |O|  |N|  |N|      |N|  |F|                 |I|        |R|        |R|  |M|  |M|  |M|  |M|   |?|       |?| \n";
        str += "\t\t   |C|           |O|         |O|  |N|   |N|     |N|  |F|                 |I|        |R|      |R|    |M|   |M||M|   |M|    |?|     |?|  \n";
        str += "\t\t   |C|           |O|   |O|   |O|  |N|    |N|    |N|  |F||F||F|           |I|        |R|    |R|      |M|    |M|     |M|           |?|   \n";
        str += "\t\t   |C|           |O|         |O|  |N|     |N|   |N|  |F|                 |I|        |R|  |R|        |M|            |M|          |?|    \n";
        str += "\t\t   |C|           |O|         |O|  |N|      |N|  |N|  |F|                 |I|        |R|    |R|      |M|            |M|         |?|     \n";
        str += "\t\t   |C|           |O|         |O|  |N|       |N| |N|  |F|                 |I|        |R|      |R|    |M|            |M|                 \n";
        str += "\t\t   |C||C||C||C|  |O||O||O||O||O|  |N|        |N||N|  |F|           |I||I||I||I||I|  |R|        |R|  |M|            |M|         |?|     \n";
        str += "\n";
        str += "\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
        return str;
    }

    void startIntro()
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t  Please Enter Full Screen mode and Press any key to Start...\n\n";
        system("pause");
        system("cls");
        Sleep(500);
        cout << "\n\n";

        cout<<"\t\t\t\t\t%%      %%      \n";
        cout<<"\t\t\t\t\t%%      %%      \n";
        cout<<"\t\t\t\t\t%%      %%  %%%%%%%  %%       %%%%%%   %%%%%%  %%%%  %%%%  %%%%%%%     \n";
        cout<<"\t\t\t\t\t%%  %%  %%  %%       %%       %%       %%  %%  %%  %%% %%  %%          \n";
        cout<<"\t\t\t\t\t%%  %%  %%  %%%%%    %%       %%       %%  %%  %%  %%% %%  %%%%%       \n";
        cout<<"\t\t\t\t\t%%  %%  %%  %%       %%       %%       %%  %%  %%      %%  %%          \n";
        cout<<"\t\t\t\t\t%%%%%%%%%%  %%%%%%%  %%%%%%%  %%%%%%   %%%%%%  %%      %%  %%%%%%%     \n";

        Sleep(1000);
        cout << "\n\n";

        cout<<"\t\t\t\t\t\t\t\t\t   %%%%%%%%%%  %%%%%%%%   \n";
        cout<<"\t\t\t\t\t\t\t\t\t       %%      %%    %%   \n";
        cout<<"\t\t\t\t\t\t\t\t\t       %%      %% %% %%   \n";
        cout<<"\t\t\t\t\t\t\t\t\t       %%      %%    %%   \n";
        cout<<"\t\t\t\t\t\t\t\t\t       %%      %%%%%%%%   \n";

        Sleep(1000);
        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%%%%%%%  %%%%%%%%%%  %%%%%%%%%%  %%%%%%%%%%%%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%        %%      %%  %%      %%    %%      %%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%        %%      %%  %%      %%    %%      %%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%%%%%    %%  %%  %%  %%  %%  %%    %%      %%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%        %%      %%  %%      %%    %%      %%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%        %%      %%  %%      %%    %%      %%  \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   %%        %%%%%%%%%%  %%%%%%%%%%  %%%%%%%%%%%%  \n";


        Sleep(1000);
        cout << "\n\n";

        cout << "\t\t\t\t\t %%%%%%%%%%  %%%%%%%  %%%%%%%%%%%  %%%%%%%  %%%%%%%  %%%%%%%%  %%%%      %%    %%%%%%%%  \n";
        cout << "\t\t\t\t\t %%      %%  %%   %%    %%     %%  %%       %%   %%     %%     %% %%     %%    %%        \n";
        cout << "\t\t\t\t\t %%      %%  %%   %%    %%     %%  %%       %%   %%     %%     %%  %%    %%    %%        \n";
        cout << "\t\t\t\t\t %%  %%  %%  %%%%%%%    %%     %%  %%%%     %%%%%%%     %%     %%   %%   %%    %% %%%%%  \n";
        cout << "\t\t\t\t\t %%      %%  %%%%       %%     %%  %%       %%%%        %%     %%    %%  %%    %% %% %%  \n";
        cout << "\t\t\t\t\t %%      %%  %% %%      %%     %%  %%       %% %%       %%     %%     %% %%    %%    %%  \n";
        cout << "\t\t\t\t\t %%%%%%%%%%  %%  %%%  %%%%%%%%%%%  %%%%%%%  %%  %%%  %%%%%%%%  %%      %%%%    %%%%%%%%  \n";

        Sleep(1000);
        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t %%%%%%%  %%      %%  %%%%%%%  %%%%%%%%%%  %%%%%%%  %%%%     %%%%          \n";
        cout << "\t\t\t\t\t\t\t\t\t %%        %%    %%   %%           %%      %%       %% %%   %% %%          \n";
        cout << "\t\t\t\t\t\t\t\t\t %%         %%  %%    %%           %%      %%       %%  %% %%  %%          \n";
        cout << "\t\t\t\t\t\t\t\t\t %%%%%%%     %%%%     %%%%%%%      %%      %%%%     %%   %%%   %%          \n";
        cout << "\t\t\t\t\t\t\t\t\t      %%      %%           %%      %%      %%       %%         %%          \n";
        cout << "\t\t\t\t\t\t\t\t\t      %%      %%           %%      %%      %%       %%         %%          \n";
        cout << "\t\t\t\t\t\t\t\t\t %%%%%%%      %%      %%%%%%%      %%      %%%%%%%  %%         %%          \n";

        Sleep(1000);
        cout << "\n\n\n";

        int i; 
        for(i=5; i>=1; i--)
        {
            cout << "\r\t\t\t\t\t\t\t\t\t  Starting in " << i << " seconds";
            Sleep(1000);  
        }
    }

public:
    FOMS()
    {
        fstream file;
        string name, id, password,wallet, typeOfMeal, description, price, address;
        int i;

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
            toIDCase(id);
            getline(file, name, ',');
            toNameCase(name);
            getline(file, password, ',');
            getline(file, address, ',');
            getline(file, wallet, ',');
            newUser = new User(name, id, password, address, stoi(wallet));
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
            toIDCase(id);
            getline(file, name, ',');
            toNameCase(name);
            getline(file, password, ',');
            newRestaurant = new Restaurant(name, id, password);
            restaurants.addNode(newRestaurant);
        }
        //restaurants.stdOut(cout);
        file.close();

        file.open("Meals.csv", ios::in);
        if(file.fail())
            throw invalid_argument("OOPS!! Meals.csv File does not Exist\n");

        file >> mealsCount;
        for(i=0; i<mealsCount; i++)
        {
            file.ignore();
            getline(file, id, ',');
            toIDCase(id);
            getline(file, typeOfMeal, ',');
            toIDCase(typeOfMeal);
            getline(file, name, ',');
            toNameCase(name);
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
        startIntro();
        mainMenu();
    }

    ~FOMS()
    {
        fstream file;

        file.open("Users.csv", ios::out);
        file << usersCount << '\n';
        users.stdOut(file, true);
        file.close();

        file.open("Restaurants.csv", ios::out);
        file << restaurantsCount << '\n';
        restaurants.stdOut(file, true);
        file.close();

        file.open("Meals.csv", ios::out);
        file << mealsCount << '\n';
        meals.stdOut(file, true);
        file.close();
    }
};

#endif
