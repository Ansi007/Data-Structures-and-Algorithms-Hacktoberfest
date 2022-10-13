#include <iostream>
#include <list>
using namespace std;

class Graph {
  int v;
  list<int> *adjL;
  bool *c;

   public:
  Graph(int V);
  void addEdge(int s, int t);
  void DFS(int m);
};

// Initialize graph
Graph::Graph(int vert) {
  v = vert;
  adjL = new list<int>[vert];
  c = new bool[vert];
}

// Add edges
void Graph::addEdge(int s, int t) {
  adjL[s].push_front(t);
}

// DFS algorithm
void Graph::DFS(int m) {
  c[m] = true;
  list<int> adjList = adjL[m];

  cout << m << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!c[*i])
      DFS(*i);
}

int main() {
  Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from m 2) \n";
  g.DFS(2);

  return 0;
}
