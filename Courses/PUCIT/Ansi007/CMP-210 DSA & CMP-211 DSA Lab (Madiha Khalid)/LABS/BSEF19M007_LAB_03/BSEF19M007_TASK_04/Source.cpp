#include<iostream>
#include"MyStack.h"
#include"MyStack.cpp"
#include<string>

using namespace std;


string countAtoms(string formula_string) {

	/*
	This function takes a molecular fomrula as an arguement and return its simplified form representing the number of atoms in it
	:param: string formula_string: input formula
	:return: Simplified atoms count

	:working: Function works in 4 steps.
	:step1: It concatenates the atoms by its factors e.g. H2O -> HHO
	:step2: It extracts the parenthesis part from the string and store it into STACK
	:step3: Opens up the parenthesis and seperate all of the atoms
	:step4: Count the number of atoms put it in a string
	*/


	MyStack<string>STACK1, STACK2;
	string output_string = "";
	string Helping_Array[4];
	int iterator = 0;			//Initital to 0, Used for concatenation
	int bracketCount = 0;		//To have the Opening and BracketCount


	/*
	* 	Helping_Array[0] -> To extract strings and push pop in stack. It is also used to extract and then concatenate the repeated atoms.
	* 	Helping_Array[1] -> To extract the numerical factor and then convert it into iterator
	* 	Helping_Array[2] -> To store the concatenated string.
	*/


	//Step 1

	for (int i = 0; i < formula_string.length(); i++) {
		if (formula_string[i] >= 'A' && formula_string[i] <= 'Z') {
			if (formula_string[i + 1] >= 'a' && formula_string[i + 1] <= 'z') {
				Helping_Array[0] = formula_string[i];
				Helping_Array[0] += formula_string[i + 1];
				i++;
			}

			else Helping_Array[0] = formula_string[i];
			Helping_Array[2] += Helping_Array[0];
		}

		if (formula_string[i] >= '1' && formula_string[i] <= '9') {
			if (formula_string[i + 1] >= '0' && formula_string[i + 1] <= '9') {
				Helping_Array[1] = formula_string[i];
				Helping_Array[1] += formula_string[i + 1];
				i++;
			}

			else if (formula_string[i - 1] == '(' || formula_string[i - 1] == ')') {
				Helping_Array[0] = formula_string[i];
				Helping_Array[2] += Helping_Array[0];
			}

			else if (formula_string[i - 1] != '(' || formula_string[i - 1] != ')')
			{
				Helping_Array[1] = formula_string[i];
				iterator = stoi(Helping_Array[1]) - 1;
				while (iterator--) {
					Helping_Array[2] += Helping_Array[0];
				}
			}
		}

		if (formula_string[i] == '(' || formula_string[i] == ')') {

			Helping_Array[0] = formula_string[i];
			Helping_Array[2] += Helping_Array[0];

		}
	}

	//Step 2

	formula_string = "";


	for (int i = 0; i < Helping_Array[2].size(); i++) {

		if (Helping_Array[2][i] >= 'A' && Helping_Array[2][i] <= 'Z') {
			if (Helping_Array[2][i + 1] >= 'a' && Helping_Array[2][i + 1] <= 'z') {
				Helping_Array[0] = Helping_Array[2][i];
				Helping_Array[0] += Helping_Array[2][i + 1];
				i++;
				formula_string += Helping_Array[0];

			}
			else {
				Helping_Array[0] = Helping_Array[2][i];
				formula_string += Helping_Array[0];
			}
			continue;
		}

		else if (Helping_Array[2][i] == '(') {
			bracketCount++;
			Helping_Array[0] = Helping_Array[2][i];
			STACK1.Push(Helping_Array[0]);
			i++;

			while (1) {
				if (Helping_Array[2][i] == '(')
					bracketCount++;

				if (Helping_Array[2][i] == ')')
					bracketCount--;

				Helping_Array[0] = Helping_Array[2][i++];
				STACK1.Push(Helping_Array[0]);

				if (bracketCount == 0) {
					Helping_Array[0] = Helping_Array[2][i++];
					STACK1.Push(Helping_Array[0]);
					break;
				}
			}
			i--;
		}
	}

	//Step 3

	Helping_Array[0] = "";
	Helping_Array[1] = "";
	Helping_Array[2] = formula_string;

	while (!STACK1.isEmpty()) {
		STACK2.Push(STACK1.Pop());
	}

	while (!STACK2.isEmpty()) {

		if (STACK2.Peek() == ")") {
			STACK2.Pop();
			Helping_Array[1] = STACK2.Pop();
			if (Helping_Array[1] >= "0" && Helping_Array[1] <= "9")
				if (STACK2.Peek() >= "0" && STACK2.Peek() < "9") {
					Helping_Array[1] += STACK2.Pop();
					iterator = stoi(Helping_Array[1]);
				}
				else
					iterator = stoi(Helping_Array[1]);

			else iterator = 1;

			Helping_Array[3] = "";
			while (STACK1.Peek() != "(") {
				Helping_Array[0] = STACK1.Pop();
				if (Helping_Array[0] >= "a" && Helping_Array[0] <= "z") {
					Helping_Array[0] += STACK1.Pop();
				}
				for (int q = 0; q < iterator; q++)
					Helping_Array[3] += Helping_Array[0];
			}

			STACK1.Pop();
			for (int a = 0; a < Helping_Array[3].size(); a++) {
				Helping_Array[0] = Helping_Array[3][a];
				STACK1.Push(Helping_Array[0]);
			}

		}

		else STACK1.Push(STACK2.Pop());

	}

	while (!STACK1.isEmpty()) {
		Helping_Array[0] = STACK1.Pop();
		Helping_Array[2] += Helping_Array[0];
	}

	//Step 4


	int size = Helping_Array[2].size();
	string* m1 = new string[size];		//Store the atoms
	int* m2 = new int[size];		//Store the atoms count
	bool* m3 = new bool[size];	//Have a check if the atom has already been counted

	for (int i = 0; i < size; i++) {
		m1[i] = "";
		m2[i] = 0;
		m3[i] = false;
	}

	//Extracting atoms from the strings and storing it into the array for counting

	for (int i = 0; i < size; i++) {
		if (Helping_Array[2][i + 1] >= 'a' && Helping_Array[2][i + 1] <= 'z') {
			Helping_Array[0] = Helping_Array[2][i];
			Helping_Array[0] += Helping_Array[2][i + 1];
			i++;
			m1[i] = Helping_Array[0];
		}

		else {
			Helping_Array[0] = Helping_Array[2][i];
			m1[i] = Helping_Array[0];
		}
	}

	//Sorting the array, it also helps to gather the same atoms together. 

	string max;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (m1[i] < m1[j]) {
				max = m1[i];
				m1[i] = m1[j];
				m1[j] = max;
			}
		}
	}

	int next_iteration = 0;

	for (int i = 0; i < Helping_Array[2].size(); i++) {

		for (int j = i; j <= Helping_Array[2].size(); j++) {

			if (m1[i] == m1[j])
				++m2[i];
			else {
				next_iteration = j;
				break;

			}
		}



		if (m1[i] != "") {
			output_string += m1[i];
			if (m2[i] != 1)
				output_string += to_string(m2[i]);
		}

		i = next_iteration - 1;
	}

	return output_string;
}

int main() {
	string formula_string, output_string;
	cout << "=> Input formula = ";
	cin >> formula_string;
	output_string = countAtoms(formula_string);
	cout << "=> Output: " << output_string << endl;
	return 0;
}