#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

class Graph
{
	private:

	    struct GNode
	    {
	        string label;
	        list<int> adj;

	        GNode(string n)
	        {
	            label = n;
	        }
	    };

		vector<GNode> data;

		void addEdge(int fromLoc, int toLoc)
		{
			data[fromLoc].adj.push_back(toLoc);
		}

		void ExploreNetwork(int vertexNo, vector<bool>& seen)
		{
			if(seen[vertexNo] == false)
			{
				seen[vertexNo] = true;

				cout << getVertex(vertexNo) << " visited" << endl;
				list<int>::iterator it;
				for(it=data[vertexNo].adj.begin(); it != data[vertexNo].adj.end(); it++)
				{
					int adjVertex = *it;
					ExploreNetwork(adjVertex, seen);
				}
			}
		}

	public:
		string getVertex(int vno)
		{
			return data[vno].label;
		}

		void addVertex(string st)
		{
			GNode tmp(st);
			data.push_back(tmp);
		}

		int findVertex(string st)
		{
			for(int j=0;j<data.size();j++)
			{
				if(data[j].label == st)
				{
					return j;
				}
			}
			return -1;
		}

		void addDirectedEdge(string from, string to)
		{
			int fromLoc = findVertex(from);
			int toLoc = findVertex(to);

			if (fromLoc == -1 || toLoc == -1)
			{
				exit(0); // exception
			}
			addEdge(fromLoc, toLoc);
		}

		void addUnDirectedEdge(string from, string to)
		{
			int fromLoc = findVertex(from);
			int toLoc = findVertex(to);

			if (fromLoc == -1 || toLoc == -1)
			{
				exit(0); // exception
			}
			addEdge(fromLoc, toLoc);
			addEdge(toLoc, fromLoc);
		}

		void TraverseReachableGraph(string start)
		{
			vector<bool> t(data.size(), false);
			int vno = findVertex(start);
			if (vno == -1)
			{
				exit(0); // exception
			}
			ExploreNetwork(vno, t);
		}

		void TraverseReachableGraph()
		{
			vector<bool> t(data.size(), false);
			ExploreNetwork(0, t);
		}

		void TraverseCompleteGraph()
		{
			vector<bool> t(data.size(), false);
			for(int j=0; j<data.size(); j++)
			{
				if(t[j] == false)
				{
					cout << "starting traversal ..." << endl;
					ExploreNetwork(j, t);
				}
			}
		}
};

int main()
{
	Graph f;

	f.addVertex("B");
	f.addVertex("R");
	f.addVertex("N");
	f.addVertex("F");
	f.addVertex("A");
	f.addVertex("P");
	f.addVertex("Y");

	f.addDirectedEdge("R", "N");
	f.addDirectedEdge("B", "F");
	f.addDirectedEdge("A", "P");
	f.addDirectedEdge("R", "A");
	f.addDirectedEdge("P", "F");
	f.addDirectedEdge("N", "B");
	f.addDirectedEdge("Y", "N");
	f.addDirectedEdge("Y", "F");
	f.addDirectedEdge("Y", "A");
	f.addDirectedEdge("R", "B");

	cout << endl << "Explore Reachable Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseReachableGraph("Y", "H");
	cout << endl << "Explore Reachable Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseReachableGraph();
	cout << endl << "Explore Complete Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseCompleteGraph();
}
