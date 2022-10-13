#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    long long maxSubarraySum(int arr[], int n){
        
        int current_sum =0;
        int largest_sum =INT_MIN;
        for(int i=0;i<n;i++){
            current_sum += arr[i];
            
             largest_sum = max(current_sum,largest_sum);
            
              if(current_sum<0)
               current_sum =0;
            
           
        }
        
        return largest_sum;
        
    }
};


int main()
{
    int t,n;
    
    cin>>t; 
    while(t--) 
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
