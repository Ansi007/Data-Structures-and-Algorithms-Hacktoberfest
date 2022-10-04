// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Qusetion Given an integer array return true if the given array is monotonic false otherwise?
#include <iostream>
using namespace std;
bool CheckMonotonic(int* arr,int length)
{
	bool IsMonoticIncreasing = false;
	bool IsMonoticDecreasing = false;
	for (int i = 0;i < length-1;i++)
	{
		if (arr[i] > arr[i + 1])
		{
			IsMonoticDecreasing = true;
			if (IsMonoticIncreasing == true)
			{
				return false;
			}
		}
		else if (arr[i] < arr[i+1])
		{
			IsMonoticIncreasing = true;
			if (IsMonoticDecreasing == true)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int i,n;
	cout << "Enter the size of array:\n";
	cin >> n;
	int* arr = new int[n];
	for (i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	bool check=CheckMonotonic(arr,n);
	cout << check;


	//another method implemented in js
	
	//const checkMonotonic = function(array) {
	//	const first = array[0];
	//	const last = array[array.length - 1];
	//	// 1.......10
	//	if (first == = last) {
	//		for (let i = 0;i < array.length - 1;i++) {
	//			if (array[i + 1] != = array[i]) return false;
	//		}
	//	}
	//	else if (first < last) {
	//		// non decreasing
	//		for (let i = 0;i < array.length - 1;i++) {
	//			if (array[i + 1] < array[i]) return false;
	//		}
	//	}
	//	else {
	//		// non increasing
	//		for (let i = 0;i < array.length - 1;i++) {
	//			if (array[i + 1] > array[i]) return false;
	//		}
	//	}
	//	return true;
	//}

	//checkMonotonic([9]);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
