//https://www.youtube.com/channel/UCJEPLDddB_FZv2ATOTs6gRA
//#ub

//Quick Sort
#include <iostream>

using namespace std;

/* Partition the list into two halves based 
   on pivot and return partition index */
int partition(int A[], int left, int right)
{
	int l = left, r = right;
	int p = left; //Choosing first element as pivot

	//Partition based on p (pivot)
	while (l < r)
	{
		while (A[l] <= A[p] && l < r)
			l++;

		while (A[r] > A[p])
			r--;

		if (l < r)
		{
			swap(A[l], A[r]);
		}
	}

	swap(A[r], A[p]);
	//Partitioning end

	return r;
}

//Quick Sort
void quickSort(int A[], int left, int right)
{
	if (left < right)
	{
		//pi is Partition Index
		int pi = partition(A, left, right);
		cout << pi << endl;
		//Recursive calls
		//quickSort(A, left, pi - 1);	 //for left array having smaller values from pivot
		//quickSort(A, pi + 1, right); //for right array having greater values from pivot
	}
}

int main()
{
	int n = 10;
	int A[] = {41, 79, 65, 35, 21, 48, 59, 87, 52, 28};

	cout << "List:\t\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}

	cout << endl;

	cout << partition(A, 0, 9);

	cout << "Sorted List:\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}

	cout << endl
		 << endl;

	return 0;
}