#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

long long Cheap_Travel(long long n, long long m, long long a, long long b){
    long long second=(n/m)*b;
    if((second+(n%m)*a)<(second+b))
        second=second+(n%m)*a;
    else 
        second=second+b;
    if((n*a)<=second)
        return n*a;
    else 
        return second;
}

int main()
{
    long long n,m,a,b,ans;
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;
    ans=Cheap_Travel(n,m,a,b);
    cout << ans;
    return 0;
}