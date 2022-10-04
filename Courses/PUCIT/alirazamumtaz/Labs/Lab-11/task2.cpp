#include <iostream>
#include <queue>

using namespace std;

#define NOEDGE 0
#define EDGE 1

class AMatrix {
	int **nodes, count;
public:
	AMatrix(int count) {
		this -> count = count;
		nodes = new int* [count];
		int i, j;
		for (i = 0 ; i < count ; i++) {
			nodes [ i ] = new int [count];
			for ( j = 0 ; j < count ; j++ )
				nodes [ i ] [ j ] = NOEDGE;
		}
	}
	void addEdge(int n1, int n2) {
		nodes [ n1 ] [ n2 ] = EDGE;
	}
	void show() {
		int i, j;
		for (i = 0 ; i < count ; i++) {
			cout << i << " : ";
			for ( j = 0 ; j < count ; j++ )
				if ( nodes [ i ] [ j ] == EDGE )
					cout << j << ' ';
			cout << '\n' ;
		}
	}

	bool isConnected(int a, int b) {
		return ( nodes [ a ] [ b ] == EDGE );
	}

	bool isPathExist(int a, int b) {
		// Base Case
        if(nodes[a][b] == EDGE)	return true;
    	// Recursive case
        for(int i = 0 ; i < count ; i++){ 
            if (nodes[a][i] == EDGE){
                if(nodes[a][i] == EDGE)
                    return isPathExist(i, b);
            }
        }
        return false;
	}
	int countOfEdges(int a, int b){
		// Base Case
        if(nodes[a][b] == EDGE)	return true;
    	// Recursive case
        for(int i = 0; i < count ; i++) {
            if(nodes[a][i] == EDGE){
                if(nodes[a][i]==EDGE)
                    return isPathExist(i,b) + 1;
            }
        }
        return 0;
	}
};

int main() {
	AMatrix matrix(10);
	matrix.addEdge(0, 2);
	matrix.addEdge(0, 3);
	matrix.addEdge(0, 4);
	matrix.addEdge(1, 0);
	matrix.addEdge(1, 3);
	matrix.addEdge(2, 4);
	matrix.addEdge(3, 0);
	matrix.addEdge(4, 1);
	matrix.addEdge(4, 2);
	matrix.addEdge(4, 3);
	matrix.addEdge(4, 6);
	matrix.addEdge(6, 5);
	matrix.addEdge(8, 6);
	matrix.addEdge(1, 9);
	matrix.addEdge(3, 8);
	matrix.show();
	if(matrix.isConnected(2,4))
		cout << "\nConnected\n";

	// if(matrix.isPathExist(1,5))
	// 	cout << "\nPath Found\n";

	cout << "countOfEdges = " << matrix.countOfEdges(3,6);
	return 0;
}
