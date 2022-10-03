#include "Stack.cpp"
using namespace std;

bool checkParenthesis(char *exp){
	Stack <int> stack(100); 
	try{
		for (int i=0;exp[i]!=0;i++)
			if (exp[i] == '(')
				stack.push(1);
			else if (exp[i] == ')')
				stack.pop();	
	}catch(int i){
		return false;
	}
	return stack.isEmpty();
}
int main(){
	char exp1[100]="sdkjffsd(dsjkdskfjsd(dksdjsksda)dsfjkds)dsdds(dsfdsj)dsfsd";
	char exp2[100]="sdkjffsd(dsjkdskfjsd(dksdjsksda)dsfjkdsdsdds(dsfdsj)dsfsd";
	char exp3[100]="sdkjffsd(dsjkdskfjsd(dksdjsksda)dsfjkds)dsdds(ds)fd)sj)dsfsd";
	if (checkParenthesis(exp1))	cout << "Expression is Valid\n";
	else 						cout << "Expression is Invalid\n";
	if (checkParenthesis(exp2))	cout << "Expression is Valid\n";
	else 						cout << "Expression is Invalid\n";
	if (checkParenthesis(exp3))	cout << "Expression is Valid\n";
	else 						cout << "Expression is Invalid\n";
	return 0;
}
