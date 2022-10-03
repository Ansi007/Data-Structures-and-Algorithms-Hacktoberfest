/*
Given a non-negative integer, return the sum of
its digits recursively (no loops). Note that mod (%)
by 10 yields the rightmost digit (126 % 10 is 6),
while divide (/) by 10 removes the rightmost digit
(126 / 10 is 12).
*/

#include<iostream>

using namespace std;
int digitSum(int n){
	static int sum=0;
	if(n == 0) return sum;
	sum += n%10;
	return digitSum(n/10);
}
int main(int args, char** argv){
	cout << digitSum(atoi(argv[1]));
	return 0;
}

/*
1267			sum=0
1267%10 = 7		sum += 7	1267/10 = 126
126%10 = 6		sum += 6	126/10 = 12
12%10 = 2		sum += 2	12/10 = 1
1%10 = 1		sum += 1	1/10 = 0
*/