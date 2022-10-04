#include <iostream>

using namespace std;

class MaxHeap{
	int size, currentSize;
	int* data;
public:
	MaxHeap(int size=0){
		this->size = size;
		currentSize = 0;
		data = new int[size];
	}
	~MaxHeap(){
		delete []data;
	}
	
	void add(int d){
		data[currentSize++];
		for(int i = 0; i<currentSize; i++){
			if(d <)
		}
		cout << "Task with priority "<< d <<" is added\n";
	}
	int remove(){
		int temp = data[0];
		data[0] = data[currentSize--];
		cout << "Task with priority "<< temp <<" is removed\n";
		return temp;
	}
	
};

int main(int argc, char const *argv[]){
	MaxHeap h(5);
	h.add(32);
	h.add(34);
	h.add(44);
	h.add(28);
	h.remove();
	h.add(21);
	h.remove();
	return 0;
}