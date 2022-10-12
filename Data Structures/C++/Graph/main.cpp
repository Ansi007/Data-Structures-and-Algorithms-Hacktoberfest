#include <iostream>
#include "graph.cpp"

using namespace std;

int main()
{
    Graph graph(6);
    //Adding edges for vertex A(i.e 0)
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(0, 5);
    //Adding edges for vertex B(i.e 1)
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    //Adding edges for vertex C(i.e 2)
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    //Adding edges for vertex D(i.e 3)
    graph.addEdge(3, 5);
    //Adding edges for vertex E(i.e 4)
    graph.addEdge(4, 5);
    //Adding edges for vertex F(i.e 5)
    graph.addEdge(5, 4);
    cout << "-------------------Adjacency Matrix-------------------\n";
    graph.show();
    cout << "\n-------------------DFS-------------------\n";
    graph.DFS(0);
    cout << "\n-------------------BFS-------------------\n";
    graph.BFS(0);
    return 0;
}