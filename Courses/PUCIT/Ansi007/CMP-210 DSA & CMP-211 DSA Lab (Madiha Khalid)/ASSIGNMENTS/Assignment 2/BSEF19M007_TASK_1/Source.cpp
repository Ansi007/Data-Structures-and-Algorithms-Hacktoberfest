#include<iostream>
#include<fstream>
#include<string>
#include "MyStack.h"
#include "MyStack.cpp"

using namespace std;

int gX, gY;	//GoalX, GoalY, Will not change
int Size;	

MyStack<string> S;		//To print out path
MyStack<string> S1;

bool func(char**, int, int, char);


int main() {

	ifstream in("in.txt");
	ofstream out("out.txt");
	char** maze;

	in >> Size;
	maze = new char* [Size];
	for (int i = 0; i < Size; i++)
		maze[i] = new char[Size];

	char** output;
	output = new char* [Size];
	for (int i = 0; i < Size; i++)
		output[i] = new char[Size];


	int mX, mY;
	in >> mY >> mX >> gY >> gX;

	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++) {
			in >> maze[i][j];
			if (maze[i][j] != '1' && maze[i][j] != '0' && maze[i][j] != 'm' && maze[i][j] != 'c') {		//if input size is not correct, garbage will be read, discard that input.
				out << "=> Wrong input." << endl;
				return 0;
			}
		}

	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			output[i][j] = maze[i][j];	//Creating a copy of the input.


	out << Size << endl;
	out << mY << " " << mX << endl;
	out << gY << " " << gX << endl;


	if (func(maze, mX, mY, 'n')) {	

		while (!(S.isEmpty())) {
			S1.Push(S.Pop());
		}

		while (!(S1.isEmpty())) {
			out << S1.Pop();
		}

		out << endl;

		for (int i = 0; i < Size; i++) {

			for (int j = 0; j < Size; j++) {
				if (maze[i][j] == '*')	//Display output maze
					out << "* ";

				else
					out << output[i][j] << " ";
			}
			out << endl;
		}
	}

	else out << "=> No path found. ";

	return 0;
}

bool func(char** maze, int mX, int mY, char last) {


	if (mX == gX && mY == gY) {	//if reached to the destination
		string o = "(";
		o += to_string(mY) + "," + to_string(mX) + ")";
		S.Push(o);	//Push last path

		maze[mY][mX] = '*';
		return true;	
	}

	if (mX < Size - 1 && last != 'l') {	//Cannot go right, if last movement was left. This avoids inifinte looping

		if (maze[mY][mX + 1] != '1' && maze[mY][mX + 1] != '*') {	//if not block
			string o = "(";

			maze[mY][mX] = '*';
			o += to_string(mY) + "," + to_string(mX) + ")";
			S.Push(o);

			++mX; // right
			if (func(maze, mX, mY, 'r')) {	//recursive call
				return true;
			}
			else {
				maze[mY][mX] = '1';	//put a wall on that path, where we have already been. 
				--mX;	//and come back
				S.Pop();	
			}
		}
	}

	if (mY < Size - 1 && last != 'u') {		//dont go out of bound

		if (maze[mY + 1][mX] != '1' && maze[mY + 1][mX] != '*') {
			string o = "(";

			maze[mY][mX] = '*';
			o += to_string(mY) + "," + to_string(mX) + ")";
			S.Push(o);

			++mY; // down
			if (func(maze, mX, mY, 'd')) {
				return true;
			}
			else {
				maze[mY][mX] = '1';
				--mY;
				S.Pop();
			}
		}
	}





	if (mY > 0 && last != 'd') {	//dont go out of bound
		if (maze[mY - 1][mX] != '1' && maze[mY - 1][mX] != '*') {
			string o = "(";

			maze[mY][mX] = '*';
			o += to_string(mY) + "," + to_string(mX) + ")";
			S.Push(o);

			--mY; // up
			if (func(maze, mX, mY, 'u')) {
				return true;
			}
			else {
				maze[mY][mX] = '1';
				++mY;
				S.Pop();

			}
		}
	}

	if (mX > 0 && last != 'r') {	//dont go out of bound

		if (maze[mY][mX - 1] != '1' && maze[mY][mX - 1] != '*') {
			string o = "(";

			maze[mY][mX] = '*';
			o += to_string(mY) + "," + to_string(mX) + ")";
			S.Push(o);

			--mX; // left
			if (func(maze, mX, mY, 'l')) {
				return true;
			}
			else {
				maze[mY][mX] = '1';
				++mX;
				S.Pop();
			}
		}
	}


	return false;
}
