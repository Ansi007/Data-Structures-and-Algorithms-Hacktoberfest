#include <iostream>
#include <iomanip>

using namespace std;

class Treee
{
	private:
		double V[999]; // array
		double P[999]; // array
		int size;      //count of values in Tree
	public:
		Treee()
		{
			size = 0;
		}
		
		void addRoot(double n)
		{
			if(size == 0)
			{
				V[0] = n;
				P[0] = -1;
				size++;
			}
		}
		
		void addChild(double n, double p)
		{
			for(int j=0; j<size; j++)
			{
				if(V[j] == p)
				{
					V[size] = n;
					P[size] = p;
					size++;
					break;
				}
			}
		}
		
		void dumpArrays()
		{
			for(int j=0; j<size; j++)
			{
				cout << V[j] << " <-- ";
				cout << P[j] << endl;
			}
		}

		void display()
		{
			double e;

			double T[999]; // temp array
			int C = 0;

			T[C++] = V[0];
			while(C > 0)
			{
				e = T[--C];
				
				cout << e << endl;

				for(int j=0; j<size; j++)
				{
					if(P[j] == e)
					{
						T[C++] = V[j];
					}
				}
			}
		}

		void displayTreee()
		{
			double e;
			int i;

			double T[999]; // temp array
			int D[999]; // temp array
			int C = 0;

			T[C] = V[0];
			D[C++] = 0;
			while(C > 0)
			{
				e = T[--C];
				i = D[C];
				
				for(int j=0; j<i-1; j++){
					cout << "   ";
				}
				if(i>0)
				{
					cout << "+" << "--";
				}
				cout << e << endl;
					
				for(int j=0; j<size; j++)
				{
					if(P[j] == e)
					{
						T[C] = V[j];
						D[C++] = i+1;
					}
				}
			}
		}

		void displayWR()
		{
			displayRcr(0);
		}

		void displayRcr(int sbtr)
		{
			if(sbtr < size)
			{
				cout << V[sbtr] << endl;
				
				for(int j=size-1; j>=0; j--)
				{
					if(P[j] == V[sbtr])
					{
						displayRcr(j);
					}
				}
			}
		}

};

int main()
{
	Treee t;
	t.addRoot(50);
	t.addChild(40, 50);
	t.addChild(20, 50);
	t.addChild(90, 50);
	t.addChild(33, 40);
	t.addChild(77, 40);
	t.addChild(109, 33);
	t.addChild(456, 77);
	t.addChild(4156, 109);
	t.addChild(2456, 109);
	t.addChild(4576, 109);
	t.addChild(901, 20);
	t.addChild(781, 20);
	t.addChild(42, 90);
	t.addChild(81, 33);
	t.dumpArrays();
	cout << endl;
	t.display();
	cout << endl;
	t.displayWR();
	cout << endl;
	t.displayTreee();
	cout << endl;
	
	return 0;
}