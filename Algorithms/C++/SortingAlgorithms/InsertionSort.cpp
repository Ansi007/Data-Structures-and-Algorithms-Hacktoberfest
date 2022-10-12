#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void insertion_sort(int *array, int size)
{
	int i, j, key;
	for(i = 1; i < size; i++)
	{
		key = array[i];
		for(j = i - 1; j >= 0 && array[j] > key; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = key;
	}
}

int main()
{
	srand(time(0));
	int size;
    cout << "Enter list size: ";
	cin >> size;
    int *array = new int [size];
	for(int i = 0; i < size; i++)
		array[i] = rand() % 90 + 10;
	cout << "\nUnsorted List:\n";
	for(int i = 0; i < size; i++)
		cout << array[i] << ' ';
    insertion_sort(array, size);
    cout << "\n\nSorted List:\n"; 
    for(int i = 0; i < size; i++)
		cout << array[i] << ' ';   
    return 0;
}