#include<iostream>

using namespace std;

/*
binarySearch: Search particular element in the sorted array.
:param: Array, Starting Index, Ending Index, Value to be found.
:return: index if found else -1
*/


int binarySearch(int arr[], int start_index, int end_index, int find) {


	int mid_index = start_index + (end_index - start_index) / 2; // Computing middle mid_index

	if (end_index < start_index)	// if not found
		return -1;

	else {
		if (find == arr[mid_index]) 	// if found
			return mid_index;

		else if (find < arr[mid_index])
			return binarySearch(arr, start_index, mid_index - 1, find);	//Left side of the array

		else
			return binarySearch(arr, mid_index + 1, end_index, find);	//Right side of the array
	}

}



int main() {


	int* arr, size, find;
	cout << "=> Give size of the array: "; cin >> size;
	arr = new int[size];

	cout << "=> Give array: ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "=> Give the value you want to find in the array: "; cin >> find;

	int found_index = binarySearch(arr, 0, size - 1, find);

	if (found_index == -1)
		cout << "=> " << find << " not found. " << endl;

	else cout << "=> " << find << " found at index " << found_index << ". " << endl;

	return 0;
}




