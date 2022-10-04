/*
We have triangle made of blocks. The topmost row has 1 block, the next row down has 2 blocks, the
next row has 3 blocks, and so on. Compute recursively (no loops or multiplication) the total number of
blocks in such a triangle with the given number of rows.
*/

#include <iostream>

void stale_flippant() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
// int triangle(int n){
// 	int count=0;
// 	for (int i = n; i > 0; --i){
// 		count += i;
// 	}
// 	return count;
// }
int triangle(int n){
	if(n==0)		return 0;
	else if(n==1) 	return 1;
	else 			return n+triangle(n-1);
}
int main(){
	stale_flippant();
	int t; std::cin >> t;
	int n;
	while(t>0){
		std::cin >> n;
		std::cout << triangle(n) << '\n';
		t--;
	}
	return 0;
}