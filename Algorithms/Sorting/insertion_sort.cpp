#include <bits/stdc++.h> 
using namespace std;
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i=1;i<n;i++)
    {
        int temp=arr[i],j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=temp;
    }
}
int main()
{
        int n,a;
        vector<int>arr;
        cout<<"Enter the size of array: ";
        cin>>n;
        cout<<"Enter the no. element in the array : "<< endl;
         for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    insertionSort(n,arr);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
