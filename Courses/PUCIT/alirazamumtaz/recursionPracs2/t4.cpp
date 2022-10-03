/*
Write a recursive function to compute the binomial coefficient according to the definition.

𝑛
𝑘

1 				𝑖𝑓 𝑘 = 0 𝑜𝑟 𝑘 = 𝑛

𝑛 − 1 +  n
  𝑘 	k - 1	𝑜𝑡ℎ𝑒𝑟𝑤𝑖𝑠𝑒

i.e, 	6 3 = 20
*/

#include<iostream>
#include <string>

using namespace std;
long long binomialCoefficient(int n, int k){
	if( k == 0 or k == n) return 1;
	return binomialCoefficient(n-1,k) + binomialCoefficient(n-1, k-1);
}
long long binomialCoefficientDP(int n, int k, int **arr){
	if( k == 0 or k == n) return 1;
	if( arr[n][k]) return arr[n][k];
	else 
		return binomialCoefficient(n-1,k) + binomialCoefficient(n-1, k-1);

}
long long binomialCoefficientDP(int n, int k){
	int **arr = new int*[n+1];
	for (int i = 0; i <= n; ++i){
		arr[i] = new int[k+1];
		for (int j = 0; j <= k; ++j)
			arr[i][j] = 0;
	}
	return binomialCoefficientDP(n,k,arr);
}
int main(int args, char** argv){
	cout << "with out Dynamic programming: "<< binomialCoefficient(11,6) << '\n';
	cout << "with Dynamic programming: "<< binomialCoefficientDP(11,6) << '\n';
	cout << "\nDone with this program.\n";
	return 0;
}