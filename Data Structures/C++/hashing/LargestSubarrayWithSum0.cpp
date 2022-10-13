#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> m;
        int maxi=0;
        int pre_sum=0;
        for(int i=0;i<n;i++){
            pre_sum += A[i];
            if(pre_sum == 0){
                maxi = i+1;
            }
            else{
                if(m.find(pre_sum) != m.end()){
                    maxi = max(maxi, (i - m[pre_sum]));
                }
                else{
                    m[pre_sum]= i;
                }
            }
        
            
        }
        return maxi;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}

