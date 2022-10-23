#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Array {
	int *a , size , length ;
	
public:
	Array (int size ) {
		this->size = size ;
		a = new int [size] ;
		length = 0 ;
	}
	
	void addelement(int e) {
		if (length < size) 
			a[length++] = e;
		else cout << "Not enough space to add " << e << endl ;
		
	}
	
	
	void insertelement(int index , int element) {
		int i;
		if (index > length) cout << cout << "Index out of bound.\n" ; 
		else if (length < size ) {
			
			for (i = length - 1 ; i > index -1; i--) 
				a[i + 1] = a[i] ;	
			a[index] = element ;
			length ++ ;
		}
		else cout << "Not enough space to insert " << element << endl ;
	}
	
	int deleteelement(int index) {
		int i , element;
		if (index > length) return -1 ;
		else {
			element = a[index] ;
		for (i = index ; i < length - 1 ; i++) 
			a[i] = a[i+1] ;
		length -- ;
		return element ;
		}
		
	}
	
	void reverse () {
		int i , j , temp;
		for (i = 0 , j = length - 1 ; i < j ; i++ , j--) 
			swap(a[i] , a[j]) ;
	}
		
	Array merge( Array &a1) {
		Array arr(length + a1.length) ;
		arr.length = length + a1.length ;
		int i  = 0 , j = 0 , k = 0;
		while (i < length and j < a1.length ) {
			if (a[i] < a1.a[j]) 
				arr.a[k++] = a[i++] ;	
			else if (a[i] > a1.a[j]) arr.a[k++] = a1.a[j++] ;
			else {
				arr.a[k++] = a[i++] ;
				arr.a[k++] = a1.a[j++] ;
			}
		}
		for (;i < length ; i++) 
			arr.a[k++] = a[i] ;
		for (;j < a1.length ; j++) 
			arr.a[k++] = a1.a[j] ;
		return arr ;
	}
	 
	Array unionarr( Array &a1) {
		Array arr(length + a1.length) ;
		int i , j  , k ;
		i = j = k = 0 ;
		while (i < length and j < a1.length ) {
			if (a[i] < a1.a[j]) 
				arr.a[k++] = a[i++] ;
			else if (a[i] > a1.a[j]) arr.a[k++] = a1.a[j++] ;
			else {
				arr.a[k++] = a[i++] ;
				j++ ;
			}
		}
		for (;i < length ; i++) 
			arr.a[k++] = a[i] ;
		for (;j < a1.length ; j++) 
			arr.a[k++] = a1.a[j] ;
		arr.length = k  ;
		return arr ;
	}
 
	Array intersection( Array &a1) {
		Array arr(length) ;
		int i , j  , k ;
		i = j = k = 0 ;
		while (i < length ) {
			if (a[i] == a1.a[j]) {
				arr.a[k++] = a[i++] ;	
				j++;
			}
				
			else if (a[i] > a1.a[j]) j++ ;
			else if (a[i] < a1.a[j]) i++ ;
			
		}
		arr.length = k  ;
		return arr ;
	}

	Array differenciation( Array &a1) {
		Array arr(length + a1.length) ;
		int i , j  , k ;
		i = j = k = 0 ;
		while (i < length and j < a1.length ) {
			if (a[i] == a1.a[j]) {
				i++;
				j++;
			}	
			else if (a[i] < a1.a[j]) 
				arr.a[k++] = a[i++] ;	
			else if (a[i] > a1.a[j]) 
				arr.a[k++] = a1.a[j++] ;
			
		}
		for (;i < length ; i++) 
			arr.a[k++] = a[i] ;
		for (;j < a1.length ; j++) 
			arr.a[k++] = a1.a[j] ;
		arr.length = k  ;
		return arr ;
	}
	
	int binarysearch (int element) {
		int low = 0 , high = length - 1 , mid ;
		while (low <= high ) {
			mid = (low + high) / 2;
			if (a[mid] == element) return mid;
			else if (a[mid] < element) low = mid + 1;
			else high = mid - 1;
		}
		return -1;
	}
	void print() {
		cout << "Elements of array are: " << endl ;
		for (int i = 0 ; i < length ; i++)
			cout << a[i] << ' ' ;
		cout << endl ;
	}
};

int main() {
	int size , del , index , i , element , choice;
	Array res(20);
	cout << "Enter array size:" ;
	cin >> size ;
	Array a (size) ;
	cout << "Enter elements of array. Enter -1 if you want to terminate before array is filled\n" ;
	for (i = 0 ; i < size ; i++){
		cin >> element;
		if (element == -1 ) break ;
		else
			a.addelement(element) ;
	}
	a.print();
	cout << "Enter size of second array:" ;
		cin >> size ;
		Array b(size);
		cout << "Enter elements of array. Enter -1 if you want to terminate before array is filled\n" ;
		for (i = 0 ; i < size ; i++){
			cin >> element;
			if (element == -1 ) break ;
			else
				b.addelement(element) ;
		}
		b.print();
	cout << "MEnu\n" ;
	cout << "1.Add element\n2.Delete element\n3.Insert element\n4.Search Element\n5.Reverse Array\n6.Merge Arrays\n7.Union of Arrays\n8.Intersection of Arrays\n" ;
	cout << "9.Diffrenciation of arrays\nEnter choice" ; 
	cin >> choice ;

	
	if (choice == 1) {
		cout << "Enter element to add: " ;
		cin >> element ;
		a.addelement(element) ;
	}
	else if (choice == 2) {
		cout << "Enter index of element to delete: " ;
		cin >> index ;
		del = a.deleteelement(index);
	if (del == -1) cout << "Index out of bound\n" ;
	else
		cout << "Deleted element is " << del << endl;
	}
	if (choice == 3) {
		cout << "Enter element to insert: " ;
		cin >> element ;
		cout << "Enter index: " ;
		cin >> index;
		a.insertelement(index,element) ;
	}
	if (choice == 4) {
		cout << "Enter element to search: " ;
		cin >> element ;
		index = a.binarysearch(element) ;
		if (index == -1) cout << "Element not found\n" ;
		else cout << "Element is found at index " << index << endl ;
	}
	if (choice == 5) 
		a.reverse() ;
	if (choice == 6) 
		res = a.merge(b) ;
	if (choice == 7)
		res = a.unionarr(b) ;
	if (choice == 8) 
		res = a.intersection(b); 
	if (choice == 9)
		res = a.differenciation(b); 
	if (choice <= 5) a.print();
	else res.print();
	
}
