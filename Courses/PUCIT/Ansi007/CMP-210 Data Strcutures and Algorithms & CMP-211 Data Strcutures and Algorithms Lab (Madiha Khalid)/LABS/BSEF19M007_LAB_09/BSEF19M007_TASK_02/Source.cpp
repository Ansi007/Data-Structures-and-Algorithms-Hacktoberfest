#include<iostream>


using namespace std;

/*
returnMax: Return the max value found in arr.
:param: Array, iterator, Array size.
:return: Max value in array.
*/

int returnMax(int arr[], int i, int size) {

	if (i == size - 1)	//if reached last
		return arr[i];

	int max = returnMax(arr, ++i, size);

	if (max < arr[i - 1])	//Comparing two consecutive value.
		max = arr[i - 1];

	return max;
}

int main() {

	int* arr, size;

	cout << "=> Give size of array: "; cin >> size;
	arr = new int[size];

	cout << "=> Give array: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "=> The max value in the array is: " << returnMax(arr, 0, size);

	return 0;
}
