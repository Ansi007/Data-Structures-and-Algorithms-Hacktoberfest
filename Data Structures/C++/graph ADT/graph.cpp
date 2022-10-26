#include <iostream>

#include "circularqueue.cpp"

using namespace std;

class Graph{
    int **arr ;
    Queue <char> q;
    int noofnodes ;

public:
    Graph(int **a , int size) {
        int i , j;
        this->noofnodes = size ;
        arr = new int*[size] ;
        for (i = 0 ; i < size ; i++)
            arr[i] = new int [size] ;
        for (i = 0 ; i < size ; i++)
            for (j = 0 ; j < size ; j++)
                this->arr[i][j] = a[i][j] ;
    }

    void BFS(char start) {
        char temp ;
        int i = 0 , j;
        int *visit;
        visit = new int [noofnodes] ;
        for (j = 0 ; j < noofnodes ; j++) 
            visit[j] = 0 ;
        cout << start << ' ';
        visit[i] = 1 ;
        q.enqueue(start) ;
        while (!q.isempty()) {
            temp = q.dequeue() ;
            for (j = 1 ; j < noofnodes ; j++) {
                if (arr[i][j] == 1 and visit[j] == 0) {
                    char t = j + 'A' ;
                    cout << t << ' ' ;
                    visit[j] = 1; 
                    q.enqueue(t) ;
                }
                
            }
            i++ ;
        }
    }

    void DFS (char start) {
        int j ;
        static int visit[6] = {0} ;
        int i = start - 'A';
        if (visit[i] == 0) {
            cout << start << ' ' ;
            visit[i] = 1 ;
            for (j = 1 ; j < noofnodes ; j++) {
                if (arr[i][j] == 1 and visit[j] == 0) {
                    char temp = j + 'A' ;
                    DFS(temp);
                }
            }
        }
    }
};


int main () {
    int **A ;
    A = new int *[6] ;
    for (int i = 0 ; i < 6 ; i++)
        A[i] = new int [6] ;
    
    int G[6][6]={{0,1,0,1,0,1},
                {1,0,1,0,0,0},
                {0,1,0,1,0,0},
                {0,0,0,0,0,1},
                {0,0,0,0,0,1},
                {0,0,0,0,1,0}};

    for (int i = 0 ; i < 6 ; i++) 
        for (int j = 0 ; j < 6 ; j++) 
            A[i][j] = G[i][j] ;

    Graph g(A, 6) ;
    cout << "BFS is " ;
    g.BFS('A') ;
    cout << endl ;
    cout << "DFS is " ;
    g.DFS('A') ;
    return 0 ;
}

