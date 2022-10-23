#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
	cin>>n;
	int res = 0;
	while(n>0) {
		res++;
		n /= 10;
	}
	
	cout<<"Number of digit is: "<<res;
	return 0;
}
