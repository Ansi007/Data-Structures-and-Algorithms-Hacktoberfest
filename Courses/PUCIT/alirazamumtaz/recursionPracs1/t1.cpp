/*
1. Given a non-negative integer, return the count of the
occurrences of 7 as a digit, so for example 717 has 2
occurrences of digit 7. Note that mod (%) by 10 yields the
rightmost digit (126 % 10 is 6), while divide (/) by 10 removes
the rightmost digit (126 / 10 is 12).
*/

#include <iostream>

// int countN(unsigned int n, int k){
// 	int count = 0;
// 	while(n>0){
// 		if(n % 10 == k)
// 			count++;
// 		n /= 10;
// 	}
// 	return count;
// }

int countN(unsigned int n, int k){
	static int count = 0;
	if(n>0){
		if(n % 10 == k)
			count += 1;
		countN(n / 10,k);
	}
	return count;
}
int main(int argc, char** argv){
	unsigned int n, k;
	if(argc>1){
		n = atoi(argv[1]);
		k = atoi(argv[2]);
	}
	else{
		std::cout<<"Enter number: ";std::cin>>n;
		std::cout<<"Enter digit to count: ";std::cin>>k;
	}
	int count = countN(n,k);
	std::cout << "Count of " << k << " is: " << count << '\n';
	return 0;
}