

//BSEF19M003 
//LAIBA KAMAL
#include<fstream>
#include"MyStack.cpp"
using namespace std;

struct cell//to store source and destination
{
    int i, j;
};
//BSEF19M003 
//LAIBA KAMAL

//returns true if the move is valid and false otherwise.
inline bool isValidMove(int size, int i, int j, char** maze, bool** visited)
{
    if (i >= 0 && i < size && j >= 0 && j < size && (maze[i][j] == '0' || maze[i][j] == 'm' || maze[i][j] == 'c') && !visited[i][j])
        return true;
    else
        return false;
}

//BSEF19M003 
//LAIBA KAMAL
//prints size, source, destination, path and maze matrix on console.
inline void printOnConsole(int size, char** maze, cell s, cell d, MyStack<int>path)
{
    cout << size << endl << s.i << " " << s.j << endl << d.i << " " << d.j << endl;//size, source, destination

    for (int i = 0, j = 0; !(path.isEmpty());)//path print
    {
        j = path.pop();
        i = path.pop();
        cout << "(" << i << "," << j << ") ";
    }


    cout << endl << endl;
    for (int r = 0; r < size; r++)//maze matrix print
    {
        for (int c = 0; c < size; c++)
            cout << maze[r][c] << " ";
        cout << endl;
    }
}


//BSEF19M003 
//LAIBA KAMAL
//puts size, source, destination, path and maze matrix in out file.
inline void writeOutputFile(int size, char** maze, cell s, cell d, MyStack<int>path)
{
    fstream f;
    f.open("out.txt", ios::out);

    f << size << endl << s.i << " " << s.j << endl << d.i << " " << d.j << endl;//size, source, destination

    for (int i = 0, j = 0; !(path.isEmpty());)//path print
    {
        j = path.pop();
        i = path.pop();
        f << "(" << i << "," << j << ") ";
    }


    f << endl << endl;
    for (int r = 0; r < size; r++)//maze matrix print
    {
        for (int c = 0; c < size; c++)
            f << maze[r][c] << " ";
        f << endl;
    }
}

//BSEF19M003 
//LAIBA KAMAL



//decides the safe path of rat 
inline void decidePath(int size, char** maze, cell s, cell d)
{
    MyStack<int> st;
    MyStack<int> path;

    bool** visited = new bool* [size];
    for (int a = 0; a < size; a++)
    {
        visited[a] = new bool[size];
        for (int b = 0; b < size; b++)
            visited[a][b] = false;
    }

    int r = s.i, c = s.j;
    st.push(r);
    st.push(c);

    for (; ((r != d.i) || (c != d.j));)
    {
        if ((r != size - 1) && maze[r + 1][c] == 'c')//if there is destination on one step down
        {
            r = r + 1;
            st.push(r);
            st.push(c);
        }
        else if ((r != 0) && maze[r - 1][c] == 'c')//if there is destination on one step up
        {
            r = r - 1;
            st.push(r);
            st.push(c);
        }
        else if (maze[r][c + 1] == 'c')//if there is destination on one step right
        {
            c = c + 1;
            st.push(r);
            st.push(c);
        }
        else if (maze[r][c - 1] == 'c')//if there is destination on one step left
        {
            c = c - 1;
            st.push(r);
            st.push(c);
        }
        else if (isValidMove(size, r, c + 1, maze, visited))//if right is a valid move
        {
            c = c + 1;
            visited[r][c] = true;
            st.push(r);
            st.push(c);
        }
        else if (isValidMove(size, r, c - 1, maze, visited))//if left is a valid move
        {
            c = c - 1;
            visited[r][c] = true;
            st.push(r);
            st.push(c);
        }
        else if (isValidMove(size, r - 1, c, maze, visited))//if up is a valid move
        {
            r = r - 1;
            visited[r][c] = true;
            st.push(r);
            st.push(c);
        }
        else if (isValidMove(size, r + 1, c, maze, visited))//if down is a valid move
        {
            r = r + 1;
            visited[r][c] = true;
            st.push(r);
            st.push(c);
        }
        else if (r == d.i && c == d.j)//if destination cell is reached
        {
            continue;
        }
        else
        {
            c = st.pop();
            r = st.pop();
            if (maze[r][c] == 'm')//if its SOURCE cell
            {
                st.push(r);
                st.push(c);
                //maze[r][c] = '*';
            }
            else if (maze[r + 1][c] == 'm')//if there is source on one step down
            {
                r = r + 1;
                st.push(r);
                st.push(c);
            }
            else if ((r != 0) && maze[r - 1][c] == 'm')//if there is source on one step up
            {
                r = r - 1;
                st.push(r);
                st.push(c);
            }
            else if (maze[r][c + 1] == 'm')//if there is source on one step right
            {
                c = c + 1;
                st.push(r);
                st.push(c);
            }
            else if (maze[r][c - 1] == 'm')//if there is source on one step left
            {
                c = c - 1;
                st.push(r);
                st.push(c);
            }
            else if (isValidMove(size, r, c + 1, maze, visited))//if right is a valid move
            {
                st.push(r);
                st.push(c);
            }
            else if (isValidMove(size, r, c - 1, maze, visited))//if left is a valid move
            {
                st.push(r);
                st.push(c);
            }
            else if (isValidMove(size, r - 1, c, maze, visited))//if up is a valid move
            {
                st.push(r);
                st.push(c);
            }
            else if (isValidMove(size, r + 1, c, maze, visited))//if down is a valid move
            {
                st.push(r);
                st.push(c);
            }
        }
    }


    for (int r = d.i, c = d.j; ((r != s.i) || (c != s.j));)//puts esterics on the path
    {
        c = st.pop();
        r = st.pop();
        maze[r][c] = '*';
        path.push(r);
        path.push(c);
    }

    printOnConsole(size, maze, s, d, path);//prints on consle
    writeOutputFile(size, maze, s, d, path);//puts the output into output file

}

//BSEF19M003 
//LAIBA KAMAL