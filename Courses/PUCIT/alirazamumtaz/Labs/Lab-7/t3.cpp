/*
Write a function to check correctness of given expression. The expression is stored in character
array and have all types of brackets, i.e. small, medium &amp; large. You have to check order of
brackets. See example(s) carefully:
a. [x+{(y+z)*(y-x)+((x+y(2*z)))}] is correct expression
b. {(y+z)*(y-x)]  is incorrect expression or
c. (X+y)) is incorrect
*/

#include <iostream>
#include "Stack.cpp"

using namespace std;


char parenthesis[2][3] = {
	{'[' , '{', '('},
	{']', '}', ')'}
};
char openingPren(char pren){
	for (int i = 0; i < 3; ++i){
		if(pren == parenthesis[1][i])
			return parenthesis[0][i];
	}
}

bool isExist(char val, char* arr, int size){
	for (int i = 0; i < size; ++i){
		if(arr[i] == val) return true;
	}
	return false;
}

bool checkParenthesis(char *exp){
	Stack <char> stack(100); 
	try{
		for (int i=0;exp[i]!=0;i++)

			if (isExist(exp[i],parenthesis[0],3))
				stack.push(exp[i]);

			else if (isExist(exp[i],parenthesis[1],3)){
				if(stack.seeTop() != openingPren(exp[i])) return false;
				stack.pop();
			}
	}catch(int i){
		return false;
	}
	return stack.isEmpty();
}
int main(int argc, char const *argv[]){
	char exp1[100]="[x+{(y+z)*(y-x)+((x+y(2*z)))}]";
	char exp2[100]="{(y+z)*(y-x)]";
	char exp3[100]="(X+y))";
	if(checkParenthesis(exp1))
		cout << exp1 << " is correct expression.\n";
	else
		cout << exp1 << " is incorrect expression.\n";
	if(checkParenthesis(exp2))
		cout << exp2 << " is correct expression.\n";
	else
		cout << exp2 << " is incorrect expression.\n";
	if(checkParenthesis(exp3))
		cout << exp3 << " is correct expression.\n";
	else
		cout << exp3 << " is incorrect expression.\n";
	return 0;
}