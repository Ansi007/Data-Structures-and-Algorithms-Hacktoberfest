#include <iostream>

using namespace std;

	class ShowRoom{
		class CarNode{
		public:
			string company, brand, trans;
			int engCap, seatCap,mileage;
			long long price;
			string registered;
			CarNode *next, *prev;
				CarNode(){
				company = "Dummy", brand = "Dummy", trans = "DummyTran";
				engCap = -999, seatCap = -9, mileage = -9999;
				price = -9999999;
				registered = "DummyRegisteration";
				next = NULL, prev = NULL;
			}
			CarNode(string company, string brand, int mileage, long long price, string registered,
					int engCap = 660,int seatCap = 4,string trans = "Automatic"){
				this->company = company, this->brand = brand, this->trans = trans;
				this->engCap = engCap, this->seatCap = seatCap, this->mileage = mileage;
				this->price = price;
				this->registered = registered;
				this->next = NULL, this->prev = NULL;
			}
			void show(){
				cout << company << "\t\t" << brand << "\t\t" << trans << "\t\t  "
					 << engCap << "\t\t  " << seatCap << "\t\t  "  << mileage << "\t\t"
					 << price << "\t\t" << registered << "\t\t";
			}
			friend ostream& operator << (ostream& out, CarNode& car){
				out << car.company << ' ' << car.brand << ' ' << car.engCap << " CC " << " [Rs. " << car.price << " only]\n"
					<< car.trans << ' ' << car.registered << '\n'
					<< "Seating Capacity: " << car.seatCap << '\n'
					<< "Mileage: " << car.mileage << '\n';
				return out;
			}
	};
	void freeList(CarNode* t){
		if(t != NULL)	freeList(t->next);
		delete t;
	}
	CarNode *head, *tail;
public:
	ShowRoom(){
		head = new CarNode();
		tail = NULL;
	}
	void addNewCar(){
		CarNode* newCar = new CarNode();
		if(tail == NULL){
            head->next = newCar;
            newCar-> next = NULL;
            newCar->prev = head;
            tail = newCar;
        }	else{
            tail->next = newCar;
            newCar->prev = tail;
            newCar->next = NULL;
            tail = newCar;
        }
	}
	void addNewCar(string company, string brand, int mileage, long long price, string registered,
			int engCap,int seatCap,string trans){
		CarNode* newCar = new CarNode(company,brand,mileage,price,registered,engCap,seatCap,trans);
		if(tail == NULL){
            head->next = newCar;
            newCar-> next = NULL;
            newCar->prev = head;
            tail = newCar;
        }	else{
            tail->next = newCar;
            newCar->prev = tail;
            newCar->next = NULL;
            tail = newCar;
        }
	}
	void searchCompany(string company){
		for( CarNode* t = head->next; t!=NULL; t = t->next){
			if(t->company == company)
				cout << t;
		}
	}
	void searchBrand(string brand){
		for( CarNode* t = head->next; t!=NULL; t = t->next){
			if(t->brand == brand)
				cout << t;
		}
	}
	void searchManual(){
		for( CarNode* t = head->next; t!=NULL; t = t->next){
			if(t->trans == "Manual")
				cout << t;
		}
	}
	void searchAutomatic(){
		for( CarNode* t = head->next; t!=NULL; t = t->next){
			if(t->trans == "Automatic")
				cout << t;
		}
	}
	void searchInPriceRange(long long min, long long max){
		for( CarNode* t = head->next; t!=NULL; t = t->next){
			if(t->price >= min and t->price <= max)
				cout << t;
		}
	}
	friend ostream& operator << (ostream& out, ShowRoom& showRoom){
		int sr = 1;
		out << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		out << "Sr.\tCompany\t\tBrand\t\tTransmission\t\tEngin Capacity\tSeat Capacity\tMileage\t\tPrice\t\t\tRegisteration\n";
		out << "------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		for(CarNode* t = showRoom.head->next;  t!=NULL; t = t->next){
			out << sr++ << '\t';
 			t->show();
			out << '\n';
		}
		return out;
	}
	~ShowRoom(){
		freeList(head->next);
		head = tail = NULL;
	}
};

int main(int argc, char const *argv[]){
	// CarNode c("company1","brand1",1300,220000,true);
	// cout << c;
	// CarNode car;
	// car.show();
	ShowRoom s;
	s.addNewCar();
	s.addNewCar("Toyota1","Yarsi1",20000,22000000,"Unregistered",1500,4,"Automatic");
	s.addNewCar("Toyota2","Yarsi2",20000,22000000,"Unregistered",1500,4,"Automatic");
	s.addNewCar("Toyota3","Yarsi3",20000,22000000,"Unregistered",1500,4,"Automatic");
	cout << s;
	return 0;
}