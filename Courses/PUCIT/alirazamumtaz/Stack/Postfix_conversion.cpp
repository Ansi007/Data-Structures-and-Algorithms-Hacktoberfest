#include "Stack.cpp"
using namespace std;

char* convertToPostFix(char *exp){
	Stack <char> stack(100); 
	char *postFix = new char[100] , temp;
	int j = 0;
	for (int i=0;exp[i]!=0;i++){
		//-------------------------------------------------------------------
		if (exp[i] == '(')								stack.push('(');

		else if (exp[i] >= '0' && exp[i] <= '9' )		postFix[j++]=exp[i];

		else if  (exp[i] == ')')
			do{
				temp = stack.pop();
				if (temp=='(')							break;
				postFix[j++] = temp;
			}while (!stack.isEmpty());
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
			while (!stack.isEmpty()){
				temp = stack.seeTop();
				if (temp == '(')						break;
				if (exp[i] == '+' || exp[i] == '-' )
					postFix[j++] = stack.pop();
				if ( ( exp[i] == '*' || exp[i] == '/' ) && (temp == '*' || temp == '/')	)
					postFix[j++] = stack.pop();
				else									break;	
			}
			stack.push(exp[i]);
		}
	//------------------------------------------------------------------------------
	}
	while (!stack.isEmpty())
		postFix[j++] = stack.pop();
	postFix[j] = 0; 
	return postFix;
}
int evaluate(int n1, int n2, char op){
	switch(op){
		case '+':	return n1 + n2;
		case '-':	return n1 - n2;
		case '*':	return n1 * n2;
		default:	return n1 / n2;
	}
}
int evaluatePostFix(char *exp){
	Stack <int> stack(100); 
	int n1, n2;
	for (int i=0;exp[i]!=0;i++)
		if (exp[i] >= '0' && exp[i] <= '9' )		stack.push(exp[i]-'0'); //Convert character digit into number digit
		else{
			n2 = stack.pop();
			n1 = stack.pop();
			stack.push(evaluate(n1, n2, exp[i]));
		}
	return stack.pop();
}
int main(){
	char exp1[100]="2+3*5";
	char exp2[100]="(2+3)*5";
	char exp3[100]="(2+3)*5+8*(6-4)*7";
	cout << exp1 << " Post fix expression:" << convertToPostFix(exp1) << '\n';
	cout << exp2 << " Post fix expression:" << convertToPostFix(exp2) << '\n';
	cout << exp3 << " Post fix expression:" << convertToPostFix(exp3) << '\n';
	cout << exp1 << " Post fix expression:" << evaluatePostFix(convertToPostFix(exp1) )<< '\n';
	cout << exp2 << " Post fix expression:" << evaluatePostFix(convertToPostFix(exp2) )<< '\n';
	cout << exp3 << " Post fix expression:" << evaluatePostFix(convertToPostFix(exp3) )<< '\n';
	return 0;
}
