#include <iostream>
#include "Stack.cpp"

using namespace std;

void printAdditiveDivisions(int n,int p,bool* check){
}
void printAdditiveDivisions(int n){
	bool check[n]={false};
	Stack <int> st(n);
	while(n > 1){
		int rem = n/2;
		st.push(rem);
		cout << n << " : " << n-rem << " + " << rem << '\n';
		n = n-rem;
		check[n] = true;
	}
	while(!st.isEmpty()){
		n = st.pop();
		while(n > 1 and !check[n]){
			int rem = n/2;
			st.push(rem);
			cout << n << " : " << n-rem << " + " << rem << '\n';
			n = n-rem;
			check[n] = true;
		}
	}
}

int main(int argc, char const *argv[]){
	printAdditiveDivisions(37);
	return 0;
}