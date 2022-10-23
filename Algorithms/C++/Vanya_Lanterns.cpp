#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double Vanya_Lanterns(vector<int>a, int last){
    double diff,max;
    sort(a.begin(),a.end());
    max=a[0]/1.0;
    for(int i=0;i<a.size()-1;i++){
        diff=a[i+1]-a[i];
        diff=diff/2;
        if(diff>max)
            max=diff;
    }
    if(a[a.size()-1]!=last){
        diff=last-a[a.size()-1];
        if(diff>max)
            return diff/1;
    }
        return max;
}

int main()
{
    int p,q,num;
    double ans;
    cin >> p;
    cin >> q;
    vector<int>a;
    for(int i=0;i<p;i++){
        cin >> num;
        a.push_back(num);
    }
    ans=Vanya_Lanterns(a,q);
    cout << fixed << setprecision(10) << ans;
    return 0;
}