#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;  

bool check_prime(long long a){
    long long j,save=-1;
    for(j=2;j*j<=a;j++){  
        if(a%j==0) 
            return false; 
    }
    return true;
}

int main()  
{  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,a;
    cin >> n;  
    for(long long i=0;i<n;i++){
        cin >> a;
        long long square_root = sqrt(a);
        if(a==1 || a==0)
            cout << "NO" << endl;
        else if(a==4)
            cout << "YES" << endl;
        else if(square_root*square_root==a && check_prime(square_root))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;  
}  