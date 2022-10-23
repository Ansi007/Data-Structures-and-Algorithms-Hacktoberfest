#include <bits/stdc++.h> 
using namespace std;
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
                min=j;
        }
        swap(arr[min],arr[i]);
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
    selectionSort(arr,n);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
