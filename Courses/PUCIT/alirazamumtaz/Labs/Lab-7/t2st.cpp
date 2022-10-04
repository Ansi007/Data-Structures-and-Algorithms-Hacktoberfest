#include <iostream>
#include <cmath>
#include "Stack.cpp"
/*
Write a function to print divisor(s) of a composite number. You have to print divisor of divisors as
well, unless number is not further divisible. See example(s) carefully:
Note: In case of square print divisor one time only:
a. 16
Divisor of 16 : 2 , 8
Divisor of 8 : 2 , 4
Divisor of 4 : 2
b. 64y
Divisor of 64 : 2 , 32
Divisor of 32 : 2 , 16
Divisor of 16 : 2 , 8
Divisor of 8 : 2 , 4
Divisor of 4 :2
c. 49
Divisor of 49:7
*/
using namespace std;
bool isPerfectSquare(int n){
    for (int i = 1; i * i <= n; i++) {
        if ((n % i == 0) && (n / i == i)) {
            return true;
        }
    }
    return false;
}
void printDivisors(int n, int d){
	if(n == 2) return;
	if(n%d != 0) return;
	cout << "Divisor of " << n << " :";
	cout << d;
	if((n/d) > d) cout  << " , " << n/d << '\n';
	printDivisors(n/d,2);
}
void printDivisors(int n){
	Stack <int> stack(n);
	if(isPerfectSquare(n) and n%2 != 0)
		cout << "Divisor of " << n << " : " << sqrt(n) << '\n';
	else{
		while(true){
			if(n == 2) return;
			for (int i = 2; i <= n/2; ++i){
				if(n%i == 0){
					cout << "Divisor of " << n << " :";
					cout << i;
					if((n/i) > i) cout  << " , " << n/i << '\n';
					n /= i;
					break;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int n; cin >> n;
	printDivisors(n);
	return 0;
}