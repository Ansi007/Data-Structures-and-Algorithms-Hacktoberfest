#include <iostream>
using namespace std;
int main() {
    int t,n,k,instanceMax,maxx=0;
    cin>>t;
    while(t--){
        cin>>n>>k;
        maxx=0;
        for(int i=1;i<=k;i++){
            instanceMax = n%i;
            if(instanceMax > maxx){
                maxx = instanceMax;
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
