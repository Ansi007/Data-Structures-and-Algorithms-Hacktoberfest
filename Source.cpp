#include<iostream>
using namespace std;
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}
}
int getMedian(int* array1, int* array2, int n)
{
	int i = 0;
	int x = 0;
	if (n == 1)
	{
		x = (max(array1[0], array2[0]), min(array1[1], array2[1])) / 2;
		cout << "\t" << x;
	}
	else {
		i = n / 2;
		int* temp1 = new int[i + 1];
		int* temp2 = new int[i + 1];
		if (array1[i] < array2[i])
		{
			for (int j = 0; j < i; j++)
			{
				temp1[j] = array1[i + j];
				temp2[j] = array2[j];
			}
		}
		else if (array1[i] > array2[i])
		{
			for (int j = 0; j < i; j++)
			{
				temp1[j] = array1[j];
				temp2[j] = array2[i + j];
			}
		}
		int x = 0;
		x=getMedian(temp1, temp2, i);
		return x;
	}
}
int main()
{
	int i = 0;
	cout << "enter the number of elements to be entered : " << "\t";
	cin >> i;
	int* arr1 = new int[i];
	int* arr2 = new int[i];
	cout<<"enter the elements of array 1 : "<<"\t";
	for (int j = 0; j < i; j++)
	{
		cin >> arr1[j];
	}
	cout << "enter the elements of array 2 : " << "\t";
	for (int j = 0; j < i; j++)
	{
		cin >> arr2[j];
	}
	cout << endl;
	cout << "the median of two array is : " << "\t";
	getMedian(arr1, arr2, i);
	return 0;

}