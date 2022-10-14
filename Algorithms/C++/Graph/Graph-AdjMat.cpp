#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Graph
{
	private:
		vector<string> vertices;
		vector<vector<float> > edges;
		int size;
	public:
		Graph(int verticesCount)
		{
			vertices.resize(verticesCount);
			edges.resize(verticesCount);
			for ( int i = 0 ; i < verticesCount ; i++ )
				edges[i].resize(verticesCount);
			size = 0;
		}

};

int main()
{
	Graph f(7);

	cout << endl;
}
