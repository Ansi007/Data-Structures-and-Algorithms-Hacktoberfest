//*File to write data *//
#include<iostream>
#include<cstring>
#include<fstream>
#include"Admin.cpp"
#include"User.cpp"
#include"Vehicle.cpp"
#include"bike.cpp"
#include"Car.cpp"
#include"Rickshaw.cpp"
#include"Bus.cpp"
#include"Coach.cpp"
using namespace std;

/* *******User.txt file writing *****
int main(){
    fstream file;
    Admin admin("Imaan Saleem","bcsf20m523","2339");
    file.open("./Users.txt",ios::out);
    file << admin;
    User user("Eisha Hamid","bcsf20m519","519",100);
    file << user.count_of_Users << endl;
    file << user;
    file.close();
    return 0;

}
*/
/* *******Vehicle.txt file writing *****
int main(){
    Vehicle *vehicle[30];//array of pointers
    fstream file;
    vehicle[0]=new Bike("PZA_195","Black","Talha","bike",2010, 1, 0,100);
    vehicle[1]=new Bike("QYB_284","White","Hussain","bike",2004, 1, 0,100);
    vehicle[2]=new Bike("RXC_376","Gray","Samir","bike",2001, 1, 0, 100);
    vehicle[3]=new Bike("SWD_463","Silver","Talal","bike",2003, 1, 0, 100);
    vehicle[4]=new Bike("TVE_552","Red","Rayan","bike",2005, 1, 0, 100);
    vehicle[5]=new Bike("VUF_641","Blue","Hassan","bike",2002, 1, 0, 100);
    vehicle[6]=new Bike("UTG_730","Brown","Omar","bike",2019, 1, 0, 100);
    vehicle[7]=new Bike("WSH_821","Green","Tabish","bike",2008, 1, 0, 100);
    vehicle[8]=new Car("XRI_912","Beige","Khalil","car",2022, 4, 0, 500);
    vehicle[9]=new Car("YQJ_543","Orange","Hadi","car",2007, 4, 0, 500);
    vehicle[10]=new Car("ZPK_951","Gold","Haris","car",2018, 4, 0, 500);
    vehicle[11]=new Car("AOL_842","Yellow","Faiz","car",2006, 4, 0, 500);
    vehicle[12]=new Car("BNM_736","Purple","Danish","car",2017, 4, 0, 500);
    vehicle[13]=new Car("CMN_634","Black","Hammad","car",2000, 4, 0, 500);
    vehicle[14]=new Car("DLO_525","White","Junaid","car",2005, 4, 0, 500);
    vehicle[15]=new Car("EKP_461","Silver","Kamal","car",2016, 4, 0, 500);
    vehicle[16]=new Car("FJQ_703","Gray","Karim","car",1999, 4, 0,500);
    vehicle[17]=new Car("GIR_218","Red","Abbas","car",2021, 4, 0, 500);
    vehicle[18]=new Rickshaw("HHS_192","Maroon","Adeel","rickshaw",2015, 3, 0, 300);
    vehicle[19]=new Rickshaw("IGT_435","Black","Arsal","rickshaw",2005, 3, 0, 300);
    vehicle[20]=new Rickshaw("JFU_915","Purple","Jibran","rickshaw",2020, 3, 0, 300);
    vehicle[21]=new Rickshaw("KEV_523","Yellow","Haider","rickshaw",1014, 3, 0, 300);
    vehicle[22]=new Rickshaw("LDW_308","Gold","Jamal","rickshaw",1998, 3, 0, 300);
    vehicle[23]=new Rickshaw("MCX_417","Orange","Arham","rickshaw",2023, 3, 0, 300);
    vehicle[24]=new Rickshaw("NBY_549","Beige","Hamza","rickshaw",1987, 3, 0, 300);
    vehicle[25]=new Bus("OAZ_658","Gray","Aamir","bus",2009, 8, 0, 200);
    vehicle[26]=new Bus("HYM_767","Green","Adnan","bus",2003, 8, 0, 200);
    vehicle[27]=new Bus("NTP_876","Brown","Ahmad","bus",2021, 8, 0, 200);
    vehicle[28]=new Coach("FLS_985","Blue","Nazir","coach",2011, 10,0,200);
    vehicle[29]=new Coach("STB_194","Red","Ali","coach",2020, 10, 0, 200);
    file.open("./Vehicles.csv",ios::out);
    file << vehicle[0]->count_of_Vehicles << endl;
    for(int i=0;i<30;i++){
    //Passed the fstream object to function because ifstream works for reading and writing both
        vehicle[i]->writeInFile(file);
        cout <<'\n';
    }
    return 0;
}
*/


/*What we have done
 * Number 1-Admin
step1 users.txt file to be open in write mode
create object of admin class
file kay start may
Name Username Password
1 //no of registered users

number 2_Users
Name Username Password wallet
objects of vehicle

count of vehicles 30
type_of vehicle number_plate, string color, string driver_name, int model_no, int seating_capacity, bool is_Booked
//30 vehicles ka data*/