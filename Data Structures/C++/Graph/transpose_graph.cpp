//  transpose_graph.cpp: Rishabh Dev
//  Description: Transposing a graph.
#include <iostream>
using namespace std;

class AdjencyNode
{
private:
    int destination_;
    AdjencyNode *next_;

public:
    AdjencyNode(int);
    void printNodes();
    void addPath(int);
    AdjencyNode *nextNode() { return next_; }
    int destination() { return destination_; }
    bool searchPath(int);
};

AdjencyNode::AdjencyNode(int destination)
{
    destination_ = destination;
    next_ = NULL;
}

void AdjencyNode::printNodes()
{
    if (!this)
    {
        cout << "∅";
        return;
    }

    cout << destination_ << " -> ";

    next_->printNodes();
}

void AdjencyNode::addPath(int destination)
{
    if (!next_)
        next_ = new AdjencyNode(destination);
    else
        next_->addPath(destination);
}

bool AdjencyNode::searchPath(int destination)
{
    if (!this)
        return false;

    return ((destination_ == destination) || next_->searchPath(destination));
}

class Graph
{
private:
    int vertices_;
    AdjencyNode **adjency_list;

public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    bool searchPath(int, int);
    Graph transpose();
};

Graph::Graph(int vertices)
{
    vertices_ = vertices;

    adjency_list = (AdjencyNode **)malloc(sizeof(AdjencyNode *) * vertices_);

    for (int i = 0; i < vertices_; i++)
    {
        adjency_list[i] = NULL;
    }
}

void Graph::addEdge(int source, int destination)
{
    if (!(source < vertices_ && destination < vertices_))
        return;

    if (!adjency_list[source])
    {
        adjency_list[source] = new AdjencyNode(destination);
        /* adjency_list[destination] = new AdjencyNode(source); */
        return;
    }

    adjency_list[source]->addPath(destination);
    /*
        if (!adjency_list[destination])
        {
            adjency_list[destination] = new AdjencyNode(source);
            return;
        }

        adjency_list[destination]->addPath(source); */
}

void Graph::printGraph()
{
    for (int vert = 0; vert < vertices_; vert++)
    {
        cout << "Adjecncy list of vertex " << vert << " is\nhead -> ";
        if (adjency_list[vert])
        {
            adjency_list[vert]->printNodes();
        }
        cout << endl
             << endl;
    }
}

bool Graph::searchPath(int source, int destination)
{
    if (!(source < vertices_ && destination < vertices_))
        return false;

    return adjency_list[source]->searchPath(destination);
}

Graph Graph::transpose()
{
    Graph transpose_graph(vertices_);

    for (int i = 0; i < vertices_; i++)
    {
        AdjencyNode *traverser = adjency_list[i];

        while (traverser)
        {
            transpose_graph.addEdge(traverser->destination(), i);
            traverser = traverser->nextNode();
        }
    }

    return transpose_graph;
}

int main()
{
    AdjencyNode adjency_node(2);
    adjency_node.addPath(3);
    adjency_node.addPath(4);
    adjency_node.addPath(5);
    cout << "head -> ";
    adjency_node.printNodes();
    cout << endl
         << endl;

    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();
    cout << "============================== TRANSPOSE ==============================" << endl
         << endl;
    graph.transpose().printGraph();

    cout << graph.transpose().searchPath(4, 3);

    return 0;
}