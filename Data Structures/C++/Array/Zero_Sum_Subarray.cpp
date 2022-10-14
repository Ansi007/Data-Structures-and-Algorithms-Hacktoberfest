#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    public:
  
    ll findSubarray(vector<ll> a, int n ) {
       int cnt=0;
       int sum=0;
       unordered_map<int,int>mpp;
       mpp[0] = 1;
       for(int i=0;i<n;i++){
            sum+=a[i];
            if(mpp.find(sum)== mpp.end()) mpp[sum]++;
            else{
                cnt+=mpp[sum];
                mpp[sum]++;
           }
           
       }
       return cnt;
    }
};


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; 
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
