#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class CMinHeap {
	T *data;
	int size, capacity;

	void swap(T &a, T &b) {
		T temp = a;
		a = b;
		b = a;
	}
public: 
	CMinHeap(int capacity = 10) {
		this->capacity = capacity;
		size = 1; // First index is left for some reason
		data = new T [capacity];
	}
	void push(T d) {
		if (size >= capacity)	throw("No space to add more data.\n");
		data[size] = d;
		for (int i = size; data[i] < data[i / 2] and i > 1; i /= 2) {
			swap(data[i], data[i / 2]);
		}
		size += 1;
	}

	T pop(){
		if (size<=1)		throw ("Heap is empty.\n");
		int temp = data[1];
		size --;
		data[1] = data[size];
		int i=1, smallChild;
		while (i*2<size){
			smallChild = i*2+1;
			if (i*2+1 >= size || data[i*2] < data[i*2+1])  smallChild = i*2;
			if (data[i]<=data[smallChild])	break;
			swap(data[i], data[smallChild]);
			i = smallChild;
		}
		return temp;
	}
	void show(){
		for(int i=1;i<size; i++)
			cout << data[i] << ' ';
		cout << '\n';
	}
	bool isEmpty() const{
		return size == 1;
	}
	~CMinHeap() {
		delete data;
	}

};

int main(int argc, char const *argv[]) {
	freopen("D:\\AlgoExpert - Become an Algorithms Expert\\input.txt","r",stdin);
	freopen("D:\\AlgoExpert - Become an Algorithms Expert\\output.txt","w",stdout);
	srand(time(0));
	int val;
	CMinHeap<int> heap(10);
	for (int i=1;i<=15;i++){
		try{
			val = rand()%3;
			if (val<2){
				val = rand()%100;
				cout << setw(2) << val << " is inserted\n";
				heap.push(val);
			}
			else{
				// val = heap.pop();
				cout << setw(2) << val << " is removed\n";
			}
		}catch(char *e){
			cout << e;
			i--;
		}
	}
	// heap.push(10);
	// heap.push(12);
	// heap.push(1);
	// heap.push(17);
	// heap.push(7);
	// heap.show();
	while (!heap.isEmpty()){
		// cout << setw(2) << heap.pop() << " is removed\n";
	}

	return 0;
}