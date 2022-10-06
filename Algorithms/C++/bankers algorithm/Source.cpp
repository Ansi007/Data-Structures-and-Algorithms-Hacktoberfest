#include <iostream>
#include <fstream>
using namespace std;
/*bankers algorithm
//this algo. reads two files.
//1-->resource.txt
//2-->process.txt
data structures-->arrays of 1 and 2 dimensions are used.
*/
bool bankersAlgo(int numOfProcess, int numOfResources, int* avail, int* resources, int** allocation, int** need);

int main()
{
	
	ifstream sin;
	sin.open("resource.txt");
	if (!sin)
	{
		cout << "Error! resource file do not open";
	}
	else
	{
		 int numOfResources;
		sin >> numOfResources;
		int* resourceArray = new int[numOfResources];
		for (int i = 0; i < numOfResources; i++)
		{
			sin >> resourceArray[i];
			//sin >> *(resourceArray+i);
		}sin.close();
		sin.open("process.txt");
		if (!sin)
		{
			cout << "Error process file donot open";
		}
		else
		{
			int numOfProcess;
			sin >> numOfProcess;
			int** allocatedResources = new int* [numOfProcess];
			int** needOfResources = new int* [numOfProcess];
			for (int i = 0; i < numOfProcess; i++)
			{
				allocatedResources[i] = new int[numOfResources];
				needOfResources[i] = new int[numOfResources];
			}
			for (int i = 0; i < numOfProcess; i++)
			{
				for (int j = 0; j < numOfResources; j++)
				{
					sin >> allocatedResources[i][j];

				}
				for (int j = 0; j < numOfResources; j++)
				{
					sin >> needOfResources[i][j];

				}
			}
			int *available=new int[numOfResources];
			for (int i = 0; i < numOfResources; i++)
			{
				int sum = 0;
				//getting available resources by substracting sum of resources from all process
				for (int j = 0; j < numOfProcess; j++)
				{
					
					sum = sum + allocatedResources[j][i];
				}
				available[i] = resourceArray[i]- sum;
			}
			
			bankersAlgo(numOfProcess, numOfResources, available,resourceArray, allocatedResources, needOfResources);
			 



			//deleting 
			for (int i = 0; i < numOfProcess; i++)
			{
				delete[] allocatedResources[i];
				delete[] needOfResources[i];
			}
			delete []allocatedResources;
			delete[] needOfResources;
			delete[] available;
		}
		
		delete[]resourceArray;
	}


}

bool bankersAlgo(int numOfProcess,int numOfResources,int *avail, int* resources, int** allocation, int** need)
{
	char* Flag=new char[numOfProcess];
	for (int i = 0; i < numOfProcess; i++)
	{
		Flag[i] = 0;
	}
	for (int i = 0; i < numOfProcess; i++)
	{
		
		for (int j = 0,flag=1; j < numOfResources&&flag>0; j++)
		{
			if (Flag[i] == 0)//if some process has not  been finished 
			{
				if (need[i][j] > avail[j])//check wether system can fulfil its need
				{
					
					flag = 0;
					
				}
				else
				{
					flag++;
					if (flag == 4)//if system can fulfil the need of a process for resources
					{

						
						for (int p = 0; p < numOfResources; p++)
						{
							//geting alloted resource back
							
							avail[p] = avail[p] + allocation[i][p];
							//cout << avail[p] << "   ";
						}
						Flag[i] = 1;
						//if system can fulfil the need of some process then after 
						//taking resources from it, again start to check from process1;
						i = 0;
						
						
					}
				}
			}
		}
	}
	for (int i = 0; i < numOfProcess; i++)
	{
		if (Flag[i] == 0)
		{
			cout << "system is in the dead lock condition:";
			return 0;
			i = numOfProcess;
			
		}
	}
	delete[]Flag;
	cout << "system is \'NOT\' in the dead lock condition:";
	cout << "\n system is in the afe condition.";
	return 1;
}

