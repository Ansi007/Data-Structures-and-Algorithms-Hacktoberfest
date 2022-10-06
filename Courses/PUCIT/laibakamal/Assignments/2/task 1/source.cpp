//BSEF19M003 
//LAIBA KAMAL

#include <iostream>
#include"A2 T1 functions.cpp"
using namespace std;


int main()
{
    cell source, destination;
    int size;
    fstream file;

    file.open("in.txt", ios::in);
    file >> size;

    char** maze = new char* [size];

    file >>source.i >> source.j >> destination.i >> destination.j;

    for (int r = 0; r < size; r++)
    {
        maze[r] = new char[size];
        for (int c = 0; c < size; c++)
            file >> maze[r][c];
    }

    decidePath(size, maze, source, destination);

    return 0;
}

//BSEF19M003 
//LAIBA KAMAL