#include <iostream>
#include <ctime>
using namespace std;

class BarberShop{
	int *arr, size, front, rear;
public:
	BarberShop(int size){
		this->size = size;
		arr = new int[size];
		front = rear = -1;
	}
	void addCustomer(int val){
		if((front == 0 and rear == size-1) or rear == front-1)
			throw (0);
		if(front==-1)  front = 0;
		rear = (rear+1) % size;
		arr[rear] = val;
	}
	int removeCustomer(){
		if(front == -1) throw(0);
		int result = arr[front];
		if(front == rear) front = rear = -1;
		else if(front == size-1) front = 0;
		else front += 1;
		return result;
	}
	void printShop(){
		if(front == -1 and rear == -1){
			cout << "shop is off.\n";
			return;
		}
		for(int i = front; i <= rear; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	~BarberShop(){
		delete []arr;
	}
};

int main(int argc, char const *argv[]){
	srand(time(0));
	int choice, ctr=0;
	BarberShop shop(4);
	while(true){
		ctr++;
		choice = rand()%5 - 1;
		switch(choice){
			case 0:
			case 1:
			case 2:
				cout << "Customer " << ctr << " entered ";
				try{
					shop.addCustomer(ctr);
					cout << ", Accepted\n";
				}catch(int i){
					cout << ", Rejected\n";
				}
				break;
			case 3:
				try{
					shop.removeCustomer();
					break;
				}catch(int i){
					cout << "Customer " << ctr << " Served\n";
				}
			case 4:
				return 0;
		}
	}
	return 0;
}