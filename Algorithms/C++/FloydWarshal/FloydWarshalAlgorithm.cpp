#include<iostream>
using namespace std;
int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void floydWarshall(int M[5][5], int N)
{
	for(int K=0;K<5;K++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(M[i][j]>M[i][K]+M[K][j])
					M[i][j]=min(M[i][j], M[i][K] + M[K][j]); 
	
	//Printing Matrix    
	cout<<"After Applying Floyd-Warshell"<<endl;
		for(int i=0;i<N;i++)
		{
	        for(int j=0;j<N;j++)
	    		cout<<M[i][j] << " ";
	    	cout<<endl;
		}
		
}

int main()
{
	int mat[5][5] = {{0, 5, 1000000, 17,1000000}, {1000000, 0, 1000000, 1, 1000000}, {16, 1000000, 0, 1000000, 1000000}, {1000000, 1000000, 16, 0, 8} , {1000000, 1000000, 6, 1000000, 0}}; 
	floydWarshall(mat,5);
}