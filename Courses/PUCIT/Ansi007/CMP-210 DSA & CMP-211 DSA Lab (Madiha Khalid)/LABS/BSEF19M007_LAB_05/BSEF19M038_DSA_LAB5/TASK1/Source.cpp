#include<iostream>
#include"Queue.h"
#include"Queue.cpp"		//INCLUDING FILES
using namespace std;
int main()
{
	Queue<double> Q2(20);
	Q2.Enqueue(5.0);				//ENQUE 2 ELEMENTS
	Q2.Enqueue(6.5);
	Q2.showstructure();				//CALLING SHOWSTRUCUTRE FUNCTION
	Q2.Enqueue(-3.0);
	Q2.Enqueue(-8.0);				//ENQUEUE 2 MORE ELEMENTS
	Q2.showstructure();				//CALLING SHOWSTRUCTURE FUNCTION
	Q2.Dequeue();
	Q2.Dequeue();					//DEQUEUE 2 ELEMETS
	Q2.showstructure();				//OUTPUT QUEUE
}