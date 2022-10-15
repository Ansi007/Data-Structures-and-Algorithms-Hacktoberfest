#include<iostream>
#include<cstring>
#include<fstream>
#include "HashMap.cpp"
#include "User.cpp"
#include "Meal.cpp"
#include "Restaurant.cpp"

using namespace std;

//int main()
//
// {
//    fstream file;
//    int num;
    /*
    file.open("Restaurants.csv", ios::out);
    Restaurant *res;
    num = 4;
    file << num << endl;
    res = new Restaurant("McDonald's", "mcdonalds", "2339");
    res->stdOut(file, true);
    res = new Restaurant("KFC", "kfc", "2339");
    res->stdOut(file, true);
    res = new Restaurant("Dominos", "dominos", "2339");
    res->stdOut(file, true);
    res = new Restaurant("Howdy", "howdy", "2339");
    res->stdOut(file, true);
    file.close();
    */
    /*
    file.open("Users.csv", ios::out);
    User *user;
    num = 2;
    file << num << endl;
    user = new User("Umair Javed", "539", "39", "Street 27 House 11 Canal Park Lahore.", 1000);
    user->stdOut(file, true);
    user = new User("Imaan Saleem", "523", "23", "392 H1 Block Johar Town Lahore.", 3000);
    user->stdOut(file, true);
    file.close();
    */
    /*
    file.open("Meals.csv", ios::out);
    num = 30;
    file << num << endl;

    Meal *meal[30];
    meal[0] = new Meal("mcdonalds", "burger", "Mc Double Cheesy", "Sear-sizzled 100% Beef with Double layer of Melted cheese.", 565);
    meal[1] = new Meal("mcdonalds", "burger", "Mc Royale Burger", "Made with Beef patty Cheese slice Lettuce Tomato and Pickles.", 735 );
    meal[2] = new Meal("mcdonalds", "burger", "Big Mac", "Double layer of sear-sizzled Beef Cheese diced onions icebergs and crunch of Pickles", 675);
    meal[3] = new Meal("mcdonalds", "burger", "Mega Mac","Made with 4-Layers of sear-sizzled Beef patty with sauces and Meltd Cheese and crunch of Pickles.", 1025);
    meal[4] = new Meal("mcdonalds", "wrap", "Mc Wrap", "BBQ Wrap with perfectly cooked Tortilla Chipotle and Cheesy Mayo.", 405);
    meal[5] = new Meal("mcdonalds", "wrap", "Mc Arabia", "Two grilled Chicken Patties Arabic bread lettuce with a unique and unforgettable taste.", 785);
    meal[6] = new Meal("mcdonalds", "nuggets", "6 pcs Mc Nuggets", "Whichever way you enjoy your favourite McNuggets. Made with juicy white meat.", 585);
    meal[7] = new Meal("mcdonalds", "nuggets", "20 pcs Mc Nuggets", "Made with juicy white meat that makes them hard to resist more quantity.", 1235);
    meal[8] = new Meal("kfc", "chicken", "Chicken Meal 1","Kentucky fried Chicken providess the best the most crispy fried Chicken." , 370);
    meal[9] = new Meal("kfc", "chicken", "Hot Shots 9pcs","Hot and Crispy fried chicken ready to beat th hunger." , 450);
    meal[10] = new Meal("kfc", "wings", "Hot Wings 10pcs","Hungry? 10 pcs of crispy fried Wing with a regular drink and sauces." , 440);
    meal[11] = new Meal("kfc", "wings", "Saucy Wings","10pcs of Crispy fried wings dipped in 5 sauces ready to beat the appitite." , 670);
    meal[12] = new Meal("kfc", "burger", "Krunch Burger","Crunchy Chicken fillet spicy mayo lettuce between a sesame seed bun." , 560);
    meal[13] = new Meal("kfc", "burger", "Mighty Zinger","Signature Zinger but bigger! Diuble zinger fillet with a combination of spicy and plain mayo and cheese." , 850);
    meal[14] = new Meal("kfc", "deal", "Xtreme Duo Box","The irresistible of 2 signature Zinger Burgers + 2 hot wings and a Large bucket of fries." , 1370);
    meal[15] = new Meal("kfc", "Meal", "Wow Box","1 Zinger and 1 hot and crispy fried Chicken + 1 regular fries + 1 drink." , 925);
    meal[16] = new Meal("dominos", "pizza", "One & Only","Small hand tossed Pizza with 345ml Drink." , 399);
    meal[17] = new Meal("dominos", "pizza", "The Hungry One","8 inch Pizza with 345ml Drink.", 599);
    meal[18] = new Meal("dominos", "pizza", "Too Good for Two","Medium Pizza with 2 x 345ml Drinks.", 1199);
    meal[19] = new Meal("dominos", "pizza", "The Show Stopper", "Large Pizza with 1.5 liter Drink.", 1499);
    meal[20] = new Meal("dominos", "pizza", "Fix for Four", "2 Medium Pizzas with 1.5 liter Drink.", 2199);
    meal[21] = new Meal("dominos", "pizza", "Fix for Six", "2 Large Pizzas with 1.5 liter Drink.", 2599);
    meal[22] = new Meal("dominos", "deal", "The Game Changer", "Nothing like anything before. Large Premium Pizza with 1.5 liter Drink.", 2199);
    meal[23] = new Meal("howdy", "steak", "Despirado", "Jalapeno Sauce Chicken Steak", 1099);
    meal[24] = new Meal("howdy", "steak", "Texan", "Mushroom Creamy White steak", 1099);
    meal[25] = new Meal("howdy", "wings", "Kick of Chick (Grilled)", "Grilled Buffalo Wings.", 559);
    meal[26] = new Meal("howdy", "wings", "Kick of Chick (Fried)", "Fried Buffalo Wings.", 559);
    meal[27] = new Meal("howdy", "desert", "Chocaine", "Choclate Nautella Cake,", 1299);
    meal[28] = new Meal("howdy", "desert", "Tres Amigos Lotus", "3 Milk Cake Louts.", 1699);
    meal[29] = new Meal("howdy", "desert", "Oreo Shake", "Sweet cold and delicious Oreo shake. ", 399);

    for(int i=0; i<num; i++)
        meal[i]->stdOut(file, true);

    file.close();*/
//    cout << "Writing Completed\n";
//    system("pause");
//    return 0;
//}
