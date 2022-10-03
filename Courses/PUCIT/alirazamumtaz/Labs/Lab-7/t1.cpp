#include <iostream>
#include "Stack.cpp"

using namespace std;
/*
A large array of integers contains lists inside. Lists have positive integers and -1 indicates separators
in between the lists. There must exist -1 at start and end of the array. You are required to print
these lists in reverse order that is start printing from last list, but you have to print each list from
start to end. See example carefully:
Array has two lists:
-1 23 59 37 -1 46 64 -1
Output:
46 64
23 59 37
*/
void printListRev(int *arr, int n){
	Stack <int>	st;
	int temp;
	for (int i = n-1; i >= 0; --i){
		do{
			if(arr[i] == -1){
				while(!st.isEmpty())	cout << st.pop() << ' ';
				cout << '\n';
			}
			else st.push(arr[i]);
		}while(!arr[i] == -1);
	}
}

int main(int argc, char const *argv[]){
	int *arr, size;
	cout << "Enter Size of array: ";
	cin >> size;
	arr = new int [size];
	cout << "Enter values of array: ";
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	printListRev(arr,size);
	return 0;
}