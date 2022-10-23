# include<iostream>
using namespace std;
class hashTable
{
	private:
	__int64 unsigned* verticalArr;
	__int64 unsigned a;
	__int64 unsigned b;
	__int64 unsigned p;
	int count = 0;
	int size;
	public:
	hashTable()
	{
		size = 10;
		p = 18361375334787046697;
		a = (rand() % p) + 1;
		b = rand() % p;
		verticalArr = new __int64 unsigned[size];
		for (int i = 0; i < size; i++)
		{
			verticalArr[i] = 0;
		}
	}
	void insertValue(__int64 unsigned  key)
	{
		int idx = (((a * key) + b) % p) % size;
		if (verticalArr[idx] == 0)                  //placeable
			verticalArr[idx] = key;
		else
		{
			count = 0;
			for (int i = 0; i < size; i++)
			{

			}
			while (verticalArr[idx] != 0)
			{
				a = (rand() % p) + 1;
				b = rand() % p;
				idx = (((a * key) + b) % p) % size;
				count++;
			}
			verticalArr[idx] = key;
			cout << "COLLISIONS: " << count;
		}

	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << verticalArr[i] << "\t";
		}
		cout << endl;
	}
};
int main()
{
	__int64 unsigned a;
	__int64 unsigned b;
	__int64 unsigned p;
	p = 18361375334787046697;
	a = (rand() % p) + 1;
	b = rand() % p;
	int size = 10;
	hashTable h[10];

	__int64 unsigned*myArr = new __int64 unsigned[size];
	srand(time(0));
	cout << "\nRandom numbers::\n";
	for (int i = 0; i < size; i++)
	{
		myArr[i] = rand() % 10000;
		cout << myArr[i] << "\t";
	}

	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		int hashIndex = (((a * myArr[i]) + b) % p) % size;
		cout << "hash index: " << hashIndex << endl;
		h[hashIndex].insertValue(myArr[i]);
		//h[hashIndex].display();
		cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		h[i].display();
		cout << endl;
	}


	return 0;
}