#include<iostream>
#include <list>
 
using namespace std;
 
class Graph
{
    int V;    
    list<int> *adjL;  
public:
    Graph(int V);  
 
    void addEdge(int v, int w);
 
    void BFS(int s); 
};
 
// Initialize graph
Graph::Graph(int V)
{
    this->V = V;
    adjL = new list<int>[V];
}
 
// Add edges
void Graph::addEdge(int v, int w)
{
    adjL[v].push_back(w); 
}
 
// BFS algorithm
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    list<int> queue;
 
    visited[s] = true;
    queue.push_back(s);
 
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adjL[s].begin(); i != adjL[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
