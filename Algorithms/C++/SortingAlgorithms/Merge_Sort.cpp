//https://www.youtube.com/channel/UCJEPLDddB_FZv2ATOTs6gRA
//#ub

//Merge Sort
#include <iostream>

using namespace std;

//Merge
void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1; //size of left sub array
	int n2 = right - mid;	 //size of right sub array

	/* create temporary arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temprary arrays L and R */
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];

	for (int i = 0; i < n2; i++)
		R[i] = A[mid + 1 + i];

	/* Merge the temporary arrays back into original array A from left till right*/
	int i = 0, j = 0, k = left; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of Left(L) array, if there are any */
	while (i < n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of Right(R) array, if there are any */
	while (j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}

	// Free temporary arrays
	delete[] L;
	delete[] R;
}

//Merge Sort
void mergeSort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(A, left, mid);	  //left half
		mergeSort(A, mid + 1, right); //right half
		merge(A, left, mid, right);	  //merge the elements
	}
}

int main()
{
	int A[] = {38, 27, 43, 3};

	mergeSort(A, 0, 9);

	//display the array content
	for (size_t i = 0; i < 10; i++)
	{
		cout << A[i] << endl;
	}

	return 0;
}