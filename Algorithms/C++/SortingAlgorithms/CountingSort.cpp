#include<iostream>

using namespace std;

int* CountingSort(int* a , int k){
    int* arr;
    arr = new int[k+1];
    int i , j  , l = 0;
    for(i = 0 ; i< k+1 ;i++)
        arr[i] = 0;
    for(i = 0 ; i<=k ; i++)
        arr[a[i]]++;
    
    for(i =0 ; i <= k ; i++ ){
        if(arr[i]!= 0){
            j =0;
            while(j<arr[i]){
                //cout<<i<<" ";
                a[l++] = i;
                j++;
        }
            }
    }
    return a;
}

int main(){
    int a[10] = {3,4,6,5,1,1,4,0,9,7};
    int* arr = CountingSort(a , 10);
    int i ;
    for(i = 0 ; i< 10 ; i++)
     cout<<a[i]<<" ";
    return 0;
}