


//BSEF19M003
//LAIBA KAMAL


#include<iostream>
#include<string>
#include"MyStack.cpp"
using namespace std;

bool isBalanced(string);//returns 1 if the exp passed is BALANCED and 0 if the exp is UNBALANCED
string infixToPostfix(string);//converts from infix--> postfix and prints the postfix notation
double Evaluate(string, bool);//evaluates the prefix or postfix exp and prints the answer


int main()
{
	char c = 'y';//for while loop condition//if c='y', the loop will run//if c='n', the loop will terminate
	int check_invalid;//to check if the user has used invalid characters in the input expressions//gets incremented on each invalid character in the input string
	int choice;//to ask the user which function he wants to run //choice=1= is balanced function//choice=2=infix to postfix function//choice=3=expression evaluation function
	string exp;
	bool key = 0;

	while (c == 'y')//to run the program as many times as user wants
	{
		check_invalid = 0;
		cout << "MENU:\n1-Press 1 to check whether your expression is balanced or not.\n2-Press 2 to convert your infix expression to postfix expression.\n3-Press 3 to evaluate your expression.\n";//prints menu
		cin >> choice;


		//choice =1 : //isBalanced function call //takes input expression to check whether it is balanced or not
		//choice =2 : //infixToPostfix function call //takes input expression in infix notation, converts it to postfix and prints postfix
		//choice =3 : //Evaluate function call  //takes input expression in postfix/prefix notation, evaluates it and prints answer
		switch (choice)
		{
		case 1://takes input expression to check whether it is balanced or not
		{
			cout << "BALANCING:\nEnter a mathematical expression containig binary operators(+-*/) and brackets (){}[] to check whether it is balanced or not:\n";
			cin.ignore();
			getline(cin, exp);
			break;
		}
		case 2://takes input expression in infix notation
		{
			cout << "INFIX TO POSTFIX:\nEnter an infix mathematical expression containig binary operators(+-*/) and brackets (){}[] to convert it to postfix:\n";
			cin.ignore();
			getline(cin, exp);
			break;
		}
		case 3://takes input expression in postfix / prefix notation
		{
			cout << "EXPRESSION EVALUATION : \nEnter 0 if you wanna evaluate a prefix expression. Enter 1 if you wanna evaluate postfix expression: ";
			cin >> key;
			if (key == 0)
				cout << "Enter a SPACE TOKENIZED prefix expression to evaluate it:\nPLEASE ENTER A SPACE AFTER EACH UNIT OF EXPRESSION.\n";
			else if (key == 1)
				cout << "Enter a SPACE TOKENIZED postfix expression to evaluate it:\nPLEASE ENTER A SPACE AFTER EACH UNIT OF EXPRESSION.\n";
			else
				cout << "invalid key";
			cin.ignore();
			getline(cin, exp);
			break;
		}
		default:
			cout << "Invalid choice from menu!\n";
		}



	

		for (int i = 0; i < exp.length(); i++)//loop to check if the inputted expression has valid characters or not
		{
			//if (0-9) or (a-z) or (A-Z) or (opening brackets) or (closing brackets) or binary operators (+ - / *)
			if (((exp[i] >= '0') && (exp[i] <= '9')) || ((exp[i] >= 'a') && (exp[i] <= 'z')) || ((exp[i] >= 'A') && (exp[i] <= 'Z')) || (exp[i] == '(') || (exp[i] == ')') || (exp[i] == '{') || (exp[i] == '}') || (exp[i] == '[') || (exp[i] == ']') || (exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == ' '))
				check_invalid;//do nothing
			else
				check_invalid += 1;//invalid characters detected
		}


		if (check_invalid == 0)//if the expression is valid
		{
			bool balance = true;
			switch (choice)
			{
			case 1://isBalanced function call, to check whether exp is balanced or not
			{
				balance = isBalanced(exp);
				if (balance == 0)
					cout << "The given expression is UNBALANCED\n";
				else if (balance == 1)
					cout << "The given expression is BALANCED\n";
				break;
			}
			case 2: //infixToPostfix function call,  converts exp to postfix and prints postfix
			{
				balance = isBalanced(exp);
				if (balance == 0)
					cout << "The expression you entered is UNBALANCED, so it can not be converted to postfix notation.\n";
				else if (balance == 1)
					cout << "The equivalent postfix sxp is: "<<infixToPostfix(exp)<<endl;
				break;
			}
			case 3://Evaluate function is called, to evaluate the exp
			{
				cout << "Answer: " << Evaluate(exp, key)<<endl;
				break;
			}
			}
			cout << "\nEnter 'y' to run again and 'n' to end the program:";
			cin >> c;
		}
		else
			cout << "Invalid expression\n";

	}
	destruct = 1;
	return 0;
}











//BSEF19M003
//LAIBA KAMAL






//is Balanced func
 bool isBalanced(string exp)//returns 1 if the exp passed is BALANCED and 0 if the exp is UNBALANCED
{
	MyStack<string> s;

	if ((exp[exp.length() - 1] == '+') || (exp[exp.length() - 1] == '-') || (exp[exp.length() - 1] == '*') || (exp[exp.length() - 1] == '/'))//if an operator appears at the end
		return false;//exp is unbalanced

	else if ((exp[0] == '+') || (exp[0] == '-') || (exp[0] == '*') || (exp[0] == '/'))//if an operator appears in beginning of exp
		return false;//exp is unbalanced

	for (int i = 0; exp[i] != '\0'; i++)//parse through the given expression
	{
		//level 1
		if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))//if a binary operataor + - / *
		{
			if ((exp[i + 1] == exp[i]) || (exp[i + 1] == ')') || (exp[i + 1] == '}') || (exp[i + 1] == ']'))//if a unary operator appears
				return false;//exp is unbalanced
			else
			{
				//level 2
				if (exp[i] == '+')// if +
				{
					//level 3
					if (s.isEmpty())//if stack is empty
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else if ((s.peak() == "-") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is -[{( on top of stack
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else
					{
						while (true)//loop  to pop values 
						{
							//level 4
							if (s.isEmpty())//if stack is empty
							{
								break;
							}
							//level 4
							else if ((s.peak() == "*") || (s.peak() == "/") || (s.peak() == "+"))//if there is */+ on top of stack
							{
								s.pop();//pop
							}
							//level 4
							else
								break;
						}
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
				}



				//level 2
				else if (exp[i] == '-')//if -
				{
					//level 3
					if (s.isEmpty())//if stack is empty
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else if ((s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is [{( on top of stack
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else
					{
						while (true)
						{
							//level 4
							if (s.isEmpty())//if stack is empty
							{
								break;
							}
							//level 4
							else if ((s.peak() == "*") || (s.peak() == "/") || (s.peak() == "+") || (s.peak() == "-"))//if there is */+- on top of stack
							{
								s.pop();//pop
							}
							//level 4
							else
								break;
						}
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
				}



				//level 2
				else if (exp[i] == '*')//if *
				{
					//level 3
					if (s.isEmpty())//if stack is empty
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else	if ((s.peak() == "+") || (s.peak() == "-") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is +-[{( on top of stack
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else
					{
						while (true)
						{
							//level 4
							if (s.isEmpty())//if stack is empty
							{
								break;
							}
							//level 4
							if ((s.peak() == "*") || (s.peak() == "/"))//if there is */ on top of stack
							{
								s.pop();//pop
							}
							//level 4
							else
								break;
						}
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
				}



				//level 2
				else if (exp[i] == '/')
				{
					//level 3
					if (s.isEmpty())//if stack is empty
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else	if ((s.peak() == "+") || (s.peak() == "-") || (s.peak() == "*") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is  -*/+[{(  on top of stack
					{
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
					//level 3
					else
					{
						while (true)
						{
							//level 4
							if (s.isEmpty())//if stack is empty
							{
								break;
							}
							//level 4
							else if (s.peak() == "/")//if /
							{
								s.pop();//pop
							}
							//level 4
							else
								break;
						}
						string str(1, exp[i]);//convert char to str
						s.push(str);//push str on stack
					}
				}
			}
		}






		//level 1
		else if ((exp[i] == '[') || (exp[i] == '{') || (exp[i] == '('))// if opening bracket    ({[
		{
			if ((exp[i + 1] == '+') || (exp[i + 1] == '-') || (exp[i + 1] == '*') || (exp[i + 1] == '/'))
				return false;
			else
			{
				string str(1, exp[i]);//convert char to str
				s.push(str);//push str on stack
			}
		}





		//level 1
		else if ((exp[i] == ')') || (exp[i] == '}') || (exp[i] == ']'))//if closing bracket    )}]
		{
			//level 2
			if (exp[i] == ')')//if )
			{
				for (; s.peak() != "(";)
				{
					if ((s.peak() == "{") || (s.peak() == "["))//if a non-matching opening bracket, 
						return false;//expression is unbalanced
					else
						s.pop();//else pop
				}
				s.pop();
			}
			//level 2
			else if (exp[i] == '}')//if }
			{
				for (; s.peak() != "{";)
				{
					if ((s.peak() == "(") || (s.peak() == "["))//if a non-matching opening bracket, 
						return false;//expression is unbalanced
					else
						s.pop();//else pop
				}
				s.pop();
			}

			//level 2
			else if (exp[i] == ']')// if ]
			{
				for (; s.peak() != "[";)
				{
					if ((s.peak() == "{") || (s.peak() == "("))//if a non-matching opening bracket, 
						return false;//expression is unbalanced
					else
						s.pop();//else pop
				}
				s.pop();
			}

		}


		//level 1
		else
			continue;
	}

	if ((!s.isEmpty()))
	{
		for (; (!s.isEmpty());)
			s.pop();//else pop
	}

	if (s.getTop() != -1)//if stack is not empty, evem when the whole expression has been parsed,
		return false;//then the expression is unbalanced
	else
		return true;//else if stack is empty, then expressio is balanced
}









//BSEF19M003
//LAIBA KAMAL








//conversion from infix to postfix
string infixToPostfix(string exp)
{
	MyStack<string> s;
	string convert;
	for (int i = 0; exp[i] != '\0'; i++)
	{

		//level 1
		if ((exp[i] >= '0') && (exp[i] <= '9'))//0-9
		{
			//level 2
			if ((exp[i + 1] >= '0') && (exp[i + 1] <= '9'))//0-9
			{
				for (; ((exp[i] >= '0') && (exp[i] <= '9'));)//0-9
				{
					convert += exp[i];//append string
					i += 1;
				}
			}
			else
				convert += exp[i];//append string
		}


		//level 1
		else if (((exp[i] >= 'a') && (exp[i] <= 'z')) || ((exp[i] >= 'A') && (exp[i] <= 'Z'))) //a-z //A-Z
		{
			convert += exp[i];//append string
		}


		//level 1
		else if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))//if a binary operataor + - / *
		{
			//level 2
			if (exp[i] == '+')// if +
			{
				//level 3
				if (s.isEmpty())//if stack is empty
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else if ((s.peak() == "-") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is -[{( on top of stack
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else
				{
					while (true)//loop  to pop values and append string
					{
						//level 4
						if (s.isEmpty())//if stack is empty
						{
							break;
						}
						//level 4
						else if ((s.peak() == "*") || (s.peak() == "/") || (s.peak() == "+"))//if there is */+ on top of stack
						{
							convert += s.pop(); //pop and append string
						}
						//level 4
						else
							break;
					}
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
			}



			//level 2
			else if (exp[i] == '-')//if -
			{
				//level 3
				if (s.isEmpty())//if stack is empty
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else if ((s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is [{( on top of stack
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else
				{
					while (true)
					{
						//level 4
						if (s.isEmpty())//if stack is empty
						{
							break;
						}
						//level 4
						else if ((s.peak() == "*") || (s.peak() == "/") || (s.peak() == "+") || (s.peak() == "-"))//if there is */+- on top of stack
						{
							convert += s.pop();//pop and append string
						}
						//level 4
						else
							break;
					}
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
			}



			//level 2
			else if (exp[i] == '*')//if *
			{
				//level 3
				if (s.isEmpty())//if stack is empty
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else	if ((s.peak() == "+") || (s.peak() == "-") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is +-[{( on top of stack
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else
				{
					while (true)
					{
						//level 4
						if (s.isEmpty())//if stack is empty
						{
							break;
						}
						//level 4
						else if ((s.peak() == "*") || (s.peak() == "/"))//if there is */ on top of stack
						{
							convert += s.pop();//pop and append string
						}
						//level 4
						else
							break;
					}
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
			}



			//level 2
			else if (exp[i] == '/')
			{
				//level 3
				if (s.isEmpty())//if stack is empty
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else	if ((s.peak() == "+") || (s.peak() == "-") || (s.peak() == "*") || (s.peak() == "[") || (s.peak() == "{") || (s.peak() == "("))//if there is  -*/+[{(  on top of stack
				{
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
				//level 3
				else
				{
					while (true)
					{
						//level 4
						if (s.isEmpty())//if stack is empty
						{
							break;
						}
						//level 4
						else if (s.peak() == "/")//if /
						{
							convert += s.pop();//pop and append string
						}
						//level 4
						else
							break;
					}
					string str(1, exp[i]);//convert char to str
					s.push(str);//push str on stack
				}
			}

		}





		//level 1
		else if ((exp[i] == '[') || (exp[i] == '{') || (exp[i] == '('))// [{(
		{
			string str(1, exp[i]);
			s.push(str);
		}



		//level 1
		else if ((exp[i] == ')') || (exp[i] == '}') || (exp[i] == ']'))//if closing bracket    )}]
		{
			//level 2
			if (exp[i] == ')')//if )
			{
				for (; s.peak() != "(";)
				{
					convert += s.pop();//pop and append string
				}
				s.pop();//pop (
			}
			//level 2
			else if (exp[i] == '}')//if }
			{
				for (; s.peak() != "{";)
				{
					convert += s.pop();//pop and append string
				}
				s.pop();//pop {
			}

			//level 2
			else if (exp[i] == ']')// if ]
			{
				for (; s.peak() != "[";)
				{
					convert += s.pop();//pop and append string
				}
				s.pop();//pop [
			}

		}



		else
		continue;
	}

	if ((!s.isEmpty()))
	{
		for(; (!s.isEmpty());)
			convert += s.pop();//else pop
	}

	return convert;
}










//BSEF19M003
//LAIBA KAMAL








//Evaluate function
//takes a prefix or postfix exp and a  
//Boolean key as arguments //(0 for prefix expression, 1 for postfix expression)
//and returns the value of the expression after evaluation.
double Evaluate(string exp, bool key)
{
	MyStack<string>s;
	double x = 0, y = 0; //to store popped operands 
	string str;//to store more than one digit numbers


	if (key == 0)//prefix exp evaluation
	{
		//parse thorugh the whole string in reverse order, push operands on the stack
		//on the arrival of each operator, pop out two numbers, perform that operation on them and push the result back on the stack
		for (int i = exp.length() - 1; i != -1; i--)
		{
			str = "";
			if ((exp[i] >= '0') && (exp[i] <= '9'))//if operands
			{
				if (i == 0)//if in reverse order, its end of string
				{
					string s1(1, exp[i]);
					s.push(s1);
				}
				else
				{
					for (; (exp[i] != ' ') && ((exp[i] >= '0') && (exp[i] <= '9')); i--)//for more than one digit numbers
					{
						str = str + exp[i];//store the number in a string
					}
					reverse(str.begin(), str.end());//to attain right num
					s.push(str);//push 
				}
			}

			else if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))//if a binary operataor + - / *
			{
				x = stod(s.pop());//pop first operand(converting string to double to perform operations on numbers)
				y = stod(s.pop());//pop 2nd operand(converting string to double to perform operations on numbers)
				if (exp[i] == '+')//if +
					x = x + y;//perform addition
				else if (exp[i] == '-')//if -
					x = y - x;//perform subtraction
				else if (exp[i] == '*')//if *
					x = x * y;//perform multiplication
				else if (exp[i] == '/')//if /
					x = y / x;//perform division
				s.push(to_string(x));//push the answer on stack
			}
		}
	}


	//postfix exp evaluation
	else if (key == 1)
	{
		//parse thorugh the whole string,push operands on the stack
		//on the arrival of each operator, pop out two numbers, perform that operation on them and push the result back on the stack
		for (int i = 0; exp[i] != '\0';i++)
		{
			str = "";
			if ((exp[i] >= '0') && (exp[i] <= '9'))//if operands
			{
				if (i == exp.length() - 1)//if its end of string
				{
					string s1(1, exp[i]);
					s.push(s1);
				}
				else
				{
					for (; (exp[i] != ' ') && ((exp[i] >= '0') && (exp[i] <= '9')); i++)//for more than one digit numbers
					{
						str = str + exp[i];//store the number in a string
					}
					s.push(str);//push 
				}
			}
				
			else if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))//if a binary operataor + - / *
			{
				x = stod(s.pop());//pop first operand (converting string to double to perform operations on numbers)
				y = stod(s.pop());//pop 2nd operand(converting string to double to perform operations on numbers)
				if (exp[i] == '+')//if +
					x = x + y;//perform addition
				else if (exp[i] == '-')//if -
					x = y - x;//perform subtraction
				else if (exp[i] == '*')//if *
					x = x * y;//perform multiplication
				else if (exp[i] == '/')//if /
					x = y / x;//perform division
				s.push(to_string(x));//push the answer on stack (converting double to string because stack is of string)
			}
		}
	}
	x = stod(s.pop());
	return x;//return answer
}


//BSEF19M003
//LAIBA KAMAL







