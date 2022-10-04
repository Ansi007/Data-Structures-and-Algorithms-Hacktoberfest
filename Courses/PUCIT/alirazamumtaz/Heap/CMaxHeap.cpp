#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ISFULL 1
#define ISEMPTY 0
class CMaxHeap{
	int *x, currentSize, size;
public:
	CMaxHeap(int s=20){	
		currentSize = 1;	//Again index 0 is left blank purposely
		size = s+1;
		x = new int[size];
	}
	void swap(int &a, int &b){
		int temp = a;
		a  = b;
		b = temp;
	}
	void insert(int d) {
		if (currentSize>=size)	throw(ISFULL);
		x[currentSize] = d;
		int i = currentSize;
		while (i>1){
			if (x[i/2] < x[i]){
				swap(x[i/2], x[i]);
				i = i / 2 ;
			}
			else break;
		}	
		currentSize++;
	}
	int remove() {
		if (currentSize<=1)		throw (ISEMPTY);
		int temp = x[1];
		currentSize --;
		x[1] = x[currentSize];
		int i=1, largerChild;
		while (i*2<currentSize){
			largerChild = i*2+1;
			if (i*2+1 >= currentSize || x[i*2] > x[i*2+1])  largerChild = i*2;
			if (x[i]>=x[largerChild])	break;
			swap(x[i], x[largerChild]);
			i = largerChild;
		}
		return temp;
	}
	bool isEmpty() const{
		return currentSize == 1;
	}
	~CMaxHeap(){
		delete []x;
	}
};

int main(){
	freopen("D:\\AlgoExpert - Become an Algorithms Expert\\input.txt","r",stdin);
	freopen("D:\\AlgoExpert - Become an Algorithms Expert\\output.txt","w",stdout);
	srand(time(0));
	int val;
	CMaxHeap heap(20);
	for (int i=1;i<=15;i++){
		try{
			val = rand()%3;
			if (val<2){
				val = rand()%100;
				cout << setw(2) << val << " is inserted\n";
				heap.insert(val);
			}
			else{
				val = heap.remove();
				cout << setw(2) << val << " is removed\n";
			}
		}catch(int e){
			i--;
		}
	}
	while (!heap.isEmpty()){
		cout << setw(2) << heap.remove() << " is removed\n";
	}
	return 0;
}
