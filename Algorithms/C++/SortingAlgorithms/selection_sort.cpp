//Cpp program for selection sort algorithm.

#include<iostream>
using namespace std;
#define MAX 100

void swap(int *a, int *b){

	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(){

	int array[MAX], n;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the array elements\n";
	for(int i = 0; i < n; i++){
	
		cin>>array[i];
	}
	
	for(int i = 0; i < n-1; i++){// till second last element
	
		int min = i;
		for(int j = i+1; j < n; j++){//till last element
		
			if(array[j] < array[min])
				min = j;
		}
		
		if(min!=i)
			swap(&array[min], &array[i]);	
	}
	
	printf("The sorted array is \n");
	for(int i = 0; i < n; i++){
	
		cout<<array[i]<<endl;
	}	
	
}