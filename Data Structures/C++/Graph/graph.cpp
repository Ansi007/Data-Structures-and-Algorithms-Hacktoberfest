#ifndef GRAPH
#define GRAPH
#include <iostream>
#include "queue.cpp"
#define VISITED 1
#define NONVISITED 0
#define NOEDGE 0
#define EDGE 1

using namespace std;

class Graph{
    int** matrix;
    int vertexCount;
public:
    //Construtor
    Graph(int v = 50)
    {
        vertexCount = v;
        matrix = new int*[vertexCount];
        for(int i=0; i<vertexCount; i++)
        {
            matrix[i] = new int[vertexCount];
            for(int j=0; j<vertexCount; j++)
                matrix[i][j] = NOEDGE;
        }
    }

    //fn to add edge in adjacency matrix
    void addEdge(int n1, int n2)
    { 
        if( n1 >= 0 && n1 < vertexCount && n2 >= 0 && n2 < vertexCount && n1 != n2)
            matrix[n1][n2] = EDGE;
    }

    //fn to show adjaceny matrix
    void show()
    {
        cout << "    ";
        for(int i = 0; i<vertexCount; i++)
            cout << i+1 << ' ';
        cout << '\n';
        for(int i = 0; i<vertexCount; i++)
            cout << "---";
        cout << '\n';
        for(int i = 0; i<vertexCount; i++)
        {
            cout << i+1 << " | ";
            for(int j = 0; j<vertexCount; j++)
                cout << matrix[i][j] << ' ';
            cout << '\n';
        }
    }

    //DFS wrapper
    void DFS(int nodeNo=0)
    {
        int i;
        if(nodeNo < 0 || nodeNo >= vertexCount)
            return;
        
        int *visited = new int[vertexCount];
        for(i=0; i<vertexCount; i++)
            visited[i] = NONVISITED;
        for( i = 0; i<vertexCount; i++)
        {
            if(visited[nodeNo] == NONVISITED)
            {
                dfs(nodeNo, visited);
                cout << '\n';
            }
            nodeNo = ++nodeNo % vertexCount;
        }
    }

    //DFS
    void dfs(int node, int* visited)
    {
        if(visited[node] == VISITED)
            return;
        
        cout << node+1 << " - ";
        visited[node] = VISITED;
        for(int i = 0; i < vertexCount; i++)
        {
            if(matrix[node][i] == EDGE && visited[i] == NONVISITED)
                dfs(i, visited); 
        }
    }

    //BFS
    void BFS(int nodeNo=0)
    {
        int i, j, currentVertex;
        Queue<int> queue;
        if(nodeNo < 0 || nodeNo >= vertexCount)
            return;
        
        int *visited = new int[vertexCount];
        for(i=0; i<vertexCount; i++)
            visited[i] = NONVISITED;
        
        for(i = nodeNo, j = 0; j<vertexCount; j++)
        {
            if(visited[i] == NONVISITED)
            {
                queue.enqueue(i);
                while(!queue.isEmpty())
                {
                    currentVertex = queue.dequeue();
                    visited[currentVertex] = VISITED;
                    cout << currentVertex+1 << " - ";
                    for(int k = 0; k<vertexCount; k++ )
                    {
                        if(matrix[currentVertex][k] == EDGE && visited[k] == NONVISITED ) 
                        {
                           queue.enqueue(k);
                           visited[k] = VISITED;
                        }
                    }
                }
                cout << '\n';
            }
            i = ++i % vertexCount;
        }
    }
};

#endif
