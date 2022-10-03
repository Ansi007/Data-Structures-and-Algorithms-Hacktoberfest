/*
Given an array of integers, compute recursively if the array contains somewhere a value followed in
the array by that value times 10. We'll use the convention of considering only the part of the array that
begins at the given index. In this way, a recursive call can pass index+1 to move down the array. The
initial call will pass in index as 0.
array220([1, 2, 20],3) 					TRUE
array220([3, 30],2) 					TRUE
array220([3, 3, 30, 4], 4) 				TRUE
array220([20, 2, 21, 210],4) 			TRUE
array220([1, 2, 3, 4, 5, 6],6) 			FALSE
array220([1, 2, 3, 4, 5, 50, 6],7) 		TRUE
array220([1, 2, 3, 4, 4, 50, 500, 6],8) TRUE
*/

#include <iostream>
#include <algorithm>

void stale_flippant() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
// bool isExist(int arr[], int size, int val) //bubble sort
// {
//     int start=0, end=size, mid = (start + end)/2;
//     while(start<=end){
//         mid = (end + start)/2;
//         if(val == arr[mid]) return true;
//         if(val>mid) start = mid+1;
//         else end	= mid-1;
//     }
//     return false;
// }

bool isExist(int arr[], int start, int end, int val){
	if(start>end) return false;
	int mid = (start+end)/2;
	if(val == arr[mid]) return true;
	if(val>mid) return isExist(arr,mid+1,end,val);
	else return isExist(arr,start,mid-1,val);
}
bool isExist(int arr[], int size, int val) //bubble sort
{
   return isExist(arr,0,size,val);
}
bool array220(int *arr,int size){
	std::sort(arr,arr+size);
	int key;
	for (int i = 0; i < size; ++i){
		key = arr[i]*10;
		for (int j = i; j < size; ++j){
			if(isExist(arr,size,key)){
				std::cout << key << ':' << arr[j] << '\n';
				return true;			
			}
		}
	}
	return false;
}
// bool array220(int n){
// 
// }
int main(){
	int size;
	std::cout<<"Enter size: ";
	std::cin >> size;
	int *arr = new int[size];
	std::cout<<"Enter "<<size<<" elements: ";
	for (int i = 0; i < size; ++i)
		std::cin>>arr[i];
	if(array220(arr,size))
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	delete []arr;
	arr = nullptr;
	return 0;
}