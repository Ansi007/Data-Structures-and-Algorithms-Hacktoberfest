
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        
      
      //creating a map to store all the elements with their frequencies.
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
          //       then we will iterate through the map and display the 1st element with frequency same as k
            if(m[a[i]] == k){
                return a[i];
                break;
            }
        }
        return -1;
    }
};


int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
