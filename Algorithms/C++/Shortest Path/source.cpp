// C++ Code implementation for above problem
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define N 4
#define M 4

// QItem for current location and distance
// from source location
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};

int minDistance(char grid[N][M])
{
	QItem source(0, 0, 0);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '0')
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// Finding source
			if (grid[i][j] == 's')
			{
			source.row = i;
			source.col = j;
			}
		}
	}

	// applying BFS on matrix cells starting from source
	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;
	while (!q.empty()) {
		QItem p = q.front();
		q.pop();

		// Destination found;
		if (grid[p.row][p.col] == 'd')
			return p.dist;

		// moving up
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col] == false) {
			q.push(QItem(p.row - 1, p.col, p.dist + 1));
			visited[p.row - 1][p.col] = true;
		}

		// moving down
		if (p.row + 1 < N &&
			visited[p.row + 1][p.col] == false) {
			q.push(QItem(p.row + 1, p.col, p.dist + 1));
			visited[p.row + 1][p.col] = true;
		}

		// moving left
		if (p.col - 1 >= 0 &&
			visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
		}

		// moving right
		if (p.col + 1 < M &&
			visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
		}
	}
	return -1;
}

class Edge{
   public:
        int src, dest, weight;
};

class Graph {
    public:
        vector<vector<int>> list;
        int V;
        Graph(int V, vector<Edge> edges){
            this->V = V;
            list = vector<vector<int>>(V, vector<int>());
            for (int i = 0; i < (int)edges.size(); i++){
                list[edges[i].src].push_back(edges[i].dest);
                list[edges[i].dest].push_back(edges[i].src);
            }
        }
        void printGraph(){
            for (int i = 0; i < V; i++){
                cout << i << "-> ";
                for (int j = 0; j < (int)list[i].size(); j++){
                    cout << list[i][j] << " ";
                }
                cout << endl;
            }
        }
};

// Driver code
int main()
{
// {
// 	char grid[N][M] = { { '0', '*', '0', 's' },
// 						{ '*', '0', '*', '*' },
// 						{ '0', '*', '*', '*' },
// 						{ 'd', '*', '*', '*' } };

// 	cout << minDistance(grid);

vector<Edge> edges = {
    {0, 1, 4},
    {0, 2, 6},
    {0, 3, 5},
    {1, 2, 3},
    {1, 3, 2},
    {2, 3, 1}
};  

    Graph myGraph(4, edges);
    myGraph.printGraph();
    return 0;
}
